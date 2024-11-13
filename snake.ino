#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>

#define TFT_CS        10
#define TFT_RST        9 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC         8
#define STEP           2
#define SNAKE_SIZE     4


Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

int16_t start_x = 0;
int16_t start_y = 0;

void setup(void) {
  Serial.begin(9600);

  // using a 1.44" TFT:
  tft.initR(INITR_144GREENTAB); // Init ST7735R chip, green tab
  tft.setRotation(3);
  tft.fillScreen(0);
  start_x = tft.width() / 2;
  start_y = tft.height() / 2;
  tft.fillRect(start_x, start_y, SNAKE_SIZE, SNAKE_SIZE, 0xffff);
  delay(4000);

}

void loop() {
  tft.fillRect(start_x + STEP, start_y, STEP, SNAKE_SIZE, 0x0);
  start_x -= STEP;
  tft.fillRect(start_x, start_y, SNAKE_SIZE, SNAKE_SIZE, 0xffff);
  delay(500);
}
