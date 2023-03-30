set(HEADER_FILES
	src/AEngineUtil.h
	src/AEngineApp.h
	src/GameWindow.h
	src/WindowImplementation.h
	src/GLFWcode/GLFWimplementation.h
)

set(SOURCE_FILES
	src/AEngineApp.cpp
	src/GameWindow.cpp
	src/GLFWcode/GLFWimplementation.cpp
)

add_library(AEngine SHARED ${HEADER_FILES} ${SOURCE_FILES})

include_directories(src)

target_precompile_headers(AEngine PRIVATE src/pch.h)

target_link_libraries(AEngine glfw)

add_definitions(-DAENGINE_LIB)
add_definitions(-DAENGINE_GLFW)