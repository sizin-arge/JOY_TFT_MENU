#ifndef __TFT_DRIVER_H__
#define __TFT_DRIVER_H__
// Başlık koruyucusu: Bu dosyanın birden fazla kez dahil edilmesini önler. // Header guard: Prevents this file from being included more than once.

#include "stm32f3xx_hal.h"
// Mikrodenetleyicinin Donanım Soyutlama Katmanı (HAL) kütüphanesini dahil eder. // Includes the microcontroller's Hardware Abstraction Layer (HAL) library.
#include "fonts.h"
// Font verilerini içeren başlık dosyasını dahil eder. // Includes the header file containing font data.

// ST7789 Komutları
// ST7789 ekran denetleyicisinin komut kodlarını tanımlar. // Defines the command codes for the ST7789 display controller.
#define TFT_CMD_NOP         0x00      // No Operation - Hiçbir işlem yapma
#define TFT_CMD_SWRESET     0x01      // Software Reset - Yazılımla sıfırlama
#define TFT_CMD_SLPIN       0x10      // Sleep In - Uyku moduna gir
#define TFT_CMD_SLPOUT      0x11      // Sleep Out - Uyku modundan çık
#define TFT_CMD_INVOFF      0x20      // Display Inversion Off - Ekran renk tersine çevirmeyi kapat
#define TFT_CMD_INVON       0x21      // Display Inversion On - Ekran renk tersine çevirmeyi aç
#define TFT_CMD_DISPOFF     0x28      // Display Off - Ekranı kapat
#define TFT_CMD_DISPON      0x29      // Display On - Ekranı aç
#define TFT_CMD_CASET       0x2A      // Column Address Set - Sütun adresi ayarı
#define TFT_CMD_RASET       0x2B      // Row Address Set - Satır adresi ayarı
#define TFT_CMD_RAMWR       0x2C      // RAM Write - RAM'e yazma
#define TFT_CMD_MADCTL      0x36      // Memory Access Control - Hafıza erişim kontrolü (döndürme için)
#define TFT_CMD_COLMOD      0x3A      // Color Mode - Renk modu

// Renk modu
// RGB565 renk derinliğini tanımlar. Her piksel 16 bit (65 bin renk) kullanır. // Defines the RGB565 color depth. Each pixel uses 16 bits (65k colors).
#define TFT_COLOR_MODE_65K_RGB565  0x55

// Panel boyutları (paneline göre ayarla)
// Ekranın fiziksel çözünürlüğünü tanımlar. // Defines the physical resolution of the screen.
#define TFT_WIDTH   240
#define TFT_HEIGHT  320

// RGB565 renkler
// Sık kullanılan renkler için 16 bitlik RGB565 formatındaki kodları tanımlar. // Defines the 16-bit RGB565 color codes for common colors.
#define TFT_COLOR_BLACK       0x0000
#define TFT_COLOR_NAVY        0x000F
#define TFT_COLOR_DARKGREEN   0x03E0
#define TFT_COLOR_DARKCYAN    0x03EF
#define TFT_COLOR_MAROON      0x7800
#define TFT_COLOR_PURPLE      0x780F
#define TFT_COLOR_OLIVE       0x7BE0
#define TFT_COLOR_LIGHTGREY   0xC618
#define TFT_COLOR_DARKGREY    0x7BEF
#define TFT_COLOR_BLUE        0x001F
#define TFT_COLOR_GREEN       0x07E0
#define TFT_COLOR_CYAN        0x07FF
#define TFT_COLOR_RED         0xF800
#define TFT_COLOR_MAGENTA     0xF81F
#define TFT_COLOR_YELLOW      0xFFE0
#define TFT_COLOR_WHITE       0xFFFF
#define TFT_COLOR_ORANGE      0xFD20
#define TFT_COLOR_GREENYELLOW 0xAFE5
#define TFT_COLOR_PINK        0xF81F

// GPIO/SPI kontrol
// GPIO ve SPI kontrolü için temel fonksiyon prototipleri. // Basic function prototypes for GPIO and SPI control.
void TFT_CS_Set(void);       // Chip Select (CS) pinini HIGH yapar. // Sets the Chip Select (CS) pin to HIGH.
void TFT_CS_Reset(void);     // Chip Select (CS) pinini LOW yapar. // Sets the Chip Select (CS) pin to LOW.
void TFT_DC_Set(void);       // Data/Command (D/C) pinini HIGH yapar (veri modu). // Sets the Data/Command (D/C) pin to HIGH (data mode).
void TFT_DC_Reset(void);     // Data/Command (D/C) pinini LOW yapar (komut modu). // Sets the Data/Command (D/C) pin to LOW (command mode).
void TFT_RST_Set(void);      // Reset (RST) pinini HIGH yapar. // Sets the Reset (RST) pin to HIGH.
void TFT_RST_Reset(void);    // Reset (RST) pinini LOW yapar. // Sets the Reset (RST) pin to LOW.

// Komut/Veri
// Ekrana komut ve veri göndermek için fonksiyon prototipleri. // Function prototypes for sending commands and data to the screen.
void TFT_WriteCommand(uint8_t cmd);    // Bir komut yazar. // Writes a command.
void TFT_WriteData(uint8_t data);      // Bir bayt veri yazar. // Writes a byte of data.
void TFT_WriteColor(uint16_t color);   // 16 bitlik bir renk değeri yazar. // Writes a 16-bit color value.

// Adres penceresi
// Çizim yapılacak dikdörtgen alanı belirler. // Defines the rectangular area to draw on.
void TFT_SetAddressWindow(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);

// Temel API
// Ekranın temel işlevleri için fonksiyon prototipleri. // Function prototypes for basic screen functionalities.
void TFT_Init(SPI_HandleTypeDef* hspi); // SPI handle kullanarak ekranı başlatır. // Initializes the screen using the SPI handle.
void TFT_FillScreen(uint16_t color);    // Tüm ekranı tek bir renkle doldurur. // Fills the entire screen with a single color.
void TFT_SetRotation(uint8_t rotation); // Ekranın yönünü ayarlar. // Sets the orientation of the screen.

// Metin
// Ekrana metin çizmek için fonksiyon prototipleri. // Function prototypes for drawing text on the screen.
void TFT_DrawChar(uint16_t x, uint16_t y, char c, const FontDef* font,
                  uint16_t color, uint16_t bgColor); // Bir karakteri çizer. // Draws a single character.
void TFT_WriteString(uint16_t x, uint16_t y, const char* str, const FontDef* font,
                     uint16_t color, uint16_t bgColor); // Bir metin dizisini çizer. // Draws a string of text.

uint16_t TFT_GetWidth(void);     // Ekranın genişliğini döndürür. // Returns the width of the screen.
uint16_t TFT_GetHeight(void);    // Ekranın yüksekliğini döndürür. // Returns the height of the screen.

#endif /* __TFT_DRIVER_H__ */
