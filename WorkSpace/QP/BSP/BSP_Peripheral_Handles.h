/*
 * BSP_Peripheral_Handles.h
 *
 *  Created on: Dec 5, 2023
 *      Author: A409296
 */

#ifndef BSP_PERIPHERAL_HANDLES_H_
#define BSP_PERIPHERAL_HANDLES_H_

#include "stm32h5xx_hal.h"
#include "main.h"

extern UART_HandleTypeDef huart3;
#define QS_uart_p (&huart3)
#define huartTrace (huart3)



#endif /* BSP_PERIPHERAL_HANDLES_H_ */
