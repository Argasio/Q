/*
 * BSP_AoFactory.cpp
 *
 *  Created on: Dec 13, 2023
 *      Author: A409296
 */

#include "BSP_HandlerFactory.hpp"
#include "BSP_AoFactory.hpp"

//--------------- AO FACTORY ------------------//
ButtonBlink* AO_GetButtonBlink()
{
	APP::LedHandler* ledHandler = AppGetLedHandler( );
	ButtonBlinkInit_t buttonBlinkInit;
	buttonBlinkInit.ledHandler = ledHandler;
	static ButtonBlink AO_buttonBlink(buttonBlinkInit);
	return &AO_buttonBlink;
}
