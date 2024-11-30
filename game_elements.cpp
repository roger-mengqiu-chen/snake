#include "game_elements.h"

Snake::Snake()
{
    head = Location(0, 0, 0);
    tail = Location(0, 0, 0);
    len = 1;
    head_dir = 0;
    tail_dir = 0;
    queue = new Queue();
}

Snake::Snake(Adafruit_ST7735 *tft)
{
    Serial.println("Snake constructor");
    m_tft = tft;
    head = Location(m_tft->width() / 2, m_tft->height() / 2, 0);
    tail = Location(m_tft->width() / 2, m_tft->height() / 2, 0);
    len = 1;
    head_dir = 0;
    tail_dir = 0;
    queue = new Queue();
    Serial.print("color: ");
    Serial.print(head.get_x());
    Serial.print(" ");
    Serial.println(head.get_y());
    tft->fillRect(head.get_x(), head.get_y(), SNAKE_SIZE, SNAKE_SIZE, SNAKE_COLOR);
}

Snake::Snake(const Snake &s)
{
    head = s.head;
    tail = s.tail;
    len = s.len;
    head_dir = s.head_dir;
    tail_dir = s.tail_dir;
    queue = s.queue;
}

Snake &Snake::operator=(const Snake &s)
{
    delete queue;
    head = s.head;
    tail = s.tail;
    len = s.len;
    head_dir = s.head_dir;
    tail_dir = s.tail_dir;
    queue = s.queue;

    return *this;
}

Snake::~Snake()
{
    delete &head;
    delete &tail;
    delete queue;
    delete &cturn_pt;
}

void Snake::turn(uint8_t direction)
{
    Serial.println(head_dir);
    if (head_dir == direction)
        return;
    Serial.println("turn");
    head_dir = direction;
    Location turn_pt = Location(head.get_x(), head.get_y(), direction);
    queue->push(turn_pt);
}

void Snake::h_move()
{
    if (head_dir == LEFT)
    {
        Serial.print("x: ");
        Serial.println(head.get_x());
        head.set_x(head.get_x() - STEP);
        m_tft->fillRect(head.get_x() - STEP, head.get_y(), STEP, SNAKE_SIZE, SNAKE_COLOR);
    }
    else if (head_dir == RIGHT)
    {
        head.set_x(head.get_x() + STEP);
        m_tft->fillRect(head.get_x() + STEP, head.get_y(), STEP, SNAKE_SIZE, SNAKE_COLOR);
    }
    else if (head_dir == UP)
    {
        head.set_y(head.get_y() - STEP);
        m_tft->fillRect(head.get_x(), head.get_y() - STEP, STEP, SNAKE_SIZE, SNAKE_COLOR);
    }
    else if (head_dir == DOWN)
    {
        head.set_y(head.get_y() + STEP);
        m_tft->fillRect(head.get_x(), head.get_y() + STEP, STEP, SNAKE_SIZE, SNAKE_COLOR);
    }
}