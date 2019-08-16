include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/include)

project(matrix-ioc)


set (HeaderFiles 
	include/targetver.h
	include/stdafx.h

	include/logging/logger.h

	include/common/TextFormatter.h
	include/common/StringExtensions.h
)

set (SourceFiles 
	src/stdafx.cpp

	src/logging/logger.cpp

	src/common/TextFormatter.cpp
	src/common/StringExtensions.cpp
)

add_library( ${PROJECT_NAME} SHARED ${HeaderFiles} ${SourceFiles} )

add_definitions(-DEXPMODULE)

#[[
if(MSVC)
	 get_property(USE_PRECOMPILED_HEADERS GLOBAL PROPERTY USE_PRECOMPILED_HEADERS)
	 if (${USE_PRECOMPILED_HEADERS})
		add_precompiled_header(${PROJECT_NAME} pch.h SOURCE_CXX pch.cpp FORCEINCLUDE)
	 endif()
endif()
]]