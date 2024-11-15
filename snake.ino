#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>

#define TFT_CS        10
#define TFT_RST        9 
#define TFT_DC         8
#define LEFT           5
#define RIGHT          6
#define UP             7
#define DOWN           4
#define SNAKE_SIZE     4
#define STEP           2


Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

int16_t start_x = 0;
int16_t start_y = 0;
int16_t direction = 0;


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
    start_x = tft.width() / 2;
    start_y = tft.height() / 2;
    tft.fillRect(start_x, start_y, SNAKE_SIZE, SNAKE_SIZE, 0xffff);
    delay(4000);

}

void loop() {
    if (digitalRead(LEFT) == HIGH) {
        direction = LEFT;
    }

    if (digitalRead(RIGHT) == HIGH) {
        direction = RIGHT;
    }

    if (digitalRead(UP) == HIGH) {
        direction = UP;
    }
    if (digitalRead(DOWN) == HIGH) {
        direction = DOWN;
    }

    if (direction == LEFT) {
        tft.fillRect(start_x + STEP, start_y, STEP, SNAKE_SIZE, 0x0);
        start_x -= STEP;
        tft.fillRect(start_x, start_y, SNAKE_SIZE, SNAKE_SIZE, 0xffff);
    }
    
    if (direction == RIGHT) {
        tft.fillRect(start_x, start_y, STEP, SNAKE_SIZE, 0x0);
        start_x += STEP;
        tft.fillRect(start_x, start_y, SNAKE_SIZE, SNAKE_SIZE, 0xffff);
    }

    if (direction == UP) {
        tft.fillRect(start_x, start_y + STEP, SNAKE_SIZE, STEP, 0x0);
        start_y -= STEP;
        tft.fillRect(start_x, start_y, SNAKE_SIZE, SNAKE_SIZE, 0xffff);
    }

    if (direction == DOWN) {
        tft.fillRect(start_x, start_y, SNAKE_SIZE, STEP, 0x0);
        start_y += STEP;
        tft.fillRect(start_x, start_y, SNAKE_SIZE, SNAKE_SIZE, 0xffff);
    }

    delay(100);
}
