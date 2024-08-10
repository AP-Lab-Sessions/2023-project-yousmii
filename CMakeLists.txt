cmake_minimum_required(VERSION 3.16)
project(CPPacman LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
SET(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_STANDARD 17)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

add_subdirectory(src)
install(TARGETS CPPacman DESTINATION bin)
