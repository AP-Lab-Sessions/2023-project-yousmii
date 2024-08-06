cmake_minimum_required(VERSION 3.16)
project(CPPacman LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
SET(CMAKE_CXX_FLAGS "-Wall")
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(CPPacman
        src/main.cpp
        src/view/Game.cpp
        src/view/Game.hpp

        src/view/AssetManager.cpp
        src/view/AssetManager.hpp
        src/view/InputManager.cpp
        src/view/InputManager.hpp
        src/logic/Stopwatch.cpp
        src/logic/Stopwatch.hpp

        src/view/DEFINITIONS.hpp
        src/view/COLORS.hpp

        src/view/STATE_LIST.hpp
        src/view/State.hpp
        src/view/StateMachine.cpp
        src/view/StateMachine.hpp
        src/view/states/MainMenuState.cpp
        src/view/states/MainMenuState.hpp
        src/view/states/GameState.cpp
        src/view/states/GameState.hpp
        src/view/states/PauseState.cpp
        src/view/states/PauseState.hpp

        src/view/EntityFactory.cpp
        src/view/EntityFactory.hpp
        src/view/entities/Character.cpp
        src/view/entities/Character.hpp
        src/view/entities/Collectable.cpp
        src/view/entities/Collectable.hpp
        src/view/entities/Pacman.cpp
        src/view/entities/Pacman.hpp
        src/view/entities/Ghost.cpp
        src/view/entities/Ghost.hpp
)
target_link_libraries(CPPacman PRIVATE sfml-graphics sfml-audio)
target_compile_features(CPPacman PRIVATE cxx_std_17)

if (WIN32)
    add_custom_command(
            TARGET CPPacman
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:CPPacman>
            VERBATIM)
endif ()