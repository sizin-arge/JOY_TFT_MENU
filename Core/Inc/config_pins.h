#ifndef __CONFIG_PINS_H__
#define __CONFIG_PINS_H__
// Bu satırlar, header dosyasının birden fazla kez dahil edilmesini engeller. // These lines prevent the header file from being included multiple times.

#include "stm32f3xx_hal.h"
// Bu satır, STM32F3 HAL (Donanım Soyutlama Katmanı) kütüphanesini dahil eder. // This line includes the STM32F3 HAL (Hardware Abstraction Layer) library.

/**********************************************************/
/***************** TFT_Pin_Ayarlari ***********************/
// Bu bölüm, TFT ekranın mikrodenetleyiciye olan pin bağlantılarını tanımlar. // This section defines the pin connections of the TFT display to the microcontroller.


#define TFT_RST_Pin       GPIO_PIN_0
#define TFT_RST_GPIO_Port GPIOB
// TFT ekranın RST (Reset) pini, B portunun 0. pinine bağlıdır. // The TFT display's RST (Reset) pin is connected to pin 0 of port B.


#define TFT_CS_Pin        GPIO_PIN_2
#define TFT_CS_GPIO_Port  GPIOB
// TFT ekranın CS (Chip Select) pini, B portunun 2. pinine bağlıdır. // The TFT display's CS (Chip Select) pin is connected to pin 2 of port B.


#define TFT_DC_Pin        GPIO_PIN_1
#define TFT_DC_GPIO_Port  GPIOB
// TFT ekranın DC (Data/Command) pini, B portunun 1. pinine bağlıdır. // The TFT display's DC (Data/Command) pin is connected to pin 1 of port B.

/**********************************************************/

#endif /* __CONFIG_PINS_H__ */
// Bu satır, "#ifndef" bloğunu sonlandırır. // This line ends the "#ifndef" block.
