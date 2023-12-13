/*
 * Qp_Bsp.cpp
 *
 *  Created on: Dec 1, 2023
 *      Author: A409296
 */



#include "BSP_QP.hpp"
#include "Signals.hpp"
#include <cstdint>

Q_DEFINE_THIS_FILE

//--------------QSPY global variables---------------------------------------------//
#ifdef Q_SPY

// QSpy source IDs
static QP::QSpyId const l_SysTick_Handler = { 0U };
static QP::QSpyId const l_GPIO_EVEN_IRQHandler = { 0U };
unsigned char QS_Rx_Buffer = 0;

static QP::QSTimeCtr QS_tickTime_;
static QP::QSTimeCtr QS_tickPeriod_;

inline void produceSigDict() {

	QS_SIG_DICTIONARY(APP::TIMEOUT_SIG, nullptr);

}

#endif
//...............................................................................//

extern "C" {


/**
 * @brief QP on error callback
 * @param module
 * @param id
 */
Q_NORETURN Q_onError(char const * const module, int_t const id) {
    // NOTE: this implementation of the assertion handler is intended only
    // for debugging and MUST be changed for deployment of the application
    // (assuming that you ship your production code with assertions enabled).
    Q_UNUSED_PAR(module);
    Q_UNUSED_PAR(id);
    QS_ASSERTION(module, id, 10000U);

#ifndef NDEBUG
    QF_INT_DISABLE();
    //---code---//

    //----------//

    // for debugging, hang on in an endless loop...
    for (;;) {
    }
#endif

    NVIC_SystemReset();
}
//............................................................................
void assert_failed(char const * const module, int_t const id); // prototype
void assert_failed(char const * const module, int_t const id) {
    Q_onError(module, id);
}

// ISRs used in the application ==============================================
/**
 * @brief implementation of the systick handler isr, it used to keep the framework time stamp and events
 */
void SysTick_Handler(void)
{
	// STM32 HAL timebase
	HAL_IncTick();
	//----->QP related Systick operations<------//
	// inform QK about entering an ISR
	QK_ISR_ENTRY();
	// process time events at rate 0
	QP::QTimeEvt::TICK_X(0U, nullptr);
	QK_ARM_ERRATUM_838869();
	// clear CTRL_COUNTFLAG
	std::uint32_t tmp = SysTick->CTRL;
#ifdef QSPY
	// account for the clock rollover
	QS_tickTime_ += QS_tickPeriod_;
#endif
	// inform QK about exiting an ISR
	QK_ISR_EXIT();


}



} // extern "C"


/**
 * @brief initialize QSPY related hardware functions and filters
 */
void QS_Init()
{
#ifdef Q_SPY
	QS_OBJ_DICTIONARY(&l_SysTick_Handler);
	produceSigDict();

    if (QS_INIT(nullptr) == 0U) { // initialize the QS software tracing
        Q_ERROR();
    }
    QS_GLB_FILTER(QP::QS_SM_RECORDS); // state machine records
    QS_GLB_FILTER(QP::QS_AO_RECORDS); // active object records
    QS_GLB_FILTER(QP::QS_UA_RECORDS); // all user records

    HAL_UART_Receive_IT(QS_uart_p, &QS_Rx_Buffer, 1); // start receive
#endif
}

/**
 * @brief prosecution of the uart rx interrupt addressed to qspy incoming communications
 */
void handleQSRxCallback(){
#ifdef Q_SPY
    QP::QS::rxPut(QS_Rx_Buffer);

    HAL_UART_Receive_IT(QS_uart_p, &QS_Rx_Buffer, 1);

    QK_ARM_ERRATUM_838869();
#endif
}


