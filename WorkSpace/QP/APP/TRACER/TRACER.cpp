/** @file UTILS_unit_testing.h
*
* @brief
*
* @details
* @author Matteo Vittorio Ricciutelli
* @date   2023/03/28
*
* @copyright Copyright (c) 2023 Gridspertise s.r.l.
*            All rights reserved.
*/

/** @addtogroup TRACER
  * @brief Additional files shared with all modules
  * @{
  */

#include "TRACER.h"
#include <BSP_ConditionalCompile.h>
#if COMPILE_MODULE_TRACER
#include "string.h"
#include "stdio.h"
#include "stdarg.h"



#ifdef USE_TRACELYZER
#if USE_TRACELYZER==1
#include "trcRecorder.h"
#endif
#endif

/* -----------Module Private Defines---------------*/
#define TRACER_MODULE_INITIALIZED 1
#define TRACER_USE_SWO 1
#define TRACER_USE_UART 0
#define TRACER_MAX_BLOCKING_TIMEOUT 500
#define TRACER_DUMP_INACTIVE 0
#define TRACER_DUMP_ONGOING 1
#define TRACER_DUMP_EXECUTED 2
#if TRACER_OUTPUT_CHANNEL_USART // this define must be imported from the _Required.h file
#define TRACER_OUTPUT_CHANNEL TRACER_USE_UART
#elif TRACER_OUTPUT_CHANNEL_SWO // this define must be imported from the _Required.h file if TRACER_OUTPUT_CHANNEL_USART is 0
#define TRACER_OUTPUT_CHANNEL TRACER_USE_SWO
#endif

/* -----------Module Private Global variables---------------*/
#if (TRACER_USE_RTOS==1)
///@brief rtos queue to relay messages to the trace buffer
static osMessageQueueId_t TRACER_tracerQueue;
///@brief semaphore to handle hardware (uart) access
static osSemaphoreId_t TRACER_traceSemaphore;
#endif
///@brief how many bytes are being sent
volatile uint32_t TRACER_currentTransferSize = 0;
static uint8_t TRACER_totalTraceBuffer[TRACER_QUEUE_MSG_NUM*TRACER_MAX_BUFFER_SIZE];
static volatile uint8_t dumpFlag = TRACER_DUMP_INACTIVE;

/* -----------Module Functions---------------*/
/**
 * @brief this function replaces the putchat function used by printf and redirects it to the trace hardware
 */
#if TRACER_OUTPUT_CHANNEL == TRACER_USE_SWO
extern "C"{
int __io_putchar(int ch)
{
    // Write character to ITM ch.0
    ITM_SendChar(ch);
    return(ch);
}

int _write(int file, char *data, int len)
{
   for(int i = 0; i< len; i++)
   {
	   __io_putchar(data[i]);
   }

   // return # of bytes written - as best we can tell
   return len;
}
}


#endif
/**
*@brief uart interrupt callback, use it to manage access to the peripheral using a flag and a sempahore
*/
void TRACER_UartTxClptCallback()
{

    // reset counter, this also communicates that uart is free
    TRACER_currentTransferSize = 0;
#if (TRACER_USE_RTOS==1)
    // release semaphore
    osStatus_t osResult = osSemaphoreRelease(TRACER_traceSemaphore);

    if(osResult != osOK)
    {
        // do nothing
        (void)osResult;// suppress unused warning
    }
#endif

}


#if TERM_TIMESTAMP
/**
  * @brief This function inserts the timestamp in format [HH:MM:SS.mmm] in a destination string.
  * @param buffer_dst Destination buffer for the string.
  * @param buffer_dst_size Destination buffer size.
  * @retval number of bytes added to the buffer_dst.
  */
