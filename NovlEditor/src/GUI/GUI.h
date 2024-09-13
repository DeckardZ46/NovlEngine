/**
 * < Novl Engine > GUI.h
 * Author: DeckardZ46
 * Date: 2024/09/10
 * Note: GUI manager for Novl Engine Editor, using ImGUi as backend
 * Codebase: https://github.com/DeckardZ46/NovlEngine
 */
#pragma once
#include <Novl.h>
#include <imgui.h>

namespace Novl{
    class NovlGUI {
    public:
        NovlGUI();
        ~NovlGUI();

        void init();
        void drawViews();

    private:
        
    };
}
