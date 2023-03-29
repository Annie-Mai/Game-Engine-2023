
#include "pch.h"
#include "AEngineApp.h"
#include <iostream>


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