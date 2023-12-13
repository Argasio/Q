/*
 * Qp_Bsp.hpp
 *
 *  Created on: Dec 1, 2023
 *      Author: A409296
 */





#include "qpcpp.hpp"             // QP/C++ real-time embedded framework
#include "BSP_Peripheral_Handles.h"

#ifndef QP_BSP_HPP_
#define QP_BSP_HPP_

#ifdef __cplusplus

extern "C" {
#endif /* __cplusplus */



void  QS_Init();
void handleQSRxCallback();
void SysTick_Handler(void); // prototype


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* QP_BSP_HPP_ */
