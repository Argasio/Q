/*
 * BSP_AoFactory.cpp
 *
 *  Created on: Dec 13, 2023
 *      Author: A409296
 */

#include "BSP_HandlerFactory.hpp"
#include "BSP_AoFactory.hpp"
#include "BSP_McalFactory.hpp"

//--------------- AO FACTORY ------------------//
ButtonBlink* AO_GetButtonBlink()
{
	static ButtonBlink* aoPtr = nullptr;
	if(aoPtr == nullptr)
	{
		APP::LedHandler* ledHandler = AppGetLedHandler( );
		ButtonBlinkInit_t buttonBlinkInit;
		buttonBlinkInit.ledHandler = ledHandler;
		static ButtonBlink AO_buttonBlink(buttonBlinkInit);
		aoPtr = &AO_buttonBlink;
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
