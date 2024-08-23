set(EVENTS_SRC
        EVENT_TYPES.hpp
        Event.cpp
        Event.hpp
        EntityMoveEvent.cpp
        EntityMoveEvent.hpp
)

add_library(CPPacmanEvents ${EVENTS_SRC})
