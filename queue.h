#ifndef QUEUE_H_
#define QUEUE_H_
#endif

#include <cstdint>
class Location {
private:
  uint8_t m_x;
  uint8_t m_y;
  Location* next;
public:
  Location(uint8_t _x, uint8_t _y);
  ~Location();
  Location* get_next();
  void set_next(Location& l);
};


class Queue {
private:
  Location* start;
  Location* end;
  uint8_t size;
public:
  Queue(uint8_t start_x, uint8_t start_y);
  ~Queue();
  bool empty();
  Location* pop();
  void push(Location& l);
};