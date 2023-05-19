#include "pch.h"
#include "GLFWimplementation.h"

namespace AEngine
{
	void GLFWimplementation::CreateWindow(int width, int height, const std::string& windowName)
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		mWindow = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
		glfwMakeContextCurrent(mWindow);
	}
	void GLFWimplementation::CreateWindow(int width, int height, const std::string&& windowName)
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		mWindow = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
		glfwMakeContextCurrent(mWindow);
	}

	void GLFWimplementation::SwapBuffers()
	{
		glfwSwapBuffers(mWindow);
	}

	void GLFWimplementation::PollEvents()
	{
		glfwPollEvents();
	}

	int GLFWimplementation::GetWidth() const
	{
		int height{ 0 }, width{ 0 };
		glfwGetWindowSize(mWindow, &width, &height);
		return width;
	}

	int GLFWimplementation::GetHeight() const
	{
		int height{ 0 }, width{ 0 };
		glfwGetWindowSize(mWindow, &width, &height);
		return height;
	}

}