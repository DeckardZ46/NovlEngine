/** 
 * < Novl Engine > Entry.cpp
 * Author: DeckardZ46
 * Date: 2024/07/10
 * Note: This is entry point of Novl Engine Editor
 * Codebase: https://github.com/DeckardZ46/NovlEngine
 */

// Platform specific settings
#ifdef NOVL_PLAT_WINDOWS
    #include <Windows.h>
#endif

#include <pch.h>
#include "NovlEditor.h"

int main() {
#ifdef NOVL_PLAT_WINDOWS
    FreeConsole();
#endif
    Novl::NovlEditor editor;
    editor.init();
    while (!Novl::NovlRuntime::Get().getWindow().isClose()) {
        editor.update();
    }
    editor.close();
}