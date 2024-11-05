/**
 * < Novl Engine > ConsolePanel.h
 * Author: DeckardZ46
 * Date: 2024/10/17
 * Note: Console panel for Novl Editor
 * +---------------------+
 * |                     |    
 * |                     |
 * |   _______________   |  
 * |   |   Console   |   | 
 * +---------------------+ 
 * Codebase: https://github.com/DeckardZ46/NovlEngine
 */
#pragma once
#include <imgui.h>
#include "PanelBase.h"

namespace Novl{
class ConsolePanel :public PanelBase {
public:
    ConsolePanel(n_string &&name);
    ~ConsolePanel();

    void update() override;
    void draw() override;

    int TextEditCallbackImpl(ImGuiInputTextCallbackData* data);

private:
    uint32_t                m_windowWidth;
    uint32_t                m_windowHeight;
    bool                    m_scrollToBottom;
    char                    m_inputBuf[256];
    ImVector<const char*>   m_commands;
    ImGuiTextFilter         m_filter;
};
} // namespace Novl