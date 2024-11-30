#ifndef QUEUE_H_
#define QUEUE_H_
#endif

#include <Arduino.h>

class Location
{
private:
    uint8_t m_x;
    uint8_t m_y;
    uint8_t m_z;
    Location *next;

public:
    Location(uint8_t _x, uint8_t _y, uint8_t _z);
    ~Location();
    Location *get_next() const;
    uint8_t get_x() const;
    void set_x(uint8_t x);
    uint8_t get_y() const;
    void set_y(uint8_t y);
    uint8_t get_z() const;
    void set_z(uint8_t z);
    void set_next(Location &l);
};

class Queue
{
private:
    Location *start;
    Location *end;
    int size;

public:
    Queue();
    Queue(uint8_t start_x, uint8_t start_y, uint8_t start_z);
    ~Queue();
    bool empty();
    Location *pop();
    void push(Location &l);
};