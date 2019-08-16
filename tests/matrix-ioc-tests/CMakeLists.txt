
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/Include)

project(matrix-ioc-tests)

set (HeaderFiles 
	pch.h
	main.h
)

set (SourceFiles 
	pch.cpp
	main.cpp
	tests.cpp
	tests/TextFormatterTests.cpp
)


add_executable (${PROJECT_NAME} ${HeaderFiles} ${SourceFiles})

# Include sub-projects.

target_link_libraries(${PROJECT_NAME} PRIVATE gtest_main matrix-ioc)


add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
