add_subdirectory(frontend)
add_subdirectory(backend)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE frontend backend)