/*
< Novl Engine > RuntimeCommon.h
Author: DeckardZ46
Date: 2024/07/10
Note: This is common settings for Novl Engine Runtime
Codebase: https://github.com/DeckardZ46/NovlEngine
*/

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

