set(HEADER_FILES
	src/AEngineUtil.h
	src/AEngineApp.h
)

set(SOURCE_FILES
	src/AEngineApp.cpp
)

add_library(AEngine SHARED ${HEADER_FILES} ${SOURCE_FILES})

add_definitions(-DAENGINE_LIB)