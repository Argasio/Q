/*
 * BSP_Callbacks.c
 *
 *  Created on: Dec 11, 2023
 *      Author: A409296
 */

#include "BSP_Peripheral_Handles.h"
#include "BSP_QP.hpp"
#include "BSP_AoFactory.hpp"
#include "Signals.hpp"

/**
  * @brief Tx Transfer completed callback.
  * @param huart UART handle.
  * @retval None
  */
extern "C" void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
	if(huart == QS_uart_p)
	{
		handleQSRxCallback();
	}

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_UART_TxCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief Tx Transfer completed callback.
  * @param huart UART handle.
  * @retval None
  */
extern "C" void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
	if(huart == QS_uart_p)
	{
		handleQSTxCallback();
	}

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_UART_TxCpltCallback can be implemented in the user file.
   */
}

extern "C" void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
	if(huart == QS_uart_p)
	{
		HAL_UART_Abort_IT(huart);
		handleQSError();
	}

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_UART_TxCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  EXTI line rising detection callback.
  * @param  GPIO_Pin: Specifies the port pin connected to corresponding EXTI line.
  * @retval None
  */
void HAL_GPIO_EXTI_Rising_Callback(uint16_t GPIO_Pin)
{
  QK_ISR_ENTRY();
  if(GPIO_Pin == USER_BUTTON_Pin)
  {

      AO_GetButtonPressHandler()->ButtonEvent(nullptr, 0);
  }

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_GPIO_EXTI_Rising_Callback could be implemented in the user file
   */
  QK_ISR_EXIT();
}

/**
  * @brief  EXTI line rising detection callback.
  * @param  GPIO_Pin: Specifies the port pin connected to corresponding EXTI line.
  * @retval None
  */
void HAL_GPIO_EXTI_Falling_Callback(uint16_t GPIO_Pin)
{
  QK_ISR_ENTRY();
  if(GPIO_Pin == USER_BUTTON_Pin)
  {

      AO_GetButtonPressHandler()->ButtonEvent(nullptr, 1);
  }

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_GPIO_EXTI_Rising_Callback could be implemented in the user file
   */
  QK_ISR_EXIT();
}


