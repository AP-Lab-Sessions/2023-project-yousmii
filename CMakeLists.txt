# Source: https://github.com/SFML/cmake-sfml-project/blob/master/CMakeLists.txt

cmake_minimum_required(VERSION 3.16)
project(CPPacman LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
SET(CMAKE_CXX_FLAGS "-Wall")
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.5.x)
FetchContent_MakeAvailable(SFML)

add_subdirectory(src)
target_link_libraries(CPPacman PRIVATE sfml-graphics sfml-audio)
target_compile_features(CPPacman PRIVATE cxx_std_17)

install(TARGETS CPPacman DESTINATION bin)

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/installed" CACHE PATH "default install path" FORCE)
endif()