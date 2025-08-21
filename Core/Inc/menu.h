#ifndef MENU_H
#define MENU_H
// Bu satırlar, başlık dosyasının tekrar tekrar dahil edilmesini önler. // These lines prevent the header file from being included repeatedly.

#include <stdint.h>
// Sabit boyutlu tamsayı türlerini kullanmak için gerekli kütüphane. // Required library for using fixed-size integer types.
#include "fonts.h"
// Font verilerini içeren başlık dosyasını dahil eder. // Includes the header file containing font data.
#include "tft_driver.h"
// TFT ekran sürücüsü işlevlerini içeren başlık dosyasını dahil eder. // Includes the header file with TFT screen driver functions.

// Bir menü öğesinin yapısını tanımlar. // Defines the structure of a menu item.
typedef struct {
    const char      *text;
    // Menü öğesinin gösterilecek metni. // The text to be displayed for the menu item.
    const FontDef   *font;      // <-- pointer
    // Metin için kullanılacak font tanımına işaretçi. // A pointer to the font definition to be used for the text.
    uint16_t         textColor;
    // Menü öğesi metninin rengi. // The color of the menu item's text.
    uint16_t         bgColor;
    // Menü öğesi metninin arka plan rengi. // The background color of the menu item's text.
} MenuItem;

void Menu_Draw(void);
// Menünün tamamını ekrana çizen işlevin prototipi. // Prototype of the function that draws the entire menu on the screen.
void Menu_SetSelected(int index);
// Belirtilen indeksteki menü öğesini seçili olarak ayarlayan işlevin prototipi. // Prototype of the function that sets the menu item at the specified index as selected.

#endif // MENU_H
// Başlık koruyucusunu sonlandırır. // Ends the header guard.
