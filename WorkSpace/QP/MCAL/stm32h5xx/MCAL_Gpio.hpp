/*
 * MCALGpio.h
 *
 *  Created on: Dec 11, 2023
 *      Author: A409296
 */

#ifndef STM32H5XX_MCAL_GPIO_HPP_
#define STM32H5XX_MCAL_GPIO_HPP_
#include "MCAL_iGpio.hpp"
#include "stm32h5xx.h"
namespace MCAL {
typedef struct
{
	std::uint32_t pin;
	GPIO_TypeDef* port;
}GpioInit_t;

class Gpio:public iGpio {
public:
				 Gpio(const GpioInit_t& _init);
	void 		 Write(std::uint8_t val) override;
	std::uint8_t Read() 				 override;
private:
	GpioInit_t init;
};

} /* namespace APP */

#endif /* STM32H5XX_MCAL_GPIO_HPP_ */
