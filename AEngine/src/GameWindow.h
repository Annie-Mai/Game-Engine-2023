#pragma once

#include "pch.h"
#include "AEngineUtil.h"
#include "WindowImplementation.h"

namespace AEngine
{
	class AENGINE_API GameWindow
	{
	public:
		static void Init();
		static std::unique_ptr<GameWindow>& GetWindow();

		static void CreateWindow(int width, int height, const std::string& windowName);
		static void CreateWindow(int width, int height, std::string&& windowName);

		static int GetWidth();
		static int GetHeight();

	private:
		GameWindow();
		inline static std::unique_ptr<GameWindow> mInstance{ nullptr };

		WindowImplementation* mImplementation{ nullptr };

	};
}