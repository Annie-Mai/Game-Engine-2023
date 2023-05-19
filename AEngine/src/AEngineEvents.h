#pragma once

#include "AEngineUtil.h"

namespace AEngine
{
	class AENGINE_API KeyPressed
	{
	public:
		KeyPressed(int kCode);
		
		int GetKeyCode() const;

	private:
		int mKeyCode;
	};

	class AENGINE_API KeyReleased
	{
	public:
		KeyReleased(int kCode);

		int GetKeyCode() const;

	private:
		int mKeyCode;
	};

	class AENGINE_API WindowClosed
	{
	};
}