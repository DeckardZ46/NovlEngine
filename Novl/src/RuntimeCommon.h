/** 
 * < Novl Engine > RuntimeCommon.h
 * Author: DeckardZ46
 * Date: 2024/07/10
 * Note: This is common settings for Novl Engine Runtime
 * Codebase: https://github.com/DeckardZ46/NovlEngine
*/

// dynamic lib macro
#pragma once
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

// assertions
#ifdef NOVL_ENABLE_ASSERT
	#define NOVL_ASSERT(x, ...) { if(!(x)) { NLOGE("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define EDITOR_ASSERT(x, ...) { if(!(x)) { ELOGE("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define NOVL_ASSERT(x,...)
	#define EDITOR_ASSERT(x,...)
#endif

// settings
#ifdef NOVL_PLAT_WINDOWS
    // OpenGL version settings, version = MAJ.MIN, e.g. 3.3
    #define NOVL_OGL_VER_MAJ 3  
    #define NOVL_OGL_VER_MIN 3  
#endif