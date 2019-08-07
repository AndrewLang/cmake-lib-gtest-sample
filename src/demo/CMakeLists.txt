
include_directories(${CMAKE_SOURCE_DIR}/src/shared-lib)
include_directories(${CMAKE_SOURCE_DIR}/src/shared-lib/logging)

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

project(demo)

add_executable(${PROJECT_NAME} main.cpp main.h)

target_link_libraries(${PROJECT_NAME} shared-lib)

