/**
 * < Novl Engine > ConsolePanel.h
 * Author: DeckardZ46
 * Date: 2024/10/17
 * Note: Console panel for Novl Editor, DO NOT USE Novl log (NLOGX/ELOGX) in this class, that will cause MASSIVE recursive logging!!!
 * Codebase: https://github.com/DeckardZ46/NovlEngine
 */
#pragma once
#include "PanelBase.h"

namespace Novl{
class ConsolePanel :public PanelBase {
public:
    ConsolePanel(n_string &&name);
    ~ConsolePanel();

    void update() override;
    void draw() override;

private:
    
};
} // namespace Novl