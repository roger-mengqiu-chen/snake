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
    tail = Location(m_tft->width() / 2 + SNAKE_SIZE, m_tft->height() / 2, 0);
    len = 1;
    head_dir = 0;
    tail_dir = 0;
    queue = new Queue();
    tft->fillRect(head.get_x(), head.get_y(), SNAKE_SIZE, SNAKE_SIZE, SNAKE_COLOR);
    Serial.print("head starts at: ");
    Serial.print(head.get_x());
    Serial.print(" ");
    Serial.println(head.get_y());
    Serial.print("tail starts at: ");
    Serial.print(tail.get_x());
    Serial.print(" ");
    Serial.println(tail.get_y());
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
    if (queue->empty()) 
    {
        tail_dir = direction;
    }
    queue->push(turn_pt);
}

void Snake::h_move()
{
    if (head_dir == LEFT)
    {
        head.set_x(head.get_x() - STEP);
        m_tft->fillRect(head.get_x(), head.get_y(), SNAKE_SIZE, SNAKE_SIZE, SNAKE_COLOR);
    }
    else if (head_dir == RIGHT)
    {
        head.set_x(head.get_x() + STEP);
        m_tft->fillRect(head.get_x(), head.get_y(), SNAKE_SIZE, SNAKE_SIZE, SNAKE_COLOR);
    }
    else if (head_dir == UP)
    {
        head.set_y(head.get_y() - STEP);
        m_tft->fillRect(head.get_x(), head.get_y(), SNAKE_SIZE, SNAKE_SIZE, SNAKE_COLOR);
    }
    else if (head_dir == DOWN)
    {
        head.set_y(head.get_y() + STEP);
        m_tft->fillRect(head.get_x(), head.get_y(), SNAKE_SIZE, SNAKE_SIZE, SNAKE_COLOR);
    }
}

void Snake::t_move() 
{
    Location* next_location = queue->top();

    Serial.print("next tail loc: ");
    Serial.print(next_location->get_x());
    Serial.print(" ");
    Serial.println(next_location->get_y());

    if (nullptr != next_location && next_location->get_x() == tail.get_x() && next_location->get_x() == tail.get_x())
    {
        Serial.print("next location: ");
        Serial.print(next_location->get_x());
        Serial.print(" ");
        Serial.print(next_location->get_y());
        Serial.print(" ");
        tail_dir = next_location->get_z();
        Serial.print(tail_dir);
        queue->pop();
    }

    Serial.print("tail dir: ");
    Serial.println(tail_dir);

    if (tail_dir == LEFT)
    {
        Serial.println("tail moving left");
        tail.set_x(tail.get_x() - STEP);
        Serial.print("tail x: ");
        Serial.print(tail.get_x());
        Serial.print(" tail y: ");
        Serial.print(tail.get_y());
        Serial.println();
        m_tft->fillRect(tail.get_x(), tail.get_y(), STEP, SNAKE_SIZE, BACKGROUND);
    }

    if (tail_dir == RIGHT) {
        Serial.println("tail moving right");
        tail.set_x(tail.get_x() + STEP);
        m_tft->fillRect(tail.get_x(), tail.get_y(), -STEP, SNAKE_SIZE, BACKGROUND);
    }
}
