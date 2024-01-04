/*
 * BSP_Init.hpp
 *
 *  Created on: Dec 11, 2023
 *      Author: A409296
 */

#ifndef BSP_HANDLERFACTORY_HPP_
#define BSP_HANDLERFACTORY_HPP_

#include "qpcpp.hpp"        // QP/C++ real-time embedded framework
#include "../COMPONENTS/LedHandler.hpp"



APP::LedHandler* AppGetLedHandler();



#endif /* BSP_HANDLERFACTORY_HPP_ */
