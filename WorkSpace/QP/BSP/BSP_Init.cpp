/*
 * BSP_Init.cpp
 *
 *  Created on: Dec 11, 2023
 *      Author: A409296
 */
#include "BSP_Init.hpp"


MCAL::iGpio* MCalGetGpio(Gpios gpio)
{
	MCAL::iGpio* ret = nullptr;
	MCAL::GpioInit_t init;
	switch(gpio)
	{
		case Led_Red:
		{

			init.port = LED3_RED_GPIO_Port;
			init.pin = LED3_RED_Pin;

			static MCAL::Gpio red(init);
			ret = &red;
			break;
		}
		case Led_Green:
		{
			init.port = LED1_GREEN_GPIO_Port;
			init.pin = LED1_GREEN_Pin;

			static MCAL::Gpio green(init);
			ret = &green;

			break;
		}
	}
	return ret;
}

APP::LedHandler* AppGetLedHandler( )
{
	APP::LedHandlerInit_t init;
	init.gpioGreen = MCalGetGpio(Led_Green);
	init.gpioRed   = MCalGetGpio(Led_Red);
	static APP::LedHandler handler(init);
	return &handler;

}
