
/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file         stm32h7xx_hal_msp.c
  * @brief        This file provides code for the MSP Initialization
  *               and de-Initialization codes.
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
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN Define */

/* USER CODE END Define */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN Macro */

/* USER CODE END Macro */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* External functions --------------------------------------------------------*/
/* USER CODE BEGIN ExternalFunctions */

/* USER CODE END ExternalFunctions */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */
/**
  * Initializes the Global MSP.
  */
void HAL_MspInit(void)
{

  /* USER CODE BEGIN MspInit 0 */

  /* USER CODE END MspInit 0 */

  __HAL_RCC_SYSCFG_CLK_ENABLE();

  /* System interrupt init*/

  /* USER CODE BEGIN MspInit 1 */

  /* USER CODE END MspInit 1 */
}

static uint32_t SAI2_client =0;

void HAL_SAI_MspInit(SAI_HandleTypeDef* hsai)
{

  GPIO_InitTypeDef GPIO_InitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
/* SAI2 */
    if(hsai->Instance==SAI2_Block_A)
    {
    /* Peripheral clock enable */

  /** Initializes the peripherals clock
  */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_SAI2;
    PeriphClkInitStruct.Sai23ClockSelection = RCC_SAI23CLKSOURCE_PLL;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    if (SAI2_client == 0)
    {
       __HAL_RCC_SAI2_CLK_ENABLE();
    }
    SAI2_client ++;

    /**SAI2_A_Block_A GPIO Configuration
    PI6     ------> SAI2_SD_A
    PI5     ------> SAI2_SCK_A
    PI4     ------> SAI2_MCLK_A
    PI7     ------> SAI2_FS_A
    */
    GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_5|GPIO_PIN_4|GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF10_SAI2;
    HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);

    }
    if(hsai->Instance==SAI2_Block_B)
    {
      /* Peripheral clock enable */

  /** Initializes the peripherals clock
  */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_SAI2;
    PeriphClkInitStruct.Sai23ClockSelection = RCC_SAI23CLKSOURCE_PLL;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

      if (SAI2_client == 0)
      {
       __HAL_RCC_SAI2_CLK_ENABLE();
      }
    SAI2_client ++;

    /**SAI2_B_Block_B GPIO Configuration
    PG10     ------> SAI2_SD_B
    */
    GPIO_InitStruct.Pin = GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF10_SAI2;
    HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

    }
}

void HAL_SAI_MspDeInit(SAI_HandleTypeDef* hsai)
{
/* SAI2 */
    if(hsai->Instance==SAI2_Block_A)
    {
    SAI2_client --;
    if (SAI2_client == 0)
      {
      /* Peripheral clock disable */
       __HAL_RCC_SAI2_CLK_DISABLE();
      }

    /**SAI2_A_Block_A GPIO Configuration
    PI6     ------> SAI2_SD_A
    PI5     ------> SAI2_SCK_A
    PI4     ------> SAI2_MCLK_A
    PI7     ------> SAI2_FS_A
    */
    HAL_GPIO_DeInit(GPIOI, GPIO_PIN_6|GPIO_PIN_5|GPIO_PIN_4|GPIO_PIN_7);

    }
    if(hsai->Instance==SAI2_Block_B)
    {
    SAI2_client --;
      if (SAI2_client == 0)
      {
      /* Peripheral clock disable */
      __HAL_RCC_SAI2_CLK_DISABLE();
      }

    /**SAI2_B_Block_B GPIO Configuration
    PG10     ------> SAI2_SD_B
    */
    HAL_GPIO_DeInit(GPIOG, GPIO_PIN_10);

    }
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