namespace QP {


/**
 * @brief QP callback called by the QP framework on its startup
 */
void QF::onStartup() {
    // set up the SysTick timer to fire at BSP_TICKS_PER_SEC rate
    SysTick_Config(SystemCoreClock / BSP::TICKS_PER_SEC);

    // assing all priority bits for preemption-prio. and none to sub-prio.
    NVIC_SetPriorityGrouping(0U);

    // set priorities of ALL ISRs used in the system, see NOTE00
    NVIC_SetPriority(SysTick_IRQn,  QF_AWARE_ISR_CMSIS_PRI);
    // ...

}
//............................................................................
/**
 * @brief QP callback called by the QP framework on its shut down
 */
void QF::onCleanup() {
}
//............................................................................
/**
 * @brief QP callback called by the QP framework when no AO is active
 * it is mainly used to deliver QSPY traces and to collect incoming qspy commands
 */
void QK::onIdle() {

    // toggle LED2 on and then off, see NOTE01
#ifdef Q_SPY
	QF_INT_DISABLE();
	// parse all the received bytes
    QS::rxParse();
    QF_INT_ENABLE();
    QF_CRIT_EXIT_NOP();
    uint16_t b = 0;
    uint8_t dataBuffer[4000] = {0};
    uint16_t index = 0;
    QF_INT_DISABLE();
    while(HAL_UART_GetState(QS_uart_p))
	{

	}
    while ((b = QS::getByte()) != QS_EOD) { // while not End-Of-Data...
        QF_INT_ENABLE();
        dataBuffer[index] = b;
        index++;
        QF_INT_DISABLE();
    }
    QF_INT_ENABLE();
    HAL_UART_Transmit(QS_uart_p, dataBuffer, index, 100);
#elif defined NDEBUG
    // Put the CPU and peripherals to the low-power mode.
    // you might need to customize the clock management for your application,
    // see the datasheet for your particular Cortex-M3 MCU.
    //
    // !!!CAUTION!!!
    // The WFI instruction stops the CPU clock, which unfortunately disables
    // the JTAG port, so the ST-Link debugger can no longer connect to the
    // board. For that reason, the call to __WFI() has to be used with CAUTION.
    //
    // NOTE: If you find your board "frozen" like this, strap BOOT0 to VDD and
    // reset the board, then connect with ST-Link Utilities and erase the part.
    // The trick with BOOT(0) is it gets the part to run the System Loader
    // instead of your broken code. When done disconnect BOOT0, and start over.
    //
    //__WFI();   Wait-For-Interrupt
#endif


#ifdef NDEBUG
    // Put the CPU and peripherals to the low-power mode.
    // you might need to customize the clock management for your application,
    // see the datasheet for your particular Cortex-M MCU.
    //
    __WFI(); // Wait-For-Interrupt
#endif
}

//============================================================================
// QS callbacks...
#ifdef Q_SPY
namespace QS {

//............................................................................
/**
 * @brief Qspy callback called by the framework upon qpsy initialization
 * @param arg
 * @return
 */
bool onStartup(void const *arg) {
    static uint8_t qsBuf[2*1024]; // buffer for Quantum Spy
    static uint8_t qsRxBuf[128];  /* buffer for QS-RX channel */

    initBuf(qsBuf, sizeof(qsBuf));
    rxInitBuf(qsRxBuf, sizeof(qsRxBuf));



    QS_tickPeriod_ = SystemCoreClock / BSP::TICKS_PER_SEC;
    QS_tickTime_ = QS_tickPeriod_; // to start the timestamp at zero

    return true; // return success
}
//............................................................................
/**
 * @brief QP framework callback called when qspy is de initialized
 */
void onCleanup() {
}
//............................................................................
/**
 * @brief QP callback to update the qspy timestamp
 * @return time value
 */
QSTimeCtr onGetTime() { // NOTE: invoked with interrupts DISABLED
    if ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == 0) { // not set?
        return QS_tickTime_ - static_cast<QSTimeCtr>(SysTick->VAL);
    }
    else { // the rollover occured, but the SysTick_ISR did not run yet
        return QS_tickTime_ + QS_tickPeriod_
               - static_cast<QSTimeCtr>(SysTick->VAL);
    }
}
//............................................................................
/**
 * @brief used to dump the collected traces to the host at once
 */
void onFlush()
{
    uint16_t b = 0;
    uint8_t dataBuffer[4000] = {0};
    uint16_t index = 0;
    QF_INT_DISABLE();
    //
    while ((b = getByte()) != QS_EOD) { // while not End-Of-Data...

        dataBuffer[index] = b;
        index++;
    }
    HAL_UART_Transmit(QS_uart_p, dataBuffer, index, 100);
    //
    QF_INT_ENABLE();

}
//............................................................................
/**
 * @brief callback function to reset the target (to be implemented in the BSP)
 */
void onReset() {
    NVIC_SystemReset();
}
//............................................................................
/**
 * @brief callback to process custom QSPY input commands
 * @param cmdId
 * @param param1
 * @param param2
 * @param param3
 */
void onCommand(std::uint8_t cmdId, std::uint32_t param1,
               std::uint32_t param2, std::uint32_t param3)
{
    Q_UNUSED_PAR(cmdId);
    Q_UNUSED_PAR(param1);
    Q_UNUSED_PAR(param2);
    Q_UNUSED_PAR(param3);
}

} // namespace QS
#endif // Q_SPY


} // namespace QP
