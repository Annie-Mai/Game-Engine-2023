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

#if AENGINE_DEBUG==2
	#define AENGINE_LOG(x) std::cout<<"Log: "<<x<<std::endl;
	#define AENGINE_ERROR(x) std::cerr<<"Error: "<<x<<std::endl;
#elif AENGINE_DEBUG==1
	#define AENGINE_LOG(x)
	#define AENGINE_ERROR(x) std::cerr<<"Error: "<<x<<std::endl;
#else
	#define AENGINE_LOG(x)
	#define AENGINE_ERROR(x)
#endif