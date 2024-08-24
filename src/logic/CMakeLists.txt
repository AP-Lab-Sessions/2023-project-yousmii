set(LOGIC_SRC
        World.cpp
        World.hpp
        Camera.cpp
        Camera.hpp

        level/Level.cpp
        level/Level.hpp
        level/Tile.cpp
        level/Tile.hpp

        entities/Pacman.cpp
        entities/Pacman.hpp
        entities/Ghost.cpp
        entities/Ghost.hpp
        entities/Fruit.hpp
        entities/Wall.hpp
        entities/Coin.hpp
        entities/Entity.hpp

        entities/states/GhostState.hpp
        entities/states/ghost/SetupState.cpp
        entities/states/ghost/SetupState.hpp
        entities/states/ghost/ChasingState.cpp
        entities/states/ghost/ChasingState.hpp

        entities/states/PacmanState.hpp
        entities/states/pacman/MovingState.cpp
        entities/states/pacman/MovingState.hpp
        entities/states/pacman/PausedState.cpp
        entities/states/pacman/PausedState.hpp

        entities/states/StateManager.hpp
        entities/states/PacmanStateManager.hpp
        entities/states/GhostStateManager.hpp
        entities/EntityList.hpp
        level/Score.cpp
        level/Score.hpp
        Simulator.cpp
        Simulator.hpp
        Events.hpp
)
add_library(CPPacmanLogic ${LOGIC_SRC})