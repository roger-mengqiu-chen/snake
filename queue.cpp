#include "queue.h"

Location::Location(uint8_t x, uint8_t y, uint8_t z) : m_x(x), m_y(y), m_z(z), next(nullptr) {}

Location::~Location() {}

uint8_t Location::get_x() const
{
    return m_x;
}

void Location::set_x(uint8_t x)
{
    m_x = x;
}

uint8_t Location::get_y() const
{
    return m_y;
}

void Location::set_y(uint8_t y)
{
    m_y = y;
}

uint8_t Location::get_z() const
{
    return m_z;
}

void Location::set_z(uint8_t z)
{
    m_z = z;
}

Location *Location::get_next() const
{
    return next;
}

void Location::set_next(Location &l)
{
    next = &l;
}

Queue::Queue() : start(nullptr), end(nullptr), size(0) {}

Queue::Queue(uint8_t start_x, uint8_t start_y, uint8_t start_z)
{
    start = new Location(start_x, start_y, start_z);
    end = start;
    size = 1;
}

Queue::~Queue()
{
    Serial.println("deleting queue");
    while (start != nullptr)
    {
        Location *tmp = start;
        start = start->get_next();
        delete tmp;
    }
    end = nullptr;
    size = 0;
    Serial.println("queue deleted");
}

bool Queue::empty()
{
    return size == 0;
}

Location *Queue::pop()
{
    if (size > 0)
    {
        Location *res = start;
        start = start->get_next();
        --size;
        if (size == 0)
        {
            end = nullptr;
        }
        return res;
    }
    else
    {
        return nullptr;
    }
}

Location *Queue::top() 
{
    if (size > 0)
    {
        return start;
    }
    else
    {
        return nullptr;
    }
}

void Queue::push(Location &l)
{
    if (size == 0)
    {
        start = &l;
        end = &l;
    }
    else
    {
        end->set_next(l);
        end = &l;
    }
    ++size;
}
