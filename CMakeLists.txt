cmake_minimum_required(VERSION 3.16)
project(SFML_Pacman LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(main
        src/main.cpp
        src/Game.cpp
        src/Game.hpp
        src/State.cpp
        src/State.hpp
        src/StateMachine.cpp
        src/StateMachine.hpp
        src/AssetManager.cpp
        src/AssetManager.hpp
        src/InputManager.cpp
        src/InputManager.hpp
        src/Stopwatch.cpp
        src/Stopwatch.hpp
        src/DEFINITIONS.hpp
        src/states/SplashState.cpp
        src/states/SplashState.hpp
        src/COLORS.hpp
        src/STATE_LIST.hpp
)
target_link_libraries(main PRIVATE sfml-graphics sfml-audio)
target_compile_features(main PRIVATE cxx_std_17)

if (WIN32)
    add_custom_command(
            TARGET main
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
            VERBATIM)
endif ()