add_subdirectory(states)

file(GLOB_RECURSE FRONTEND_SRC "*.cpp")
add_library(frontend ${FRONTEND_SRC})

set_target_properties(frontend PROPERTIES
    CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/frontend)

target_link_libraries(frontend PRIVATE sfml-graphics sfml-audio states)