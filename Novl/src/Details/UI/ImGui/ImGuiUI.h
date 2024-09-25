#pragma once
#include <RuntimeCommon.h>
#include <Details/UI/NovlUI.h>
#include <Details/Window/NovlWindow.h>
#include <imgui.h>

namespace Novl{
    class ImGuiUI:public UIBase{
    public:
        ImGuiUI();
        virtual ~ImGuiUI();

        virtual void init() override;
        virtual void clear() override;
        virtual void update() override;
        virtual void draw() override;
        
    private:
        
    };
}