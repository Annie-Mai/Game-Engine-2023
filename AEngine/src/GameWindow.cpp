#include "pch.h"
#include "GameWindow.h"


namespace AEngine
{
	void GameWindow::Init()
	{
		if (!mInstance)
			mInstance = std::unique_ptr<GameWindow>(new GameWindow);
	}
	std::unique_ptr<GameWindow>& GameWindow::GetWindow()
	{
		return mInstance;
	}
	void GameWindow::CreateWindow(int width, int height, const std::string& windowName)
	{
		mImplementation->CreateWindow(width, height, windowName);
	}
	void GameWindow::CreateWindow(int width, int height, std::string&& windowName)
	{
		mImplementation->CreateWindow(width, height, windowName);
	}
	int GameWindow::GetWidth() const
	{
		return mImplementation->GetWidth();
	}
	int GameWindow::GetHeight() const
	{
		return mImplementation->GetHeight();
	}
}