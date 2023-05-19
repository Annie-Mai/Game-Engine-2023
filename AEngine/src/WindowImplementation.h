#pragma once

#include "pch.h"
#include "AEngineEvents.h"

namespace AEngine
{
	class WindowImplementation
	{
	public:
		virtual void CreateWindow(int width, int height, const std::string& windowName) = 0;
		virtual void CreateWindow(int width, int height, const std::string&& windowName) = 0;
		virtual void SwapBuffers() = 0;
		virtual void PollEvents() = 0;
		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
		virtual void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc) = 0;
		virtual void SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc) = 0;
		virtual void SetWindowCloseCallback(std::function<void()> callbackFunc) = 0;
		virtual ~WindowImplementation() {};
	};
}