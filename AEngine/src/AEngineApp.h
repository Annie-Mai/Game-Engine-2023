#pragma once

#include "AEngineUtil.h"


namespace AEngine
{
	class AENGINE_API AEngineApp
	{
	public:
		virtual void OnUpdate() = 0;

		void Run();

	private:

	};
}
