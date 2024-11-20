#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>
#include "game_elements.h"

#define TFT_CS        10
#define TFT_RST        9 
#define TFT_DC         8


Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

Snake snake = Snake();
bool run_game = 1;


void setup(void) {
    Serial.begin(9600);
    pinMode(LEFT, INPUT);
    pinMode(RIGHT, INPUT);
    pinMode(UP, INPUT);
    pinMode(DOWN, INPUT);

    // using a 1.44" TFT:
    tft.initR(INITR_144GREENTAB); // Init ST7735R chip, green tab
    tft.setRotation(3);
    tft.fillScreen(0);
    snake = Snake(&tft);
    delay(1000);

}

void loop() {

    if (digitalRead(LEFT) == HIGH) {
        Serial.println("LEFT");
        snake.turn(LEFT);
    }

    if (digitalRead(RIGHT) == HIGH) {
        Serial.println("RIGHT");
        // snake.turn(RIGHT);
    }

    if (digitalRead(UP) == HIGH) {
        Serial.println("UP");
        // snake.turn(UP);
    }

    if (digitalRead(DOWN) == HIGH) {
        Serial.println("DOWN");
        // snake.turn(DOWN);
    }

    snake.h_move();

    delay(100);
}
