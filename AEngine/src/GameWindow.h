#pragma once

#include "pch.h"
#include "AEngineUtil.h"

namespace AEngine
{
	class AENGINE_API GameWindow
	{
	public:
		static void Init();
		static std::unique_ptr<GameWindow>& GetWindow();

		void CreateWindow(int width, int height, const std::string& windowName);
		void CreateWindow(int width, int height, std::string&& windowName);

		int GetWidth() const;
		int GetHeight() const;

	private:
		GameWindow();
		inline static std::unique_ptr<GameWindow> mInstance{ nullptr };

		WindowImplementation* mImplementation{ nullptr };

	};
}