# JOY_TFT_MENU

STM32F3 + ST7789 ile **5 satırlı menü** örneği. CubeMX → HAL/SPI, modüler sürücü + font + menü yapısı.  
A 5-line menu on ST7789 TFT using STM32F3. Modular driver, fonts and menu built on CubeMX + HAL/SPI.

---

## Genel Bakış / Overview
- **TR:** Proje; SPI ile ST7789 TFT sürücüsünü başlatır, 3 farklı fontla 5 satırlı bir menü çizer. Kod modülerdir: `tft_driver`, `fonts`, `menu`.
- **EN:** Initializes ST7789 over SPI and renders a 5-line menu with 3 fonts. Code is modular: `tft_driver`, `fonts`, `menu`.

## Donanım / Hardware
- MCU: **STM32F3** (örnek: STM32F373RCT6)  
- TFT: **ST7789**, 240×320, 16-bit **RGB565**  
- Bus: **SPI1**

## Pinout
| Signal | MCU Pin | User Label | Description |
|-------:|:-------:|:-----------|:------------|
| SCK    | PA5     | —          | SPI clock |
| MISO   | PA6     | —          | (Not used by most ST7789 panels) |
| MOSI   | PA7     | —          | Data to TFT |
| **RST**| PB0     | `TFT_RST`  | Panel reset |
| **DC** | PB1     | `TFT_DC`   | Data/Command select |
| **CS** | PB2     | `TFT_CS`   | Chip select |

> Saat kaynağı: **HSE kristal**, sistem frekansı: **72 MHz** (CubeMX Clock Configuration).

## Klasör Yapısı / Folder Structure
Core/
├─ Inc/
│ ├─ config_pins.h
│ ├─ fonts.h
│ ├─ main.h
│ ├─ menu.h
│ └─ tft_driver.h
└─ Src/
├─ fonts.c
├─ main.c
├─ menu.c
└─ tft_driver.c
JOY_TFT_MENU.ioc # CubeMX konfigürasyonu (KESİNLİKLE repoda kalmalı)

markdown
Kopyala
Düzenle

## Derleme / Build
- **Araçlar / Tools:** STM32CubeIDE + STM32CubeMX  
- **Adımlar / Steps:**
  1. Repoyu klonlayın: `git clone https://github.com/<kullanici>/JOY_TFT_MENU.git`
  2. `JOY_TFT_MENU.ioc` dosyasını CubeMX ile açıp **Generate Code** (isteğe bağlı).
  3. STM32CubeIDE ile projeyi açın, **Build** ve **Run/Debug**.

## Kullanım / Usage
- `main.c` içinde:
  - `TFT_Init(&hspi1);`
  - `Menu_Draw();` — 5 satırlı menüyü çizer (orta satır vurgulu).
- Döndürülebilir: `TFT_SetRotation(0..3)`
- Tam ekran renk: `TFT_FillScreen(TFT_COLOR_*)`

## Notlar / Notes
- Renk formatı: **RGB565**
- Fontlar: 7×10, 11×18, 16×26 (örnek)
- Performans için SPI prescaler ~ **/8 ≈ 9 MHz** (72 MHz PCLK)

## Lisans / License
**MIT** — detaylar için `LICENSE` dosyasına bakınız.

## Video
TR/EN anlatım: ((http://www.youtube.com/@sizinarge))

