/*
 * BSP_AoFactory.cpp
 *
 *  Created on: Dec 13, 2023
 *      Author: A409296
 */

#include "BSP_HandlerFactory.hpp"
#include "BSP_AoFactory.hpp"
#include "BSP_McalFactory.hpp"

using namespace AO;
//--------------- AO FACTORY ------------------//
Blinker* AO_GetBlinker()
{
	static Blinker* aoPtr = nullptr;
	if(aoPtr == nullptr)
	{
		APP::LedHandler* ledHandler = AppGetLedHandler( );
		BlinkerInit_t BlinkerInit;
		BlinkerInit.ledHandler = ledHandler;
		static Blinker AO_Blinker(BlinkerInit);
		aoPtr = &AO_Blinker;
	}
	return aoPtr;
}

ButtonPressHandler* AO_GetButtonPressHandler()
{
	static ButtonPressHandler* aoPtr = nullptr;
	if(aoPtr == nullptr)
	{
		ButtonPressHandlerInit_t init;
		init.pin = MCalGetGpio(Gpios::Btn_Usr);
		static ButtonPressHandler AO_buttonPressHandler(init);
		aoPtr = &AO_buttonPressHandler;
	}
	return aoPtr;
}
