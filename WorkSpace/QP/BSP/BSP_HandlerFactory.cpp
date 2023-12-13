/*
 * BSP_Init.cpp
 *
 *  Created on: Dec 11, 2023
 *      Author: A409296
 */
#include <BSP_HandlerFactory.hpp>
#include "BSP_McalFactory.hpp"

//--------------- Handler FACTORY -------------//
APP::LedHandler* AppGetLedHandler( )
{
	APP::LedHandlerInit_t init;
	init.gpioGreen = MCalGetGpio(Led_Green);
	init.gpioRed   = MCalGetGpio(Led_Red);
	static APP::LedHandler handler(init);
	return &handler;

}


