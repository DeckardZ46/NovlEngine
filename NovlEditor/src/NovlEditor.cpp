/*
< Novl Engine > NovlEditor.cpp
Author: DeckardZ46
Date: 2024/07/10
Note: This is entry point of Novl Engine Editor 
Codebase: https://github.com/DeckardZ46/NovlEngine
*/

#include <Example/test.h>

// Platform specific settings
#ifdef NOVL_PLAT_WINDOWS
    #include <Windows.h>
#endif

int main(){
#ifdef NOVL_PLAT_WINDOWS
    FreeConsole();
#endif
    Test myTest;
    myTest.testLibs();
}