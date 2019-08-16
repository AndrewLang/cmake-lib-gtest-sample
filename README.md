
# cmake-lib-gtest-sample
This is a sample/starter project for using CMake, shared library and Google Test together, the main demo app uses shared library. 

This project is built on Windows with Visual Studio, but it should support other platform as well. 


## Directory structure
The directory structure is a classic app folder structure, reusable codde is in a shared library, main app reference the shared library, unit tests are created for the shared library code.

```
cmake-lib-gtest-sample
	- .gitignore				// git ignore file
	- CMakeLists.txt			// root CMakeLists file
	- README.md
	- src					// source code folder
		- CMakeLists.txt		// CMakeLists file for source code
		- demo				// demo app, main application folder
			- CMakeLists.txt	// CMakeLists file for demo app
			- main.h
			- main.cpp
		- matrix-ioc			// shared library folder
			- CMakeLists.txt	// CMakeLists file for shared library
			- targetver.h
			- stdafx.h
			- stdafx.cpp
			- logging		// logging folder
				- logger.h
				- logger.cpp 
	- tests					// unit tests
		- CMakeLists.txt		// CMakeLists file for unit tests
		- CMakeLists.txt.in		// 
		- matrix-ioc-tests
			- CMakeLists.txt
			- pch.h
			- pch.cpp
			- main.h
			- main.cpp		// main file to start the unit tests
			- tests.cpp		// cpp file has unit tests
```

## Shared library
Shared library is compiled to dll which can be reused in the solution or by other apps, a simple logger is defined in this library, demo app uses this logger output messages to console window.

This library is configured "SHARED" as following.

```
add_library( ${PROJECT_NAME} 
	SHARED 

	logging/logger.cpp
	)

```

## Demo app
Demo is a console app which demos how to use the shared library above. 

CMake configuration
```
add_executable(${PROJECT_NAME} main.cpp main.h)

# Link to shared library
target_link_libraries(${PROJECT_NAME} matrix-ioc)
```

## Unit test

To use Google test to create unit tests for the shared library, there are a few steps to do

* install google test with CMake from github
* configure google test build as dynamic library
* link to google test
* link to shared library

```

include(ExternalProject)
ExternalProject_Add(googletest  
  URL				https://github.com/google/googletest/archive/release-1.8.1.zip
  SOURCE_DIR        "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
  BINARY_DIR        "${CMAKE_CURRENT_BINARY_DIR}/googletest-build"
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
)

configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

```


