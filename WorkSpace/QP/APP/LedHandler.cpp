/*
 * LedHandler.cpp
 *
 *  Created on: Dec 11, 2023
 *      Author: A409296
 */

#include "LedHandler.hpp"

namespace APP {

LedHandler::LedHandler(LedHandlerInit_t& _init) {
	// TODO Auto-generated constructor stub
	init = _init;

}

void LedHandler::LedControl(Colors_t color, uint8_t val) {
	switch(color)
	{
	case Colors_t::Green:
		init.gpioGreen->Write(val);
		break;

	case Colors_t::Red:
		init.gpioRed->Write(val);
		break;
	}
}

} /* namespace APP */
