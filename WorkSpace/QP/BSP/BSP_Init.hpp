/*
 * BSP_Init.hpp
 *
 *  Created on: Dec 11, 2023
 *      Author: A409296
 */

#ifndef BSP_INIT_HPP_
#define BSP_INIT_HPP_
#include "MCAL_Gpio.h"
#include "BSP_Peripheral_Handles.h"
#include "LedHandler.hpp"
#include "qpcpp.hpp"        // QP/C++ real-time embedded framework
enum Gpios
{
	Led_Red,
	Led_Green,
};

namespace APP
{
enum Signals :QP::QSignal
{
    DUMMY_SIG = QP::Q_USER_SIG,



    MAX_PUB_SIG,  // the last published signal

	TIMEOUT_SIG,
    MAX_SIG       // the last signal
};

}


MCAL::iGpio*     MCalGetGpio(Gpios gpio);
APP::LedHandler* AppGetLedHandler();



#endif /* BSP_INIT_HPP_ */
