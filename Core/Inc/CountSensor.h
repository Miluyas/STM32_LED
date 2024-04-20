/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    CountSensor.h
  * @brief   This file contains all the function prototypes for
  *          the CountSensor.c file
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
#ifndef __COUNTSENSOR_H__
#define __COUNTSENSOR_H__

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
void CountSensor_Init(void);
uint16_t CountSensor_Get(void);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ COUNTSENSOR_H__ */

