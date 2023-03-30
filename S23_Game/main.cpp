#include "AEngine.h"
#include <iostream>

class S23_Game_App : public AEngine::AEngineApp
{
public:
	S23_Game_App()
	{
		AEngine::GameWindow::Init();
		AEngine::GameWindow::CreateWindow(800, 600, "TEST NAME");
	}

	virtual void OnUpdate() override
	{
		std::cout << "Game is running" << std::endl;

		AEngine::GameWindow::SwapBuffers();
		AEngine::GameWindow::PollEvents();
	}
};

AENGINE_GAME_START(S23_Game_App);