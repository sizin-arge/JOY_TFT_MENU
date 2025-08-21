/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

// Bu bölüme, projenize özel başlık dosyalarını (header files) dahil edebilirsiniz.
// Örneğin, "tft_driver.h" ve "menu.h" gibi kendi yazdığınız fonksiyonları burada eklersiniz.
// You can include your project-specific header files in this section.
// For example, custom files like "tft_driver.h" and "menu.h" should be added here.

#include "tft_driver.h"
#include "menu.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

// Bu bölüme, programınız için özel veri tiplerini (struct, enum, union) tanımlayabilirsiniz.
// Bu, kodunuzu daha okunabilir ve düzenli hale getirmek için faydalıdır.
// In this section, you can define custom data types (struct, enum, union) for your program.
// This is useful for making your code more readable and organized.

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

// Burada, projenize özel sabitleri (#define) veya makroları tanımlayabilirsiniz.
// Örneğin, TFT renkleri veya pin numaraları gibi değerleri burada belirleyebilirsiniz.
// Here you can define project-specific constants (#define) or macros.
// For example, you might define TFT colors or pin numbers here.

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;

/* USER CODE BEGIN PV */

// Bu bölüme, tüm program boyunca erişebileceğiniz global değişkenleri tanımlayabilirsiniz.
// Örneğin, menü durumu veya sensör verileri gibi değişkenler buraya eklenebilir.
// In this section, you can declare global variables that are accessible throughout the program.
// For example, variables for menu state or sensor data can be added here.

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);

/* USER CODE BEGIN PFP */

// Projenizde kullandığınız yeni fonksiyonların prototiplerini (tanımlarını) buraya ekleyebilirsiniz.
// Bu, derleyicinin fonksiyonları tanıyabilmesini sağlar.
// You can add the prototypes (declarations) of new functions used in your project here.
// This allows the compiler to recognize your custom functions.

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

// Bu bölüm, main fonksiyonundan önce çalışacak kodlar veya özel başlatma işlemleri için kullanılabilir.
// This section can be used for code that runs before the main function or for special initialization routines.

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  // main fonksiyonunun en başında, HAL_Init() çağrılmadan önce çalışacak kodlar için kullanılır.
  // This section is used for code that should run at the very beginning of the main function,
  // before the HAL_Init() call.

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  // HAL_Init() çağrıldıktan sonra, sistem saati yapılandırması öncesinde çalışacak kodlar için kullanılır.
  // Bu bölüm, genellikle donanım başlatma öncesi özel ayarlamalar için idealdir.
  // This section is for code that should run after HAL_Init() but before the system clock is configured.
  // It is ideal for special settings before hardware initialization.

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  // Sistem saati yapılandırıldıktan sonra, çevrebirim başlatma öncesinde çalışacak kodlar için kullanılır.
  // Bu bölüm, sisteme bağlı diğer başlatma işlemleri için uygundur.
  // This section is for code that runs after the system clock is configured but before peripheral initialization.
  // It is suitable for other system-level initialization tasks.

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */

  MX_GPIO_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */

  // Bu bölüme, çevrebirimler başlatıldıktan sonra, ana döngüye (while(1)) girmeden önce çalışacak kodları ekleyin.
  // Bu, uygulamanızın ilk başlangıç ekranını veya menüsünü hazırlamak için ideal bir yerdir.
  // Use this section for code that runs after all peripherals have been initialized, but before entering the main loop (while(1)).
  // This is the ideal place to prepare your application's first screen or menu.

 TFT_Init(&hspi1);

 TFT_SetRotation(0);
 TFT_FillScreen(TFT_COLOR_BLACK);
     TFT_SetRotation(1);
      TFT_FillScreen(TFT_COLOR_BLACK);

Menu_Draw();


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  // Bu ana döngü, programınızın kalbidir. Tekrarlayan tüm işler (sensör okuma, tuş kontrolü, ekran güncelleme vb.)
  // bu döngü içinde yer almalıdır.
  // This main loop is the heart of your program. All repetitive tasks (reading sensors, checking buttons,
  // updating the screen, etc.) should be placed inside this loop.

  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

    /* USER CODE END 3 */
  }
  /* USER CODE END 3 */
}

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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  // Bu bölüme, SPI1 başlatma kodundan önce özel ayarlar ekleyebilirsiniz.
  // In this section, you can add specific settings before the SPI1 initialization code.

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  // SPI1 başlatma yapılandırmasının hemen öncesinde çalışacak kodlar için kullanılır.
  // Bu, HAL_SPI_Init() çağrısından önce özel ön koşulları kontrol etmek için idealdir.
  // This is used for code that runs just before the SPI1 initialization configuration.
  // It's ideal for checking specific preconditions before the HAL_SPI_Init() call.

  /* USER CODE END SPI1_Init 1 */

  /* SPI1 parameter configuration*/

  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 7;
  hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi1.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  // Bu bölüme, SPI1 başlatıldıktan sonra çalışacak özel ayarlar veya kontroller ekleyebilirsiniz.
  // Örneğin, bir çevre biriminin hazır olup olmadığını kontrol etmek gibi.
  // In this section, you can add special settings or checks that run after SPI1 has been initialized.
  // For example, checking if a peripheral is ready.

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  // Bu bölüm, GPIO başlatma kodunun öncesinde özel pin ayarlamaları için kullanılır.
  // This section is used for custom pin settings before the GPIO initialization code.

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */

  HAL_GPIO_WritePin(GPIOB, TFT_RST_Pin|TFT_DC_Pin|TFT_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : TFT_RST_Pin TFT_DC_Pin TFT_CS_Pin */

  GPIO_InitStruct.Pin = TFT_RST_Pin|TFT_DC_Pin|TFT_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  // Bu bölüme, GPIO pinleri başlatıldıktan sonra ek ayarlar veya pin durumu kontrolleri ekleyebilirsiniz.
  // In this section, you can add extra settings or pin state checks after the GPIO pins have been initialized.

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

// Bu bölüme, projenize özel fonksiyonları (örneğin, interrupt servis rutinleri) ekleyebilirsiniz.
// Bu fonksiyonlar, diğer bölümlerdeki fonksiyonlar gibi otomatik olarak silinmez.
// In this section, you can add custom functions for your project (e.g., interrupt service routines).
// These functions will not be automatically deleted like those in other sections.

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
  * where the assert_param error has occurred.
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
