#include "queue.h"

Location::Location(short x, short y, short z) : m_x(x), m_y(y), m_z(z), next(nullptr) {}

Location::~Location() {}

short Location::get_x() {
  return m_x;
}

void Location::set_x(short x) {
  m_x = x;
}

short Location::get_y() {
  return m_y;
}

void Location::set_y(short y) {
  m_y = y;
}

short Location::get_z() {
  return m_z;
}

void Location::set_z(short z) {
  m_z = z;
}

Location* Location::get_next() {
  return next;
}

void Location::set_next(Location& l) {
  next = &l;
}

Queue::Queue() : start(nullptr), end(nullptr), size(0) {}

Queue::Queue(short start_x, short start_y, short start_z) {
  start = new Location(start_x, start_y, start_z);
  end = start;
  size = 1;
}

Queue::~Queue() {
  while (start != nullptr) {
    Location* tmp = start;
    start = start->get_next();
    delete tmp;
  }
  end = nullptr;
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
      end = nullptr;
    }
    return res;
  }
  else {
    return nullptr;
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
