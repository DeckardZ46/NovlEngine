#pragma once

#define BIT(x) (1 << x)

#define NOVL_BIND_EVENT_FN(fn) std::bind(&fn,this,std::placeholders::_1)

#ifdef NOVL_PLATFORM_WINDOWS
	#ifdef NOVL_BUILD_DLL
		#define NOVL_API __declspec(dllexport)
	#else 
		#define NOVL_API __declspec(dllimport)
	#endif
#else
	#error Novl only support Windows!
#endif

#ifdef NOVL_DEBUG
	#define NOVL_ENABLE_ASSERTS
#endif

#ifdef NOVL_ENABLE_ASSERTS
	#define NOVL_ASSERT(x, ...) { if(!(x)) { NOVL_ERR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define NOVL_CORE_ASSERT(x, ...) { if(!(x)) { NOVL_CORE_ERR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define NOVL_ASSERT(x,...)
	#define NOVL_CORE_ASSERT(x,...)
#endif