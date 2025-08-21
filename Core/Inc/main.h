/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file. // main.c dosyası için başlık.
  * This file contains the common defines of the application. // Bu dosya uygulamanın ortak tanımlarını içerir.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component. // Bu yazılım, bu yazılım bileşeninin kök dizininde bulunan LİSANS dosyasında yer alan şartlar ve koşullar kapsamında lisanslanmıştır.
  * If no LICENSE file comes with this software, it is provided AS-IS. // Eğer bu yazılımla birlikte bir LİSANS dosyası gelmiyorsa, yazılım olduğu gibi sağlanır.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H
// Bu satırlar, başlık dosyasının tekrar tekrar dahil edilmesini önler. // These lines prevent the header file from being included repeatedly.

#ifdef __cplusplus
extern "C" {
#endif
// Bu kısım, C++ derleyicisinin bu kodu C kodu olarak işlemesini sağlar. // This part ensures that a C++ compiler processes this code as C code.

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"
// Donanım Soyutlama Katmanı (HAL) kütüphanesini dahil eder. // Includes the Hardware Abstraction Layer (HAL) library.

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
// Hata oluştuğunda çağrılacak işlevin prototipini bildirir. // Declares the prototype of the function to be called on an error.

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define TFT_RST_Pin GPIO_PIN_0
#define TFT_RST_GPIO_Port GPIOB
#define TFT_DC_Pin GPIO_PIN_1
#define TFT_DC_GPIO_Port GPIOB
#define TFT_CS_Pin GPIO_PIN_2
#define TFT_CS_GPIO_Port GPIOB
// Bu satırlar, TFT ekranın pin bağlantılarını tanımlar. // These lines define the pin connections for the TFT screen.

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
// Başlık koruyucu tanımlamasını sonlandırır. // Ends the header guard definition.
