/*
 * LedHandler.hpp
 *
 *  Created on: Dec 11, 2023
 *      Author: A409296
 */

#ifndef LEDHANDLER_HPP_
#define LEDHANDLER_HPP_
#include <cstdint>
#include <stm32h5xx_hal.h>
#include "MCAL_iGpio.hpp"
namespace APP {

typedef struct LedHandlerInit_t
{
	MCAL::iGpio* gpioRed;
	MCAL::iGpio* gpioGreen;

}LedHandlerInit_t;
class LedHandler {
public:
	enum Colors_t
	{
		Red,
		Green
	};
	LedHandler(LedHandlerInit_t& _init);
	void LedControl(Colors_t color, uint8_t val);
private:
	LedHandlerInit_t init;
};

} /* namespace APP */

#endif /* LEDHANDLER_HPP_ */
