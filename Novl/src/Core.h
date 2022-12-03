#pragma once

#ifdef NOVL_PLATFORM_WINDOWS
	#ifdef NOVL_BUILD_DLL
		#define NOVL_API __declspec(dllexport)
	#else 
		#define NOVL_API __declspec(dllimport)
	#endif
#else
	#error Novl only support Windows!
#endif

#define BIT(x) (1 << x)
