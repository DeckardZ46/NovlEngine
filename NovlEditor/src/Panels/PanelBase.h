/**
 * < Novl Engine > PanelBase.h
 * Author: DeckardZ46
 * Date: 2024/09/25
 * Note: Editor panel interface, should be implemented in various panels and used by Editor UI
 * Codebase: https://github.com/DeckardZ46/NovlEngine
 */
#pragma once 
#include <Core/Types.h>

namespace Novl{
    class PanelBase {
    public:
        PanelBase(n_string &&name): m_panelName(std::move(name)){}
        virtual ~PanelBase(){}

        virtual void update() = 0;
        virtual void draw() = 0;
    
    private:
        n_string m_panelName;
    };

} // namespace Novl