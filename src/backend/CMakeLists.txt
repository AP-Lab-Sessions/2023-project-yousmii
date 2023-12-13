file(GLOB_RECURSE BACKEND_SOURCES "*.cpp")
add_library(backend ${BACKEND_SOURCES})

set_target_properties(backend PROPERTIES
    CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/backend)