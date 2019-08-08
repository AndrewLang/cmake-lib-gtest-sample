

project(shared-lib)

set (HeaderFiles 
	targetver.h
	stdafx.h

	logging/logger.h
)

set (SourceFiles 
	stdafx.cpp

	logging/logger.cpp
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