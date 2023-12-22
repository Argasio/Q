/*
 * AO_Callbacks.cpp
 *
 *  Created on: Dec 22, 2023
 *      Author: A409296
 */

#include "AO_ButtonpressHandler.hpp"
#include "AO_ButtonBlink.hpp"
#include "Signals.hpp"
#include "Modules.h"
#include "BSP_AoFactory.hpp"

void AO_ButtonPressHandlerCallback(AO_ButtonPressHandlerEvt_t evt, QP::QActive* caller)
{
	if(LongPress == evt)
	{
		AO_GetButtonBlink()->ChangeMode(APP::LedHandler::Red, caller);
	}
	else if(ShortPress == evt)
	{
		AO_GetButtonBlink()->ChangeMode(APP::LedHandler::Green, caller);
	}
}


