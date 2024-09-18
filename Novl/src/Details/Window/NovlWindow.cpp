#include <pch.h>
#include <Details/Window/NovlWindow.h>
#include <Platform/Window/Windows/WindowsWIndow.h>

namespace Novl{
    WindowBase* WindowBase::Create(const WindowData& wdata){
#ifdef NOVL_PLAT_WINDOWS
        return new WindowsWindow(wdata);
#else
    #error Unsupported Platform!
#endif
        return nullptr;
    }
}