static uint32_t TracerInsertTimestamp(char* buffer_dst, uint32_t buffer_dst_size)
{
    uint8_t buffer_src[16];
    uint32_t cur_timestamp;
    uint32_t millisecs, seconds, minutes, hours;
    // get milliseconds from HAL
    cur_timestamp = HAL_GetTick();
    // time is expressed in ms
    millisecs = cur_timestamp % 1000U;
    // now seconds holds the timetamp in seconds
    seconds = cur_timestamp / 1000U;
    // now minutes holds the timestamp in minutes
    minutes = seconds / 60U;
    // now seconds holds the "seconds" field in the hourly timestamp
    seconds %= 60U;
    // now hours holds the timestamp expressed in hours
    hours = minutes / 60U;
    // now minutes holds the "minutes" portion of the hourly timestamp
    minutes %= 60U;


    uint32_t bytes_written = sprintf((char*) buffer_src, "%.3lu.%.2lu.%.2lu.%.3lu: ", (unsigned long)hours, (unsigned long)minutes, (unsigned long)seconds, (unsigned long)millisecs);
    strncat((char*) buffer_dst, (char*) buffer_src, buffer_dst_size - strlen((char*) buffer_dst));
    return bytes_written;
}
#endif

#if (TRACER_USE_RTOS==1)
/**
 * @brief Interrogates the queue for the presence of traces to be transferred to the buffers
 * @note it sets TRACER_currentTransferSize
 * @return number of traces
 */
uint32_t TRACER_FromQueueToBuffer()
{
    uint32_t foundTraces = 0;
    TracerMsg_t traceMsg;
    // is there any trace in queue?
    osStatus_t status = osMessageQueueGet(TRACER_tracerQueue, &traceMsg, 0, osWaitForever);
    // concatenate any trace in a single string inside TRACER_totalTraceBuffer
    do
    {
        if((status == osOK))
        {
            foundTraces++;
            memcpy(&TRACER_totalTraceBuffer[TRACER_currentTransferSize],traceMsg.buffer, traceMsg.len);
            TRACER_currentTransferSize+=traceMsg.len;
        }
        // interrogate the queue again for further messages
        status = osMessageQueueGet(TRACER_tracerQueue, &traceMsg, 0, 0);
    }
    while(status == osOK);
    return foundTraces;
}
#endif

/**
 * @brief outputs the trace buffer content to uart using TRACER_currentTransferSize as n of bytes
 * @param blocking use blacking api or interrupt-based
 * @return 1 success, 0 = failure
 */
bool TRACER_PrintBufferUart( bool blocking)
{

    HAL_StatusTypeDef result = HAL_OK;

    if(TRACER_totalTraceBuffer[TRACER_currentTransferSize-1] != '\n')
    {
        TRACER_totalTraceBuffer[TRACER_currentTransferSize-1] = '\n';
    }

    // initiate transmission in blocking or non-blocking mode
    if(blocking)
    {
        result = HAL_UART_Transmit(&huartTrace, TRACER_totalTraceBuffer, TRACER_currentTransferSize ,TRACER_MAX_BLOCKING_TIMEOUT );
        // blocking call over, uart is free
        TRACER_currentTransferSize = 0;
    }
    else
    {
#if    TRACER_UART_OUTPUT_METHOD == TRACER_UARTOUTPUTMETHOD_DMA
        result = HAL_UART_Transmit_DMA(&huartTrace, TRACER_totalTraceBuffer, TRACER_currentTransferSize);
#elif  TRACER_UART_OUTPUT_METHOD == TRACER_UARTOUTPUTMETHOD_BLOCKING
        result = HAL_UART_Transmit(&huartTrace, TRACER_totalTraceBuffer, TRACER_currentTransferSize, TRACER_MAX_BLOCKING_TIMEOUT);
#elif  TRACER_UART_OUTPUT_METHOD == TRACER_UARTOUTPUTMETHOD_IRQ
        result = HAL_UART_Transmit_IT(&huartTrace, TRACER_totalTraceBuffer, TRACER_currentTransferSize);
#endif
    }

    if(HAL_OK == result)
    {
        // nothing to do
    }
    else // bad send
    {
        // uart not engaged (failed or busy), uart not busy then
        TRACER_currentTransferSize = 0;
        return false;
    }

    return true;

}

/**
 * @brief prints the content of the buffer using the swo channel
 * it prints TRACER_currentTransferSize bytes and then resets the variable to 0
 */
