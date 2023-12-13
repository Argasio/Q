/*
 * MCALGpio.cpp
 *
 *  Created on: Dec 11, 2023
 *      Author: A409296
 */

#include <MCAL_Gpio.h>

namespace MCAL {

Gpio::Gpio(const GpioInit_t& _init): init(_init) {
	// TODO Auto-generated constructor stub

}

void Gpio::Write(std::uint8_t val)
{
	HAL_GPIO_WritePin(init.port, init.pin, (GPIO_PinState)val);
}

std::uint8_t Gpio::Read()
{
	return HAL_GPIO_ReadPin(init.port, init.pin);
}

} /* namespace APP */
