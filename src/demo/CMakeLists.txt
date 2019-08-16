
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc)
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/include)


link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

project(demo)

add_executable(${PROJECT_NAME} main.cpp main.h)

target_link_libraries(${PROJECT_NAME} matrix-ioc)

