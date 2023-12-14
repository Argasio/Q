/** @file UTILS_tracer.h
*
* @brief public header of  tracing via uart to be used to log events throughout the program
*	to be used in debugging mode
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
  
#ifndef UTILS_TRACER_H_
#define UTILS_TRACER_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdint.h>
#include <stdbool.h>
#include <BSP_ConditionalCompile.h>

#if COMPILE_MODULE_TRACER

#define   TRACER_UARTOUTPUTMETHOD_UNDEFINED (0) ///< default uart transmission invalid option
#define   TRACER_UARTOUTPUTMETHOD_BLOCKING  (1) ///< default uart transmission blocking
#define   TRACER_UARTOUTPUTMETHOD_IRQ       (2) ///< default uart transmission interrupt based
#define   TRACER_UARTOUTPUTMETHOD_DMA       (3) ///< default uart transmission dma-interrupt based


///@brief maximum trace bytes
#ifndef TRACER_MAX_BUFFER_SIZE
#	define TRACER_MAX_BUFFER_SIZE 85
#endif

#ifndef TRACER_QUEUE_MSG_NUM
#	define TRACER_QUEUE_MSG_NUM 50 //< how many messages can be buffered for the tracer allocating statically the necessary memory
#endif

#ifndef TRACER_UART_OUTPUT_METHOD
#	define TRACER_UART_OUTPUT_METHOD (TRACER_UARTOUTPUTMETHOD_DMA) ///< what kind of uart transmission to use
#endif

#ifndef TRACER_USE_RTOS
#	define TRACER_USE_RTOS 0
#endif
///@brief trace message structure
typedef struct TracerMsg_t
{
    uint8_t buffer[TRACER_MAX_BUFFER_SIZE]; ///< formatted buffer
    uint8_t len;/// length field, (used by the module)
}TracerMsg_t;
///@brief trace main task function
void vTracerTask(void *argument);
///@brief trace basic print function with a timestamp added
uint32_t TracerPrint(const char * format, ...);
///@brief trace basic print function, not timestamp added
uint32_t TracerPrintNoTs(const char * format,...);
///@brief trace basic print function, with a label added
uint32_t TracerPrintWithLabel(const char * label, const char * format,...);
///@brief this function flushes the tracer pending traces and outputs them directly, to be used by asserts or hardfaults
void TracerDump();
///@brief uart interrupt callback used by the trace uart
void TRACER_UartTxClptCallback();
///@brief weak implementation of wait for task start function
void    TRACER_waitForStart(void);



#endif // compile barrier

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif

/**
  * @} // UTILS
  */
