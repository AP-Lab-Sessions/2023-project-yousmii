
#ifndef EVENT_TYPES_HPP
#define EVENT_TYPES_HPP

namespace Events {
enum class EventType {
    PacmanMove,
    PacmanDie,
    PacmanPowerUp,
    PacmanPowerDown,
    PacmanSlip,
    CoinCollected,
    PowerUpCollected
};
}

#endif //EVENT_TYPES_HPP
