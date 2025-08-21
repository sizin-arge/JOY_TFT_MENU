/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : menu.c
  * @brief          : TFT Menu Functions
  ******************************************************************************
  */ /* TR: Üst bilgi / dosya açıklaması | EN: File header / description */
/* USER CODE END Header */  // TR: Otomatik şablon etiketi | EN: Template marker

#include <string.h>          // TR: C string fonksiyonları | EN: C string utilities
#include "menu.h"            // TR: Menü yapı ve prototipleri | EN: Menu structs & prototypes
#include "tft_driver.h"      // TR: TFT sürücü arayüzü | EN: TFT driver interface


static MenuItem menuItems[5] = {  // TR: 5 öğelik sabit menü listesi | EN: Fixed 5-item menu list
    { "> QUICK START",   &Font_7x10,   TFT_COLOR_WHITE,  TFT_COLOR_BLACK }, // TR: 1. satır | EN: Row 1
    { "> DISPLAY",       &Font_11x18,  TFT_COLOR_WHITE,  TFT_COLOR_BLACK }, // TR: 2. satır | EN: Row 2
    { "> JOYSTICK TEST", &Font_16x26,  TFT_COLOR_CYAN,   TFT_COLOR_BLACK }, // TR: 3. satır (vurgulu) | EN: Row 3 (highlight)
    { "> COLORS",        &Font_11x18,  TFT_COLOR_WHITE,  TFT_COLOR_BLACK }, // TR: 4. satır | EN: Row 4
    { "> ABOUT",         &Font_7x10,   TFT_COLOR_WHITE,  TFT_COLOR_BLACK }, // TR: 5. satır | EN: Row 5
};


static int s_selected = 2;   // TR: Seçili öğe indeksi (başlangıçta 3. öğe) | EN: Selected index (starts at 3rd item)


void Menu_SetSelected(int index)  // TR: Seçili menü öğesini ayarla | EN: Set selected menu item
{
    int count = (int)(sizeof(menuItems) / sizeof(menuItems[0])); // TR: Toplam öğe sayısı | EN: Total item count
    if (index < 0) index = 0;                  // TR: Alt sınırla | EN: Clamp to lower bound
    if (index >= count) index = count - 1;     // TR: Üst sınırla | EN: Clamp to upper bound
    s_selected = index;                        // TR: Geçerli seçimi güncelle | EN: Update current selection
}


void Menu_Draw(void)          // TR: Menüyü ekrana çiz | EN: Draw the menu on the screen
{
    const int16_t MARGIN_LEFT  = 8;   // TR: Sol kenar boşluğu (px) | EN: Left margin (px)
    const int16_t LINE_SPACING = 10;  // TR: Satırlar arası boşluk (px) | EN: Line spacing (px)

    uint16_t totalH = 0;              // TR: Menünün toplam yüksekliği | EN: Total menu height
    for (int i = 0; i < 5; i++) {     // TR: Tüm satırları dolaş | EN: Iterate all menu rows
        totalH += menuItems[i].font->height;  // TR: Font yüksekliğini ekle | EN: Accumulate font height
    }
    totalH += (5 - 1) * LINE_SPACING; // TR: Satır arası boşlukları ekle | EN: Add inter-line spacing

    int16_t startY = 0;               // TR: Başlangıç Y konumu | EN: Start Y position
    if (TFT_GetHeight() > totalH) {   // TR: Menü ekran yüksekliğinden küçükse | EN: If menu fits vertically
        startY = (int16_t)((TFT_GetHeight() - totalH) / 2); // TR: Dikey ortala | EN: Vertically center
    }

    TFT_FillScreen(TFT_COLOR_BLACK);  // TR: Arka planı siyaha boya | EN: Clear screen to black

    int16_t y = startY;               // TR: İlk satırın Y konumu | EN: Y position of first row
    for (int i = 0; i < 5; i++) {     // TR: Satırları çiz | EN: Draw each row
        const MenuItem *it = &menuItems[i]; // TR: Aktif öğe işaretçisi | EN: Pointer to current item
        uint16_t textColor = it->textColor; // TR: Varsayılan yazı rengi | EN: Default text color
        uint16_t bgColor   = TFT_COLOR_BLACK; // TR: Arka plan rengi (siyah) | EN: Background color (black)

        if (i == s_selected) {        // TR: Seçili satır mı? | EN: Is this the selected row?
            textColor = TFT_COLOR_CYAN; // TR: Seçili satırı vurgu rengine çek | EN: Highlight color
            bgColor   = TFT_COLOR_BLACK; // TR: Arka plan siyah kalsın | EN: Keep black background
        }

        TFT_WriteString(MARGIN_LEFT, y, it->text, it->font, textColor, bgColor);
        // TR: Satır metnini çiz (sol boşluk, y konumu, font, renkler)
        // EN: Render row text (left margin, y position, font, colors)

        y += it->font->height + LINE_SPACING; // TR: Sonraki satırın Y konumuna geç | EN: Advance Y for next row

        TFT_WriteString(90, 20, "SizinArGe", &Font_16x26, TFT_COLOR_WHITE, TFT_COLOR_BLACK);
        // TR: Üstte logoyu/başlığı çiz (not: döngü içinde 5 kez yazılır; istenirse döngü dışına alınabilir)
        // EN: Draw logo/title at top (note: drawn 5 times in loop; can be moved outside if desired)
    }
}


