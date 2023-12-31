/*
 * BSP_AoFactory.hpp
 *
 *  Created on: Dec 13, 2023
 *      Author: A409296
 */

#ifndef BSP_AOFACTORY_HPP_
#define BSP_AOFACTORY_HPP_


#include "Signals.hpp"
#include "AO_Blinker.hpp"
#include "AO_ButtonPressHandler.hpp"
enum AO_PRIORITIES{
    AO_LED_PRIO = 1u,
	AO_BTN_PRIO = 2u,
    AO_PRIO_MAX
};
AO::Blinker* AO_GetBlinker();
AO::ButtonPressHandler* AO_GetButtonPressHandler();


#endif /* BSP_AOFACTORY_HPP_ */
