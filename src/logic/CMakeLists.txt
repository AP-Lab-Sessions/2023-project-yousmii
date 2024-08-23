set(LOGIC_SRC
        World.cpp
        World.hpp
        Camera.cpp
        Camera.hpp

        ../events/Event.cpp
        ../events/Event.hpp

        level/Level.cpp
        level/Level.hpp
        level/Tile.cpp
        level/Tile.hpp

        entities/Pacman.cpp
        entities/Pacman.hpp
        entities/Ghost.cpp
        entities/Ghost.hpp
        entities/Fruit.hpp
        entities/Wall.cpp
        entities/Wall.hpp
        entities/Coin.hpp
        entities/Entity.hpp

        entities/states/GhostState.hpp
        entities/states/ghost/SetupState.cpp
        entities/states/ghost/SetupState.hpp
        entities/states/ghost/ChasingState.cpp
        entities/states/ghost/ChasingState.hpp
        entities/states/ghost/FrightenedState.cpp
        entities/states/ghost/FrightenedState.hpp
        entities/states/ghost/RespawningState.cpp
        entities/states/ghost/RespawningState.hpp

        entities/states/PacmanState.hpp
        entities/states/pacman/MovingState.cpp
        entities/states/pacman/MovingState.hpp
        entities/states/pacman/DeadState.cpp
        entities/states/pacman/DeadState.hpp
        entities/states/pacman/PowerUpState.cpp
        entities/states/pacman/PowerUpState.hpp
        entities/states/pacman/PausedState.cpp
        entities/states/pacman/PausedState.hpp

        entities/states/StateManager.hpp
        entities/states/PacmanStateManager.cpp
        entities/states/PacmanStateManager.hpp
        entities/states/GhostStateManager.cpp
        entities/states/GhostStateManager.hpp
        entities/EntityList.hpp
        entities/states/Statemanager.cpp
)
add_library(CPPacmanLogic ${LOGIC_SRC})