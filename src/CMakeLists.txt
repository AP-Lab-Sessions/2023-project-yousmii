add_subdirectory(logic)
add_subdirectory(singletons)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

find_package(SFML COMPONENTS graphics audio REQUIRED)

set(VIEW_SRC
        main.cpp
        view/Game.cpp
        view/Game.hpp

        view/AssetManager.cpp
        view/AssetManager.hpp
        view/InputManager.cpp
        view/InputManager.hpp
        singletons/Stopwatch.cpp
        singletons/Stopwatch.hpp

        DEFINITIONS.hpp
        view/COLORS.hpp

        view/STATE_LIST.hpp
        view/State.hpp
        view/StateMachine.cpp
        view/StateMachine.hpp
        view/states/MainMenuState.cpp
        view/states/MainMenuState.hpp
        view/states/GameState.cpp
        view/states/GameState.hpp
        view/states/PauseState.cpp
        view/states/PauseState.hpp

        view/EntityFactory.cpp
        view/EntityFactory.hpp
        view/entities/Character.cpp
        view/entities/Character.hpp
        view/entities/Collectable.cpp
        view/entities/Collectable.hpp
        view/entities/Pacman.cpp
        view/entities/Pacman.hpp
        view/entities/Ghost.cpp
        view/entities/Ghost.hpp
        SETTINGS.hpp
        view/entities/Wall.cpp
        view/entities/Wall.hpp
)

add_executable(CPPacman ${VIEW_SRC})
target_link_libraries(CPPacman PRIVATE CPPacmanLogic Singletons sfml-graphics sfml-audio)
target_include_directories(CPPacman PUBLIC Logic ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(CPPacman PRIVATE cxx_std_17)

if (WIN32)
    add_custom_command(
            TARGET CPPacman
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:CPPacman>
            VERBATIM)
endif ()