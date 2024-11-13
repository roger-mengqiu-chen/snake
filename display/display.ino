#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>

#define TFT_CS        10
#define TFT_RST        9 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC         8


Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);


float p = 3.1415926;

void setup(void) {
  Serial.begin(9600);

  // using a 1.44" TFT:
  tft.initR(INITR_144GREENTAB); // Init ST7735R chip, green tab
  tft.setRotation(3);
  tft.fillScreen(0);

  // tft print function!
  tft.fillRect(tft.width()/2, tft.height()/2, 5, 5, 0xffff);
  delay(4000);

}

void loop() {

}
