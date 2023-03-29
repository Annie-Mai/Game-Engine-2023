#pragma once

#ifdef AENGINE_WINDOWS
	#ifdef AENGINE_LIB
		#define AENGINE_API __declspec(dllexport)
	#else
		#define AENGINE_API __declspec(dllimport)
	#endif
#else
	#define AENGINE_API
#endif


#define AENGINE_GAME_START(ClassName) \
int main()\
{\
	ClassName game;\
	game.Run();\
	return 0;\
}