#ifndef GAME_ELEMENTS_H_
#define GAME_ELEMENTS_H_
#endif

#define LEFT           5
#define RIGHT          6
#define UP             7
#define DOWN           4
#define SNAKE_SIZE     4
#define STEP           2
#define BACKGROUND     0x0
#define SNAKE_COLOR    0xffff

#include <Adafruit_ST7735.h>
#include "queue.h"


class Snake {
private:
    Location& head;
    Location& tail;
    Location& cturn_pt;
    uint8_t head_dir;
    uint8_t tail_dir;
    uint8_t len;
    Queue* queue;
    Adafruit_ST7735* m_tft;
public:
    Snake();
    Snake(Adafruit_ST7735* tft);
    Snake(const Snake& s);
    Snake& operator=(const Snake& s);
    ~Snake();
    void turn(uint8_t direction);
    void h_move();
    void t_move();
    void eat();
    bool is_dead();
};
