/*
 * BSP_McalFactory.hpp
 *
 *  Created on: Dec 13, 2023
 *      Author: A409296
 */

#ifndef BSP_MCALFACTORY_HPP_
#define BSP_MCALFACTORY_HPP_

#include <MCAL_Gpio.hpp>
#include "BSP_Peripheral_Handles.h"

enum Gpios
{
	Led_Red,
	Led_Green,
};

MCAL::iGpio*     MCalGetGpio(Gpios gpio);

#endif /* BSP_MCALFACTORY_HPP_ */
