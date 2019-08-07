

project(shared-lib)


add_library( ${PROJECT_NAME} 
	SHARED 

	logging/logger.cpp
	)

add_definitions(-DEXPMODULE)

