#include <pch.h>
#include "GUI.h"

#ifdef NOVL_PLAT_WINDOWS
    #include <glfw3.h>
    #include <imgui_impl_glfw.h>
    #include <imgui_impl_opengl3.h>
#endif


namespace Novl{
    NovlGUI::NovlGUI() {
        NLOGI("Initializing NovlGUI...");


    }

    NovlGUI::~NovlGUI(){

    }
}