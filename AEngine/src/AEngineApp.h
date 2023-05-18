#pragma once

#include"pch.h"
#include "AEngineUtil.h"

constexpr int FPS{ 60 };

namespace AEngine
{
	class AENGINE_API AEngineApp
	{
	public:
		virtual void OnUpdate() = 0;

		void Run();

	private:
		std::chrono::milliseconds mFrameDuration{ std::chrono::milliseconds{1000}/ FPS };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}
