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
	APP::LedHandler* ledHandler = AppGetLedHandler( );
	ButtonBlinkInit_t buttonBlinkInit;
	buttonBlinkInit.ledHandler = ledHandler;
	static ButtonBlink AO_buttonBlink(buttonBlinkInit);
	return &AO_buttonBlink;
}

ButtonPressHandler* AO_GetButtonPressHandler()
{

	ButtonPressHandlerInit_t init;
	init.pin = MCalGetGpio(Gpios::Btn_Usr);
	static ButtonPressHandler AO_buttonPressHandler(init);
	return &AO_buttonPressHandler;
}
