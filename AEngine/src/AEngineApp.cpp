#include "pch.h"
#include "AEngineApp.h"

#include"glad/glad.h"
#include"GLFW/glfw3.h"
#include"stb_image.h"

#include"Renderer.h"
#include"Shader.h"
#include"Image.h"
#include"GameWindow.h"

namespace AEngine
{
	AEngineApp::AEngineApp()
	{
		GameWindow::Init();
		GameWindow::CreateWindow(800, 600, "TestName");

		SetWindowCloseCallback([this]() {DefaultWindowCloseHandler(); });
	}

	void AEngineApp::Run()
	{
		mNextFrameTime = std::chrono::steady_clock::now();

		while (!mGameWindowShouldClose)
		{
			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);

			AEngine::GameWindow::SwapBuffers();
			AEngine::GameWindow::PollEvents();

			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
		}
	}

	void AEngineApp::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc)
	{
		GameWindow::GetWindow()->SetKeyPressedCallback(callbackFunc);
	}

	void AEngineApp::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc)
	{
		GameWindow::GetWindow()->SetKeyReleasedCallback(callbackFunc);
	}

	void AEngineApp::SetWindowCloseCallback(std::function<void()> callbackFunc)
	{
		GameWindow::GetWindow()->SetWindowCloseCallback(callbackFunc);
	}

	void AEngineApp::DefaultWindowCloseHandler()
	{
		mGameWindowShouldClose = true;
	}
}