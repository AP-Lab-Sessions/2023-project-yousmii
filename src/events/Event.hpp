#ifndef EVENT_HPP
#define EVENT_HPP
#include "EVENT_TYPES.hpp"

namespace Events {

class Event {
public:
    Event() = default;
    virtual ~Event() = default;

private:

};

class EntityMoveEvent : public Event {
public:
    EntityMoveEvent();
};

} // Logic

#endif //EVENT_HPP
