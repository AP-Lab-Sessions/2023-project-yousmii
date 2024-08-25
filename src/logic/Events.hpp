#ifndef EVENTS_HPP
#define EVENTS_HPP
#include <queue>

/// @brief The EventType enum represents the different types of events that can occur in the game. This is used to
/// communicate between the Logic and View.
enum EventType {
    pacmanPositionChange,
    pacmanDirectionChange,
    blinkyPositionChange,
    pinkyPositionChange,
    inkyPositionChange,
    clydePositionChange,
    blinkyStateChange,
    pinkyStateChange,
    inkyStateChange,
    clydeStateChange,
    coinEaten,
    powerUpEaten,
    ghostEaten
};

/// @brief The Event struct represents an event that can occur in the game. It contains the type of event and 2 integers
/// Either to pass a position or any enum value such as the direction or the state of a ghost
struct Event {
    EventType type;
    int x;
    int y;
    explicit Event(EventType type, int x, int y) : type(type), x(x), y(y) {}
};

typedef std::queue<Event> Events;

#endif // EVENTS_HPP