void TRACER_PrintBufferSwo()
{
    TRACER_totalTraceBuffer[TRACER_currentTransferSize] = 0; // terminate trace string with a 0
    // print trace via swo
    printf("%s",TRACER_totalTraceBuffer);
    // print ended, signal swo free
    TRACER_currentTransferSize = 0;
}
#if (TRACER_USE_RTOS==1)
/**
*@brief main body of the tracer task, the first time it runs it initializes the global variables,
* when it runs, it seeks for trace messages in the queue
* then it waits for the uart to be freed and finally initiates a uart transaction
*/
void vTracerTask(void *argument)
{

    TRACER_tracerQueue = RTOS_GetQueueID(TRACER_QUEUE_ID);
    TRACER_traceSemaphore = RTOS_GetSemaphoreID(TRACER_SM_SEM_ID);
    osStatus_t osResult;

    TRACER_waitForStart();
    // empty the semaphore tokens
    do
    {
        osResult = osSemaphoreAcquire(TRACER_traceSemaphore, 0);
    } while (osResult != osErrorResource);
    // abort any ongoing tx processes
    if (TRACER_OUTPUT_CHANNEL == TRACER_USE_UART)
    {
        while (TRACER_currentTransferSize != 0)
        {
            ; // wait for any trace executed before the task to be completed
        }

    }
    // allow 1 token to be spent
    osResult = osSemaphoreRelease(TRACER_traceSemaphore);
    // task loop
    while (1)
    {

        uint32_t foundTraces = 0;
        // reset current transfer size value
        TRACER_currentTransferSize = 0;
        // is the uart free from sending any previous trace?
        if (TRACER_OUTPUT_CHANNEL == TRACER_USE_UART)
        {
            osResult = osSemaphoreAcquire(TRACER_traceSemaphore, osWaitForever);
        }
        if (osResult == osOK || TRACER_OUTPUT_CHANNEL == TRACER_USE_SWO)
        {
            // get the number of traces and bytes to send
            foundTraces = TRACER_FromQueueToBuffer();
            // deliver traces
            if (foundTraces > 0)
            {
                bool txSuccess = true;
                if (TRACER_OUTPUT_CHANNEL == TRACER_USE_UART)
                {
                    txSuccess = TRACER_PrintBufferUart(false);
                    if (!txSuccess)
                    {
                        // error
                    }
                }
                else
                {
                    TRACER_PrintBufferSwo();
                }

            }
        }
    }
}
#endif
/**
 * @brief dumps all traces in blocking mode bypassing the task
 * this is to be called in case of an hardfault or an assert in isr context
 */
void TracerDump()
{
#if (TRACER_USE_RTOS==1)
    const uint8_t reprintMsg[] = "TRACER:    !printing last buffer, might reprint some stuff!\n";
    const uint8_t endDumpMsg[] = "TRACER:--------END OF DUMP\n";
    const uint8_t startDumpMsg[] = "TRACER:--------START OF DUMP\n";
    if( TRACER_DUMP_EXECUTED == dumpFlag)
    {
        return; // dump was already completed no need to repeat
    }
    else
    {
        dumpFlag = TRACER_DUMP_ONGOING; // we are dumping
    }
    /*Beginning of deump, according to the output channel print the beginning msg and any residual prints*/
    if(TRACER_OUTPUT_CHANNEL == TRACER_USE_SWO)
    {
        printf("%s", startDumpMsg);
        if (TRACER_currentTransferSize > 0) // a print via swo was ongoing, restart it from the beginning
        {
            // notify we reprint stuff
            printf("%s", reprintMsg);
            // reprint previous buffer
            TRACER_PrintBufferSwo();
        }
    }
    else
    {
        // stop any ongoing uart transaction
        HAL_UART_Abort_IT(&huartTrace);
        // notify we are starting the dump
        HAL_UART_Transmit(&huartTrace, startDumpMsg, sizeof(startDumpMsg), TRACER_MAX_BLOCKING_TIMEOUT);
        if (TRACER_currentTransferSize > 0)
        {
            // notify we are reprinting stuff
            HAL_UART_Transmit(&huartTrace, reprintMsg, sizeof(reprintMsg), TRACER_MAX_BLOCKING_TIMEOUT);
            // reprint last buffer in blocking mode
            TRACER_PrintBufferUart( true);
        }

    }

    // new transfer, reset counter
    TRACER_currentTransferSize = 0;
    // check for traces in queue
    uint32_t foundTraces = TRACER_FromQueueToBuffer();
    // if there are traces use the uart channel in blocking mode or the swo
    if (foundTraces > 0)
    {
        bool txSuccess = true;
        if (TRACER_OUTPUT_CHANNEL == TRACER_USE_UART)
        {
            txSuccess = TRACER_PrintBufferUart( true);
            if (!txSuccess)
            {
                // error
            }

        }
        else
        {
            TRACER_PrintBufferSwo();

        }
    }

    // notify we are ending the dump
    if (TRACER_OUTPUT_CHANNEL == TRACER_USE_UART)
    {
        HAL_UART_Transmit(&huartTrace, endDumpMsg, sizeof(endDumpMsg), TRACER_MAX_BLOCKING_TIMEOUT);
    }
    else
    {
        printf("%s", endDumpMsg);
    }
    // dump finished, no more dumping possible
    dumpFlag = TRACER_DUMP_EXECUTED;
#endif
}

