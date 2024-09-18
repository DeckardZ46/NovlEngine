#pragma once
#include <RuntimeCommon.h>
#include <Details/UI/NovlUI.h>
#include <Details/Window/NovlWindow.h>
#include <imgui.h>

#ifdef NOVL_PLAT_WINDOWS
    #include <glfw3.h>
    #include <imgui_impl_glfw.h>
    #include <imgui_impl_opengl3.h>
#endif

namespace Novl{
    class NOVL_API ImGuiUI:public UIBase{
    public:
        ImGuiUI();
        virtual ~ImGuiUI();

        void init() override;
        void update() override;
        void draw() override;
        
    private:

    }
}