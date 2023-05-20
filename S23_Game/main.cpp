#include "AEngine.h"
#include <iostream>
#include<functional>
#include <cmath>

class S23_Game_App : public AEngine::AEngineApp
{
public:
	S23_Game_App()
	{
		SetKeyPressedCallback([this](const AEngine::KeyPressed& e) {MyKeyPressedFunc(e);  });
	}

	virtual void OnUpdate() override
	{
		if (StartScreen == true)
		{
			renderer.Clear();
			renderer.Draw(allback, { 0,0 });
			renderer.Draw(startscreen, { 0,0 });
		}
		else if (PlayScreen == true)
		{
			StartGame();
		}
		else if (LoseScreen == true)
		{
			renderer.Clear();
			renderer.Draw(allback, { 0,-450 });
			renderer.Draw(losescreen, { 0,0 });
		}

	}

	void StartGame()
	{
		renderer.Clear();
		renderer.Draw(back, { 0,0 });
		renderer.Draw(ground);
		renderer.Draw(unit);
		renderer.Draw(chicken);
		renderer.Draw(egg);

		enableChickenMovement();
		enableCloudDrop();
		StartScreen = false;
	}

	void enableCloudDrop()
	{
		int rnd = random(2, 700);
		int cloudXPos = chicken.GetCoords().xCoord;
		int cloudYPos = chicken.GetCoords().yCoord;
		//egg follows chicken
		if (dropped == false)
		{
			egg.SetCoords({ cloudXPos, cloudYPos });
			//drops the egg when the position of the egg matches with the random number
			if(egg.GetCoords().xCoord == rnd)
				dropped = true;
		}
		if (dropped == true)
		{
			egg.UpdateYCoord(-10);
			Collected();
		}
		
	}

	int random(int min, int max) {
		int value = min + rand() / (RAND_MAX / (max - min + 1) + 1);
		float num, dec, numcpy;
		int n;
		num = value;
		numcpy = num;
		dec = num - floor(num);
		num = numcpy;
		n = floor(num);
		if (n % 10 < 5)
		{
			n = (n / 10) * 10;
		}
		else if (n % 10 == 5)
		{
			if (dec > 0)
				n = (((n + 10) / 10) * 10);
			else
				n = (n / 10) * 10;
		}
		else
		{
			n = (((n + 10) / 10) * 10);
		}
		return n;
	}

	bool Collected()
	{
		int cloudXPos = chicken.GetCoords().xCoord;
		int cloudYPos = chicken.GetCoords().yCoord;

		//if egg touches player
		if (AEngine::UnitsOverlap(egg, unit))
		{
			egg.SetCoords({ cloudXPos, cloudYPos });
			collected = true;
			dropped = false;
		}
		//if egg touches the ground
		if (AEngine::UnitsOverlap(egg, ground))
		{
			egg.SetCoords({ cloudXPos, cloudYPos });
			collected = false;
			dropped = false;
			PlayScreen = false;
			LoseScreen = true;
		}
		return collected;
	}

	void enableChickenMovement()
	{
		//if the chicken position is less than 0 the bool will be true, indicating it to go right
		if (chicken.GetCoords().xCoord <= 0)
		{
			toRight = true;
		}
		//if the chicken position is great than 0 the bool will be false, indicating it to go left
		if (chicken.GetCoords().xCoord >= 700)
		{
			toRight = false;
		}
		//moves chicken to the right
		if (chicken.GetCoords().xCoord < 700 and toRight == true)
		{
			chicken.UpdateXCoord(10);
		}
		//moves chicken to the left
		else
		{
			chicken.UpdateXCoord(-10);
		}

	}

	void MyKeyPressedFunc(const AEngine::KeyPressed& e)
	{
		if (e.GetKeyCode() == AENGINE_KEY_RIGHT or e.GetKeyCode() == AENGINE_KEY_D)
		{
			if(unit.GetCoords().xCoord <= 680)
				unit.UpdateXCoord(30);
			else
			{
				unit.SetCoords({ 679, 150 });
			}

		}
		else if (e.GetKeyCode() == AENGINE_KEY_LEFT or e.GetKeyCode() == AENGINE_KEY_A)
		{
			if (unit.GetCoords().xCoord >= 0)
				unit.UpdateXCoord(-30);
			else
			{
				unit.SetCoords({ 1, 150 });
			}
		}

		if (StartScreen == true) {
			if (e.GetKeyCode() == AENGINE_KEY_SPACE)
			{
				StartGame();
				PlayScreen = true;
			}
		}
		if (LoseScreen == true)
		{
			if (e.GetKeyCode() == AENGINE_KEY_SPACE)
			{
				LoseScreen = false;
				PlayScreen = true;
				StartGame();
			}
		}
	}

private:
	AEngine::Renderer renderer;

	//Player
	AEngine::Unit unit { "../Assets/Images/chicken.png", {350, 150} };

	//Background
	AEngine::Image back { "../Assets/Images/background.png" };
	AEngine::Image allback { "../Assets/Images/allbg.png" };

	AEngine::Image startscreen { "../Assets/Images/start.png" };
	AEngine::Image losescreen { "../Assets/Images/lose.png" };

	AEngine::Unit ground { "../Assets/Images/ground.png", {0, -80} };

	//Entity
	AEngine::Unit chicken { "../Assets/Images/bigchicken.png", {350, 750} };
	bool toRight = true;

	//Entity-drop
	AEngine::Unit egg{ "../Assets/Images/egg.png", {350, 800} };
	bool dropped = false;
	bool collected = false;


	AEngine::Image start{ "../Assets/Images/start.png" };

	bool StartScreen = true;
	bool PlayScreen = false;
	bool LoseScreen = false;
};

AENGINE_GAME_START(S23_Game_App);