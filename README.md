JOY_TFT_MENU

STM32F3 + ST7789 (ST7789V) — 5-line TFT menu. CubeMX → HAL/SPI, modular driver + fonts + menu.

TL;DR (EN)

Open JOY_TFT_MENU.ioc in STM32CubeMX → Generate Code

Open project in STM32CubeIDE → Build & Flash

You should see the 5-line menu on ST7789 TFT.

Kısa Özet (TR)

STM32CubeMX ile JOY_TFT_MENU.ioc dosyasını aç → Generate Code

STM32CubeIDE’de projeyi aç → Derle & Yükle

ST7789 TFT’de 5 satırlı menü görüntülenir.

Hardware / Donanım

MCU: STM32F3 (ör. STM32F373)

TFT: ST7789, 240×320, 16-bit RGB565

SPI: SPI1

Pinout
İşlev	MCU Pin	Açıklama
SCK	PA5	SPI clock
MOSI	PA7	Master → TFT veri
MISO	PA6	(opsiyonel, çoğu ST7789’da kullanılmaz)
TFT_CS	PB2	Chip Select
TFT_DC	PB1	Data/Command
TFT_RST	PB0	Donanımsal Reset

Not: Pin etiketleri Core/Inc/config_pins.h içinde. Kart değişince buradan güncelleyin.

Folder Structure / Klasör Yapısı
Core/
  Inc/   -> main.h, config_pins.h, tft_driver.h, fonts.h, menu.h
  Src/   -> main.c, tft_driver.c, fonts.c, menu.c
JOY_TFT_MENU.ioc  -> CubeMX proje ayarları (pin/clock/SPI)

Build Steps / Derleme Adımları

CubeMX: JOY_TFT_MENU.ioc → Generate Code (Drivers/ayarlar oluşur)

CubeIDE: Projeyi aç → Build (hammer) → Run/Debug (play)

TFT’de menüyü görün.

Notes

Renkler: RGB565.

Yazı tipleri: 7×10, 11×18, 16×26 (bkz. fonts.[ch]).

Menü çizimi: Menu_Draw() (bkz. menu.c).

Ekran döndürme: TFT_SetRotation().

License

MIT — ayrıntı için LICENSE.

Video

YouTube: (http://www.youtube.com/@sizinarge)
