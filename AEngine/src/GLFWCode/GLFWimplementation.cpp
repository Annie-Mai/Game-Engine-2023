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

		glfwSetWindowUserPointer(mWindow, &mCallbacks);

		glfwSetKeyCallback(mWindow, [](GLFWwindow* window, int keycode, int scancode, int action, int mods) {
			if (action == GLFW_PRESS)
			{
				Callbacks* callbacks{ (Callbacks*)glfwGetWindowUserPointer(window) };

				KeyPressed e{ keycode };
				callbacks->keyPressedFunc(e);
			}
			else if (action == GLFW_RELEASE)
			{
				Callbacks* callbacks{ (Callbacks*)glfwGetWindowUserPointer(window) };

				KeyReleased e{ keycode };
				callbacks->keyReleasedFunc(e);
			}
		});

		glfwSetWindowCloseCallback(mWindow, [](GLFWwindow* window) {
			Callbacks* callbacks{ (Callbacks*)glfwGetWindowUserPointer(window) };
			callbacks->windowCloseFunc();
		});
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

	void GLFWimplementation::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc)
	{
		mCallbacks.keyPressedFunc = callbackFunc;
	}

	void GLFWimplementation::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc)
	{
		mCallbacks.keyReleasedFunc = callbackFunc;
	}

	void GLFWimplementation::SetWindowCloseCallback(std::function<void()> callbackFunc)
	{
		mCallbacks.windowCloseFunc = callbackFunc;
	}

}