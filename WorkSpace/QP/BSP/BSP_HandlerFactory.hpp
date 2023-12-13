/*
 * BSP_Init.hpp
 *
 *  Created on: Dec 11, 2023
 *      Author: A409296
 */

#ifndef BSP_HANDLERFACTORY_HPP_
#define BSP_HANDLERFACTORY_HPP_

#include "LedHandler.hpp"
#include "qpcpp.hpp"        // QP/C++ real-time embedded framework



APP::LedHandler* AppGetLedHandler();



#endif /* BSP_HANDLERFACTORY_HPP_ */
