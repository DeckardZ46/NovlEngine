/**
 * < Novl Engine > EditorUI.h
 * Author: DeckardZ46
 * Date: 2024/09/10
 * Note: GUI manager for Novl Engine Editor, using ImGUi as backend
 * Codebase: https://github.com/DeckardZ46/NovlEngine
 */
#pragma once
#include <Details/UI/ImGui/ImGuiUI.h>

namespace Novl{
    class PanelBase;
    class EditorUI :public ImGuiUI {
    public:
        EditorUI();
        ~EditorUI();

        void init() override;
        void clear() override;
        void update() override;
        void draw() override;

    private:
        n_vector<PanelBase*> m_panels;
    };
}
