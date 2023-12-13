/*
 * BSP_AoFactory.hpp
 *
 *  Created on: Dec 13, 2023
 *      Author: A409296
 */

#ifndef BSP_AOFACTORY_HPP_
#define BSP_AOFACTORY_HPP_


#include "Signals.hpp"
#include "AO_ButtonBlink.hpp"

enum AO_PRIORITIES{
    AO_LED_PRIO = 1u,
    AO_BUTTON_PRIO,
};
ButtonBlink* AO_GetButtonBlink();



#endif /* BSP_AOFACTORY_HPP_ */
