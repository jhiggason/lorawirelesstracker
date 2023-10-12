// Description: This file contains the main program for the LCD test.
#include "HT_st7735.h"
#include "Arduino.h"

// Constants for colors and fonts
const uint16_t BORDER_COLOR = ST7735_RED;
const uint16_t FONT_7x10_COLOR = ST7735_RED;
const uint16_t FONT_11x18_COLOR = ST7735_GREEN;
const uint16_t FONT_16x26_COLOR = ST7735_BLUE;
const uint16_t BLACK_COLOR = ST7735_BLACK;
const uint16_t BLUE_COLOR = ST7735_BLUE;
const uint16_t RED_COLOR = ST7735_RED;
const uint16_t GREEN_COLOR = ST7735_GREEN;
const uint16_t CYAN_COLOR = ST7735_CYAN;
const uint16_t MAGENTA_COLOR = ST7735_MAGENTA;
const uint16_t YELLOW_COLOR = ST7735_YELLOW;
const uint16_t WHITE_COLOR = ST7735_WHITE;

// Constants for delay times
const uint16_t BORDER_DELAY = 3000;
const uint16_t FONT_DELAY = 2000;
const uint16_t COLOR_DELAY = 500;

HT_st7735 st7735;

void setup() {
  pinMode(Vext, OUTPUT);
  digitalWrite(Vext, HIGH); //LCD needs power before init.
  Serial.begin(115200);
  st7735.st7735_init();
  Serial.printf("Ready!\r\n");
}

void loop() {
    // Check border
    st7735.st7735_fill_screen(BLACK_COLOR);  

    for(int x = 0; x < ST7735_WIDTH; x++) {
        st7735.st7735_draw_pixel(x, 0, BORDER_COLOR);
        st7735.st7735_draw_pixel(x, ST7735_HEIGHT-1, BORDER_COLOR);
    }

    for(int y = 0; y < ST7735_HEIGHT; y++) {
        st7735.st7735_draw_pixel(0, y, BORDER_COLOR);
        st7735.st7735_draw_pixel(ST7735_WIDTH-1, y, BORDER_COLOR);
    }

    delay(BORDER_DELAY);

    // Check fonts
    st7735.st7735_fill_screen(BLACK_COLOR);  
    st7735.st7735_write_str(0, 0, "Font_7x10, red on black, lorem ipsum dolor sit amet", Font_7x10, FONT_7x10_COLOR, BLACK_COLOR);  
    st7735.st7735_write_str(0, 3*10, "Font_11x18, green, lorem ipsum", Font_11x18, FONT_11x18_COLOR, BLACK_COLOR);  
    st7735.st7735_write_str(0, 3*10+3*18, "Font_16x26", Font_16x26, FONT_16x26_COLOR, BLACK_COLOR);  
    delay(FONT_DELAY);

    // Check colors
    // Using corrected BLACK_COLOR and appropriate background colors for all the color tests
    st7735.st7735_fill_screen(BLACK_COLOR);
    st7735.st7735_write_str(0, 0, "BLACK", Font_11x18, WHITE_COLOR, BLACK_COLOR);

    delay(COLOR_DELAY);

    st7735.st7735_fill_screen(BLUE_COLOR);
    st7735.st7735_write_str(0, 0, "BLUE", Font_11x18, BLACK_COLOR, BLUE_COLOR);

    delay(COLOR_DELAY);
 
    st7735.st7735_fill_screen(RED_COLOR);
    st7735.st7735_write_str(0, 0, "RED", Font_11x18, BLACK_COLOR, RED_COLOR);

    delay(COLOR_DELAY);

    st7735.st7735_fill_screen(GREEN_COLOR);
    st7735.st7735_write_str(0, 0, "GREEN", Font_11x18, BLACK_COLOR, GREEN_COLOR);

    delay(COLOR_DELAY);

    st7735.st7735_fill_screen(CYAN_COLOR);
    st7735.st7735_write_str(0, 0, "CYAN", Font_11x18, BLACK_COLOR, CYAN_COLOR);

    delay(COLOR_DELAY);

    st7735.st7735_fill_screen(MAGENTA_COLOR);
    st7735.st7735_write_str(0, 0, "MAGENTA", Font_11x18, BLACK_COLOR, MAGENTA_COLOR);

    delay(COLOR_DELAY);

    st7735.st7735_fill_screen(YELLOW_COLOR);
    st7735.st7735_write_str(0, 0, "YELLOW", Font_11x18, BLACK_COLOR, YELLOW_COLOR);

    delay(COLOR_DELAY);

    st7735.st7735_fill_screen(WHITE_COLOR);
    st7735.st7735_write_str(0, 0, "WHITE", Font_11x18, BLACK_COLOR, WHITE_COLOR);

    delay(COLOR_DELAY);

    while(1);  // Keep the loop from continuously running
}
