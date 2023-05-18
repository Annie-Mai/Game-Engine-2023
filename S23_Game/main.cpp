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
	}
};

AENGINE_GAME_START(S23_Game_App);