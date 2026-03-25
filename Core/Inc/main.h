/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32c0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SfERRbms_Pin GPIO_PIN_14
#define SfERRbms_GPIO_Port GPIOC
#define SfERRimd_Pin GPIO_PIN_15
#define SfERRimd_GPIO_Port GPIOC
#define SfINTresbut_Pin GPIO_PIN_1
#define SfINTresbut_GPIO_Port GPIOA
#define SfLCHebms_Pin GPIO_PIN_2
#define SfLCHebms_GPIO_Port GPIOA
#define SfLCHeimd_Pin GPIO_PIN_3
#define SfLCHeimd_GPIO_Port GPIOA
#define SfSDCbms_Pin GPIO_PIN_5
#define SfSDCbms_GPIO_Port GPIOA
#define SfSDCimd_Pin GPIO_PIN_6
#define SfSDCimd_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */
typedef union {
	uint8_t array[12];
	struct{
	/* ================ MISSATGE 1 ================ */
	uint8_t SfERRbms;
	uint8_t SfERRimd;
	uint8_t SfLCHebms;
	uint8_t SfLCHeimd;
	uint8_t SfINTresbut;
	uint8_t SfSDCbms;
	uint8_t SfSDCimd;
	uint16_t SfSHU;
	};
} DICCF_t;

typedef struct {
	uint8_t SpERRbms;
	uint8_t SpERRimd;
	uint8_t SpLCHebms;
	uint8_t SpLCHeimd;
	uint8_t SpINTresbut;
	uint8_t SpSDCbms;
	uint8_t SpSDCimd;
	uint16_t SpSHU;
}DICCP_t;

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
