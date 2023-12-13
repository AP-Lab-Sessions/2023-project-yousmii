cmake_minimum_required(VERSION 3.16)
project(CPPacman LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
SET(CMAKE_CXX_FLAGS "-Wall")

add_subdirectory(src)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/installed" CACHE PATH "default install path" FORCE)
endif()