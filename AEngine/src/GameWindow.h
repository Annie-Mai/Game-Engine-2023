#pragma once

#include "pch.h"
#include "AEngineUtil.h"
#include "WindowImplementation.h"
#include "AEngineEvents.h"

namespace AEngine
{
	class AENGINE_API GameWindow
	{
	public:
		static void Init();
		static std::unique_ptr<GameWindow>& GetWindow();

		static void CreateWindow(int width, int height, const std::string& windowName);
		static void CreateWindow(int width, int height, std::string&& windowName);

		static void SwapBuffers();
		static void PollEvents();

		static int GetWidth();
		static int GetHeight();

		~GameWindow();

		void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc);
		void SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc);
		void SetWindowCloseCallback(std::function<void()> callbackFunc);

	private:
		GameWindow();
		inline static std::unique_ptr<GameWindow> mInstance{ nullptr };

		WindowImplementation* mImplementation{ nullptr };

	};
}