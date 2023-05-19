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
	void AEngineApp::Run()
	{
		Renderer renderer;

		Image pic{ "../Assets/Images/cat.png" };

		pic.Activate();

		Shader sProgram{ "../Assets/Shaders/DefaultVertexShader.glsl", "../Assets/Shaders/DefaultFragmentShader.glsl" };

		sProgram.Pass2FloatValues("screenSize", GameWindow::GetWidth(), GameWindow::GetHeight());

		mNextFrameTime = std::chrono::steady_clock::now();

		while (true)
		{
			renderer.Clear();

			renderer.Draw(pic, { 200, 100 });

			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);

			AEngine::GameWindow::SwapBuffers();
			AEngine::GameWindow::PollEvents();

			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
		}
	}
}