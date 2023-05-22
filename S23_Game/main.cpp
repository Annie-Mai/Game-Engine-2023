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
			renderScore(350, 200);
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

		renderScore(30, 90);
		renderHearts(20, 20);
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
			egg.UpdateYCoord(dropSpeed);
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

	void Collected()
	{
		if (AEngine::UnitsOverlap(egg, ground))
		{
			lives -= 1;
		}
		int cloudXPos = chicken.GetCoords().xCoord;
		int cloudYPos = chicken.GetCoords().yCoord;
		//if egg touches player
		if (AEngine::UnitsOverlap(egg, unit))
		{
			egg.SetCoords({ cloudXPos, cloudYPos });
			dropped = false;
			eggsCollected += 1;
		}
		//if egg touches the ground
		if (AEngine::UnitsOverlap(egg, ground))
		{
			if (lives >= 0)
			{
				egg.SetCoords({ cloudXPos, cloudYPos });
				dropped = false;
			}
			if (lives < 0)
			{
				PlayScreen = false;
				LoseScreen = true;
			}
			
		}
		if (eggsCollected == 5)
		{
			dropSpeed = -15;
		}
		if (eggsCollected == 10)
		{
			dropSpeed = -20;
		}
		if (eggsCollected == 15)
		{
			dropSpeed = -25;
		}
		if (eggsCollected == 20)
		{
			dropSpeed = -30;
		}
		if (eggsCollected == 30)
		{
			dropSpeed = -40;
		}

	}

	void renderHearts(int xPos, int yPos)
	{
		int gap = 0;
		for (int i = 0; i < lives; i++)
		{
			renderer.Draw(heart, { xPos + gap, yPos });
			gap += 60;
		}
	}

	void renderScore(int xPos, int yPos)
	{
		int gap = 50;
		AEngine::Unit egg1{ "../Assets/Images/eggscore.png", {xPos - 20, yPos} };
		renderer.Draw(egg1);
		std::string numEggs = std::to_string(eggsCollected);
		for (int i = 0; i <= numEggs.length(); i++)
		{
			if (numEggs[i] == '1')
			{
				renderer.Draw(one, { xPos + gap, yPos + 5 });
			}
			if (numEggs[i] == '2')
			{
				renderer.Draw(two, { xPos + gap, yPos + 5 });
			}
			if (numEggs[i] == '3')
			{
				renderer.Draw(three, { xPos + gap, yPos + 5 });
			}
			if (numEggs[i] == '4')
			{
				renderer.Draw(four, { xPos + gap, yPos + 5 });
			}
			if (numEggs[i] == '5')
			{
				renderer.Draw(five, { xPos + gap, yPos + 5 });
			}
			if (numEggs[i] == '6')
			{
				renderer.Draw(six, { xPos + gap, yPos + 5 });
			}
			if (numEggs[i] == '7')
			{
				renderer.Draw(seven, { xPos + gap, yPos + 5 });
			}
			if (numEggs[i] == '8')
			{
				renderer.Draw(eight, { xPos + gap, yPos + 5 });
			}
			if (numEggs[i] == '9')
			{
				renderer.Draw(nine, { xPos + gap, yPos + 5 });
			}
			if (numEggs[i] == '0')
			{
				renderer.Draw(zero, { xPos + gap, yPos + 5 });
			}
			gap += 50;
		}
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
				unit.UpdateXCoord(60);
			else
			{
				unit.SetCoords({ 679, 150 });
			}

		}
		else if (e.GetKeyCode() == AENGINE_KEY_LEFT or e.GetKeyCode() == AENGINE_KEY_A)
		{
			if (unit.GetCoords().xCoord >= 0)
				unit.UpdateXCoord(-60);
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
				lives = defaultLives + 1;
				eggsCollected = eggsCollectedDefault;
				dropSpeed = dropSpeedDefault;
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
	AEngine::Image heart { "../Assets/Images/heart.png"};

	AEngine::Image startscreen { "../Assets/Images/start.png" };
	AEngine::Image losescreen { "../Assets/Images/lose.png" };

	AEngine::Unit ground { "../Assets/Images/ground.png", {0, -80} };

	//Entity
	AEngine::Unit chicken { "../Assets/Images/bigchicken.png", {350, 750} };
	bool toRight = true;

	//Entity-drop
	AEngine::Unit egg{ "../Assets/Images/egg.png", {350, 800} };
	bool dropped = false;

	int dropSpeedDefault = -10;
	int dropSpeed = dropSpeedDefault;


	AEngine::Image start{ "../Assets/Images/start.png" };

	bool StartScreen = true;
	bool PlayScreen = false;
	bool LoseScreen = false;

	int defaultLives = 3;
	int lives = defaultLives;

	int eggsCollectedDefault = 0;
	int eggsCollected = eggsCollectedDefault;

	//Number values
	AEngine::Image one{ "../Assets/Images/Num/1.png" };
	AEngine::Image two{ "../Assets/Images/Num/2.png" };
	AEngine::Image three{ "../Assets/Images/Num/3.png" };
	AEngine::Image four{ "../Assets/Images/Num/4.png" };
	AEngine::Image five{ "../Assets/Images/Num/5.png" };
	AEngine::Image six{ "../Assets/Images/Num/6.png" };
	AEngine::Image seven{ "../Assets/Images/Num/7.png" };
	AEngine::Image eight{ "../Assets/Images/Num/8.png" };
	AEngine::Image nine{ "../Assets/Images/Num/9.png" };
	AEngine::Image zero{ "../Assets/Images/Num/0.png" };
};

AENGINE_GAME_START(S23_Game_App);