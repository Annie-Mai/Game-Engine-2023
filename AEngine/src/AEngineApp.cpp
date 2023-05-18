#include "pch.h"
#include "AEngineApp.h"

#include"glad/glad.h"
#include"GLFW/glfw3.h"
#include"stb_image.h"

namespace AEngine
{


	void AEngineApp::Run()
	{
		while (true)
		{


			OnUpdate();
		}
	}
}