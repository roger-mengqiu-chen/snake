#ifndef QUEUE_H_
#define QUEUE_H_
#endif


class Location {
private:
  short m_x;
  short m_y;
  short m_z;
  Location* next;
public:
  Location(short _x, short _y, short _z);
  ~Location();
  Location* get_next();
  short get_x();
  void set_x(short x);
  short get_y();
  void set_y(short y);
  short get_z();
  void set_z(short z);
  void set_next(Location& l);
};


class Queue {
private:
  Location* start;
  Location* end;
  int size;
public:
  Queue(short start_x, short start_y, short start_z);
  ~Queue();
  bool empty();
  Location* pop();
  void push(Location& l);
};