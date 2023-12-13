/*
 * MCALGpio.h
 *
 *  Created on: Dec 11, 2023
 *      Author: A409296
 */

#ifndef STM32H5XX_MCAL_IGPIO_H_
#define STM32H5XX_MCAL_IGPIO_H_
#include <cstdint>
namespace MCAL {

class iGpio{
public:
	virtual void Write(std::uint8_t val) = 0;
	virtual std::uint8_t Read() = 0;
};

} /* namespace APP */

#endif /* STM32H5XX_MCAL_GPIO_H_ */
