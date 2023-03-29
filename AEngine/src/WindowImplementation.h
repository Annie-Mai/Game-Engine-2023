#pragma once

#include "pch.h"

namespace AEngine
{
	class WindowImplementation
	{
	public:
		virtual void CreateWindow(int width, int height, const std::string& windowName) = 0;
		virtual void CreateWindow(int width, int height, const std::string&& windowName) = 0;
		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
	};
}