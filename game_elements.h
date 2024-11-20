#ifndef GAME_ELEMENTS_H_
#define GAME_ELEMENTS_H_
#endif

#include <cstdint>
#include <Adafruit_ST7735.h>
#include "queue.h"


class Snake {
private:
    Location& head;
    Location& tail;
    uint8_t head_dir;
    uint8_t tail_dir;
    uint16_t len;
    Queue& queue;
    Adafruit_ST7735& m_tft;
public:
    Snake(Adafruit_ST7735& tft, uint8_t start_x, uint8_t start_y);
    ~Snake();
    void h_move();
    void t_move();
    void turn(uint8_t direction);
    void eat();
    bool is_dead();
};