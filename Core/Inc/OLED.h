/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    OLED.h
  * @brief   This file contains all the function prototypes for
  *          the OLED.c file
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __OLED_H__
#define __OLED_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

/* USER CODE BEGIN Prototypes */
void OLED_Init(void);
void OLED_Clear(void);
// void OLED_I2C_Start(void);
// void OLED_I2C_Stop(void);
// void OLED_I2C_SendByte(uint8_t Byte);
// void OLED_WriteCommand(uint8_t Command);
// void OLED_WriteData(uint8_t Data);外部不用的就不写在这里
void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char);
void OLED_ShowString(uint8_t Line, uint8_t Column, char *String);
void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length);
void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);




/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ OLED_H__ */

