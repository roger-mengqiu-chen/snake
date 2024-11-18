#include "queue.h"

Location::Location(uint8_t x, uint8_t y) : m_x(x), m_y(y), next(NULL) {}

Location::~Location() {}

Location* Location::get_next() {
  return next;
}

void Location::set_next(Location& l) {
  next = &l;
}

Queue::Queue(uint8_t start_x, uint8_t start_y) {
  start = new Location(start_x, start_y);
  end = start;
  size = 1;
}

Queue::~Queue() {
  while (start != NULL) {
    Location* tmp = start;
    start = start->get_next();
    delete tmp;
  }
  end = NULL;
  size = 0;
}

bool Queue::empty() {
  return size == 0;
}

Location* Queue::pop() {
  if (size > 0) {
    Location* res = start;
    start = start->get_next();
    --size;
    if (size == 0) {
      end = NULL;
    }
    return res;
  }
  else {
    return NULL;
  }
}

void Queue::push(Location& l) {
  if (size == 0) {
    start = &l;
    end = &l;
  }
  else {
    end->set_next(l);
    end = &l;
  }
  ++size;
}
