
include_directories(${CMAKE_SOURCE_DIR}/src/shared-lib/logging)

project(shared-lib-tests)

add_executable (${PROJECT_NAME} 
	main.cpp 	
	tests.cpp
	)

# Include sub-projects.

target_link_libraries(${PROJECT_NAME} gtest_main)
target_link_libraries(${PROJECT_NAME} shared-lib)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
