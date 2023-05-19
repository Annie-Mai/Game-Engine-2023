#include "AEngine.h"
#include <iostream>
#include<functional>

class S23_Game_App : public AEngine::AEngineApp
{
public:
	S23_Game_App()
	{
		SetKeyPressedCallback([this](const AEngine::KeyPressed& e) {MyKeyPressedFunc(e);  });
	}

	virtual void OnUpdate() override
	{
		renderer.Clear();
		renderer.Draw(back, { 0,0 });
		renderer.Draw(unit);
	}

	void MyKeyPressedFunc(const AEngine::KeyPressed& e)
	{
		if (e.GetKeyCode() == AENGINE_KEY_RIGHT)
			unit.UpdateXCoord(20);
		else if (e.GetKeyCode() == AENGINE_KEY_LEFT)
			unit.UpdateXCoord(-20);
	}

private:
	AEngine::Renderer renderer;
	AEngine::Unit unit{ "../Assets/Images/test.png", {100, 100} };
	AEngine::Image back{ "../Assets/Images/cat.png" };
};

AENGINE_GAME_START(S23_Game_App);