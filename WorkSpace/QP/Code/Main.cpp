/*
 * Main.cpp
 *
 *  Created on: Nov 30, 2023
 *      Author: A409296
 */
#include "BSP_AoFactory.hpp"
#include "BSP_QP.hpp"
#include "Main.hpp"





void AO_InitPublishSubscribe()
{
    /*
    This data type represents a set of active objects that subscribe to a given signal.
    The set is represented as a priority-set, where each bit corresponds to the unique priority of an active object.
    */
    static QP::QSubscrList subscrSto[APP::Signals::MAX_PUB_SIG];

	// init publish-subscribe
    QP::QF::psInit(subscrSto, Q_DIM(subscrSto));
}

void AO_ButtonBlinkStart()
{
	ButtonBlink* AO_buttonBlink = AO_GetButtonBlink();
	/*
	A fixed block-size memory pool is a very fast and efficient data structure for dynamic allocation of fixed block-size chunks of memory.
	A memory pool offers fast and deterministic allocation and recycling of memory blocks and is not subject to fragmenation.
	The QMPool class describes the native QF memory pool, which can be used as the event pool for dynamic event allocation,
	or as a fast, deterministic fixed block-size heap for any other objects in your application.
	*/
    static QF_MPOOL_EL(QP::QEvt) smlPoolSto[20u];
    // event queue buffer for buttonBlink AO
    static QP::QEvt const *fsm_queueStoLed[10];

	/*
	Event pool initialization for dynamic allocation of events.
	Description
	This function initializes one event pool at a time and must be called exactly once for each event pool before the pool can be used.
	*/
	QP::QF::poolInit(smlPoolSto,
					 sizeof(smlPoolSto), sizeof(smlPoolSto[0]));
	// start the Blinky active object

	AO_buttonBlink->start(AO_LED_PRIO, // priority of the active object
		fsm_queueStoLed, // event queue buffer
		Q_DIM(fsm_queueStoLed), // the length of the buffer
		nullptr,
		0U);  // private stack (not used on the desktop)


}

void start() {


	// initialize the framework
	QP::QF::init();
	// init qspy
	QS_Init();
	// init publish subscribe mechanism
	AO_InitPublishSubscribe();
    // init active objects and memory pools
	AO_ButtonBlinkStart();
    // let the framework run the application
	QP::QF::run();


}

void MainCpp()
{

	start();
    QP::QF::run();   // run the QF application
}


