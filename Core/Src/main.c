/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
#include "main.h"
// #include "gpio.h"
// #include "key.h"
// #include "buzzer.h"
// #include "LightSensor.h"
#include "OLED.h"
#include"CountSensor.h"
#include "stm32f1xx_hal.h"


/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();


  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  // MX_GPIO_Init();

  /* USER CODE BEGIN 2 */
  // Key_Init();
  // BUZZER_Init();
  // LightSensor_Init();
  CountSensor_Init();
  OLED_Init();

  
  
  //确实显示不好入死循环

  //LED显示
  OLED_ShowString(1,1,"hello6");
  // OLED_ShowString(1,3,"HELLO WORLD!");//一行三列开始显示
  // OLED_ShowNum(2,1,12345,5);
  // OLED_ShowSignedNum(2,7,-66,2);//2行7列显示十进制-66，长度为2
  // OLED_ShowHexNum(3,1,0xAA55,4);
  // OLED_ShowBinNum(4,1,0xAA55,16);//c语言无法直接写出二进制数字，所以需要16进制来表示

 
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    // /* USER CODE END WHILE */
    OLED_ShowNum(1,7,CountSensor_Get(),5);

    /*
    小灯的控制程序
    */
    // // HAL_Delay(500);
    // if(HAL_GPIO_ReadPin(GPIOB,KEY0_Pin)==GPIO_PIN_RESET)
    // {
    //   HAL_Delay(20);
    //   while (HAL_GPIO_ReadPin(GPIOB,KEY0_Pin)==GPIO_PIN_RESET){
    //     HAL_Delay(20);
    //     }
    //     LED0_Toggle();
    //     //  {/* code */
    //   //   HAL_Delay(20);
    //   //   LED0_Toggle();
    //   //  }不该将toggle包含在循环里，会导致不断20ms交换状态
    //   /* code */
       
  
    // }

    // if(HAL_GPIO_ReadPin(GPIOB,KEY1_Pin)==GPIO_PIN_RESET)
    // {
    //   HAL_Delay(20);
    //   while (HAL_GPIO_ReadPin(GPIOB,KEY1_Pin)==GPIO_PIN_RESET){
    //     /* code */
    //     HAL_Delay(20);
    //   }
    //     LED1_Toggle();
    // }

    // if (LightSensor_get()==GPIO_PIN_RESET)
    // {
    //   /* code */
    //   BUZZER_ON();
    // }
    // if (LightSensor_get()==GPIO_PIN_SET)
    // {
    //   /* code */
    //   BUZZER_OFF();
    // }
    
    



    }
       
    // LED0_Toggle();
    // LED1_Toggle();

    

    /* USER CODE BEGIN 3 */
}
  /* USER CODE END 3 */


/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
