#include "AEngine.h"
#include <iostream>

class S23_Game_App : public AEngine::AEngineApp
{
public:
	virtual void OnUpdate() override
	{
		std::cout << "Game is running" << std::endl;
	}
};

AENGINE_GAME_START(S23_Game_App);