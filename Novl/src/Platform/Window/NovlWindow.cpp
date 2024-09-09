#include <pch.h>
#include "NovlWindow.h"
#include <Platform/Window/Windows/WindowsWIndow.h>

namespace Novl{
    Window* Window::Create(const WindowData& wdata){
#ifdef NOVL_PLAT_WINDOWS
        return new WindowsWindow(wdata);
#else
    #error Unsupported Platform!
#endif
        return nullptr;
    }
}