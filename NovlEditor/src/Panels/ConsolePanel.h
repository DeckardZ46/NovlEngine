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