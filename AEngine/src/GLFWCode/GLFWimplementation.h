#pragma once

#include "../WindowImplementation.h"
#include "GLFW/glfw3.h"

namespace AEngine
{
	class GLFWimplementation : public WindowImplementation
	{
	public:
		virtual void CreateWindow(int width, int height, const std::string& windowName) override;
		virtual void CreateWindow(int width, int height, const std::string&& windowName) override;
		virtual void SwapBuffers() override;
		virtual void PollEvents() override;
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;

	private:
		GLFWwindow* mWindow{ nullptr };

	};
}