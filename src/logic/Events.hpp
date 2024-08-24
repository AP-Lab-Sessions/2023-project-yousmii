#ifndef EVENTS_HPP
#define EVENTS_HPP
#include <stack>

enum EventType {
    pacmanPositionChange,
    blinkyPositionChange,
    pinkyPositionChange,
    inkyPositionChange,
    clydePositionChange,
    coinEaten,
    powerUpEaten,
    ghostEaten
};

struct Event {
    EventType type;
    int x;
    int y;
    explicit Event(EventType type, int x, int y) : type(type), x(x), y(y) {}
};

typedef std::stack<Event> Events;

#endif //EVENTS_HPP
