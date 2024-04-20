/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    CountSensor.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "CountSensor.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_exti.h"

/* USER CODE BEGIN 0 */

/*
全局变量计数给主函数获取*/
uint16_t CountSensor_Count;

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */
/*
适用于stm32f4xx系列，M4内核
*/
// void HAL_GPIO_EXTI_Config(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin){
//   assert_param(IS_GPIO_PIN(GPIO_Pin));

//   if (GPIO_Pin < GPIO_PIN_8)
//   {
//     /* Configure the SYSCFG EXTICR register to select the GPIO pin */
//     SYSCFG->EXTICR[GPIO_Pin >> 2] &= ~(0x0F << (4 * (GPIO_Pin & 0x03)));
//     SYSCFG->EXTICR[GPIO_Pin >> 2] |= (((uint32_t)(GPIO_GET_INDEX(GPIOx))) << (4 * (GPIO_Pin & 0x03)));
//   }
//   else
//   {
//     /* Configure the SYSCFG EXTICR register to select the GPIO pin */
//     SYSCFG->EXTICR[GPIO_Pin >> 2] &= ~(0x0F << (4 * ((GPIO_Pin >> 4) & 0x03)));
//     SYSCFG->EXTICR[GPIO_Pin >> 2] |= (((uint32_t)(GPIO_GET_INDEX(GPIOx))) << (4 * ((GPIO_Pin >> 4) & 0x03)));
//   }
// }


/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void CountSensor_Init(void)
{
  

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */

  

  /*Configure GPIO pin : PtPin */
  /*
  初始化红外传感器为外部中断模式*/
  GPIO_InitStruct.Pin = COUNTSENSOR_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  // HAL_GPIO_Init(LED0_GPIO_Port, &GPIO_InitStruct);
  HAL_GPIO_Init(COUNTSENSOR_GPIO_Port, &GPIO_InitStruct);

  /*
  配置EXTI中断与GPIO引脚映射
  */
  // __HAL_GPIO_EXTI_GET_IT(COUNTSENSOR_Pin);
  HAL_NVIC_SetPriority(EXTI15_10_IRQn,1,1);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

  /*
  我忘了启动中断监听

//   */
//  HAL_GPIO_EXTI_IRQHandler(COUNTSENSOR_Pin);






}

/* USER CODE BEGIN 2 */
  /*
  注册EXTI中断回调函数*/
// void EXTI15_10_IRQn_Handler(uint16_t GPIO_Pin)
// {
//   if(GPIO_Pin ==COUNTSENSOR_Pin){
//     CountSensor_Count++;
//   }
// }

void EXTI15_10_IRQHandler(void) {
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_14);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
  if (GPIO_Pin==COUNTSENSOR_Pin)
  {
    /* code */
    /*不得不说再次判断引脚电平很重要，处理数据乱跳情况,这个位置选的非常，因为是下降沿也就是从高变低，也就为低电平才行*/
    /*这个真的是非常天才且精确，在写这些东西时，要注意状态的变化，将状态作为判断条件，而不是傻乎乎的只想着从程序配置方面解决*/
    /*如果为上升沿触发，这里改为判断1即可*/
    /*实际上这里遮住光为高电平，所以改为0,上升沿*/
      GPIO_PinState bitstatus=GPIO_PIN_RESET;


    if(HAL_GPIO_ReadPin(COUNTSENSOR_GPIO_Port,COUNTSENSOR_Pin) == bitstatus){
    CountSensor_Count++;
    }
  }
  
}
/*

*获取传感计数器计数值
*/
uint16_t CountSensor_Get(void){
  return CountSensor_Count;
}

/* USER CODE END 2 */