/**
*@brief request the print of a trace that can be enriched with a label or a timestamp
* if the tracer task is not initialized it uses the uart in blocking mode
* otherwise it will dispatch a queue message to be used by the task for later printing
*@param label
*@param timeStampEnable use time stamp?
*@param format options
*@return how many bytes were sent to be transmitted
*/
uint32_t TracerPrintGeneral(int32_t labelIndex, bool timeStampEnable,  const char * format,va_list args)
{
    TracerMsg_t traceMsg = {{0},0};
    // do we need a timestamp?
#if TERM_TIMESTAMP
    if( timeStampEnable)
    {
        // first item is time stamp
    	traceMsg.len += TracerInsertTimestamp((char*) &traceMsg.buffer[0], sizeof(traceMsg.buffer));
    }
#endif

#if TRACER_USE_QSPY == 0
    char* label = &TRACER_LABEL_TABLE[labelIndex][0];
    // is there a label to print before the trace?
    if(label >=0){
        strncat((char*) &traceMsg.buffer[traceMsg.len], label, sizeof(traceMsg.buffer));
        traceMsg.len += strlen(label);
        traceMsg.buffer[traceMsg.len] = ' ';
        traceMsg.len++;
    }
#endif
    // format the string
    va_list args_2;
    va_copy(args_2, args);
    int printedChars = vsnprintf((char*) &traceMsg.buffer[traceMsg.len],
                                    sizeof(traceMsg.buffer) - traceMsg.len, (const char*) format,
                                    args_2);

#if USE_TRACELYZER==1
    traceResult res;
    if(traceMsg.len>TRC_MAX_BLOB_SIZE)
    {
    	res = xTracePrintF(label, "!!!Too Long - Truncated!!!");
    }
    else
    {
    	res = xTraceVPrintF(label, format, &args_2);

    }
    if(res == TRC_FAIL)
    {
    	asm("NOP");
    }

#elif USE_SYSTEMVIEW
    SEGGER_SYSVIEW_VPrintfTargetEx(format, 0 , &args_2);
#elif TRACER_USE_QSPY
    // Send String using QSPY User level 0 interface layer message
    QS_BEGIN_ID(QS_MODULES_START+labelIndex, 0U)
    QS_STR(reinterpret_cast<const char*>(traceMsg.buffer));
    QS_END()
    if(labelIndex>0
       && (traceMsg.len+ sizeof(TRACER_LABEL_TABLE[0]))<sizeof(traceMsg.buffer))
    {

    	char* lbl = &TRACER_LABEL_TABLE[labelIndex][0];
    	uint32_t lblLen = strlen(lbl);
    	if(lblLen>0){
    		memmove(&traceMsg.buffer[lblLen+1],traceMsg.buffer, printedChars );
    		traceMsg.buffer[lblLen] = ' ';
    		memcpy(traceMsg.buffer, lbl, lblLen);
    		traceMsg.len += lblLen+1;
    	}
    }
#endif

    va_end(args_2);
    // update message length
    traceMsg.len += printedChars;

    if (traceMsg.len > sizeof(traceMsg.buffer))
    {
        traceMsg.len = sizeof(traceMsg.buffer);
    }
    else if (traceMsg.len<sizeof(traceMsg.buffer) && traceMsg.buffer[traceMsg.len -1] != '\n')
    {
    	traceMsg.buffer[traceMsg.len] = '\n';
    	traceMsg.len++;
    }
#if (TRACER_USE_RTOS==1)
    // is the module task initialized?
    if (osKernelGetState() == osKernelRunning)
    {

    	// if so place the message in the queue
        osStatus_t result = osMessageQueuePut(TRACER_tracerQueue, &traceMsg, 0, 0);
        if(result != osOK)
        {
            // trace lost
            traceMsg.len = 0;
        }
    }
    // while kernel has not started, only one trace at a time can be printed !!
    else
#endif
        if (0 == TRACER_currentTransferSize)
    {
        // no other prints ongoing
        TRACER_currentTransferSize = traceMsg.len;
        // rtos not initialized for the tracer task, if the uart is free then trigger a transmission
        if (TRACER_OUTPUT_CHANNEL == TRACER_USE_SWO)
        {
        	// if swo traces are blocked
		    setbuf(stdin, NULL);
		    setbuf(stdout, NULL);
            printf("%s", traceMsg.buffer);
            TRACER_currentTransferSize = 0;
        }
        else
        {
            HAL_StatusTypeDef result = HAL_OK;
            memcpy(TRACER_totalTraceBuffer, &traceMsg.buffer, TRACER_currentTransferSize);
#if    TRACER_UART_OUTPUT_METHOD == TRACER_UARTOUTPUTMETHOD_DMA
            result = HAL_UART_Transmit_DMA(&huartTrace, TRACER_totalTraceBuffer, TRACER_currentTransferSize);
#elif  TRACER_UART_OUTPUT_METHOD == TRACER_UARTOUTPUTMETHOD_BLOCKING
            result = HAL_UART_Transmit(&huartTrace, TRACER_totalTraceBuffer, TRACER_currentTransferSize, TRACER_MAX_BLOCKING_TIMEOUT);
#elif  TRACER_UART_OUTPUT_METHOD == TRACER_UARTOUTPUTMETHOD_IRQ
            result = HAL_UART_Transmit_IT(&huartTrace, TRACER_totalTraceBuffer, TRACER_currentTransferSize);
#endif
            if(result != HAL_OK)
            {
                traceMsg.len = 0;
                // bad transfer, reset counter
                TRACER_currentTransferSize = 0;
            }
    	}

    }
    else
    {
    	traceMsg.len = 0;
    }

    return traceMsg.len;
}

