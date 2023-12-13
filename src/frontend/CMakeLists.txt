file(GLOB_RECURSE FRONTEND_SRC "*.cpp")
add_library(frontend ${FRONTEND_SRC})

set_target_properties(frontend PROPERTIES
    CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/frontend)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.5.x)
FetchContent_MakeAvailable(SFML)

target_link_libraries(frontend PRIVATE sfml-graphics sfml-audio)
