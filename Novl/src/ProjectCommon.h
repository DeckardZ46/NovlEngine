#ifdef NOVL_PLAT_WINDOWS
    #ifdef NOVL_BUILD_DLL
        #define NOVL_API __declspec(dllexport)
    #else
        #define NOVL_API __declspec(dllimport)
    #endif
#else 
    #define NOVL_API
    #error Unsupported Platform!
#endif

// Platform specific settings
#ifdef NOVL_PLAT_WINDOWS
    #include <Windows.h>
#endif