/**
*@brief request the print of a trace that uses timestamp, this is a wrapper to @TracerPrintGeneral
*@param format options
*/
uint32_t TracerPrint(const char * format, ...)
{
    va_list args;
    va_start(args,format);
    uint32_t lengthPrinted = TracerPrintGeneral(-1, true, format, args);
    va_end(args);
    return lengthPrinted;
}

/**
*@brief request the print of a trace with no timestamp, this is a wrapper to @TracerPrintGeneral
*@param format options
*/
uint32_t TracerPrintNoTs(const char * format,...)
{
    va_list args;
    va_start(args,format);
    uint32_t lengthPrinted = TracerPrintGeneral(-1, false, format, args);
    va_end(args);
    return lengthPrinted;
}

/**
*@brief request the print of a trace with a label, this is a wrapper to @TracerPrintGeneral
*@param label
*@param format options
*/
uint32_t TracerPrintWithLabel(int32_t labelIndex, const char * format,...)
{
    va_list args;
    va_start(args,format);
    uint32_t lengthPrinted = TracerPrintGeneral(labelIndex, true, format, args);
    va_end(args);
    return lengthPrinted;
}
#endif

///@brief weak implementation of wait for task start function
__attribute__((weak)) void    TRACER_waitForStart(void){;}

/**
  * @} // UTILS
  */
