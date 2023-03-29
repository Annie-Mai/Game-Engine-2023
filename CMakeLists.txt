cmake_minimum_required(VERSION 3.24)

project(Spring23)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
	add_definitions(-DAENGINE_WINDOWS)
elseif(APPLE)
	add_definitions(-DAENGINE_MACOS)
else()
	add_definitions(-DAENGINE_LINUX)
endif()

add_subdirectory(AEngine)
add_subdirectory(S23_Game)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT S23_Game)