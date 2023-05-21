set(HEADER_FILES
	src/AEngineUtil.h
	src/AEngineApp.h
	src/GameWindow.h
	src/WindowImplementation.h
	src/GLFWcode/GLFWimplementation.h
	src/Renderer.h
	src/RendererTypes.h
	src/ImplRenderer.h
	src/OpenGLCode/OpenGLRenderer.h
	src/Shader.h
	src/ImplShader.h
	src/OpenGLCode/OpenGLShader.h
	src/Image.h
	src/ImplImage.h
	src/OpenGLCode/OpenGLImage.h
	src/Unit.h
	src/RendererTypes.h
	src/AEngineEvents.h
	src/AEngineKeys.h

)

set(SOURCE_FILES
	src/AEngineApp.cpp
	src/GameWindow.cpp
	src/GLFWcode/GLFWimplementation.cpp
	src/Renderer.cpp
	src/OpenGLCode/OpenGLRenderer.cpp
	src/Shader.cpp
	src/OpenGLCode/OpenGLShader.cpp
	src/Image.cpp
	src/OpenGLCode/OpenGLImage.cpp
	src/Unit.cpp
	src/AEngineEvents.cpp
)

add_library(AEngine SHARED ${HEADER_FILES} ${SOURCE_FILES})

include_directories(src)
include_directories(../glad/include)
include_directories(../stbi)
include_directories(../glfw/include)


target_precompile_headers(AEngine PRIVATE src/pch.h)

target_link_libraries(AEngine glfw glad stbi)

add_definitions(-DAENGINE_LIB)
add_definitions(-DAENGINE_GLFW)
add_definitions(-DAENGINE_OPENGL)
add_definitions(-DAENGINE_DEBUG=2)
add_definitions(-DAENGINE_WINDOWS)
