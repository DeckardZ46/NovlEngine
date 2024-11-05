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

        inline n_float getWidth() const {
            return m_panelWidth;
        }
        inline void setWidth(n_float width){
            m_panelWidth = width;
        }
        inline n_float getHeight() const {
            return m_panelHeight;
        }
        inline void setHeight(n_float height){
            m_panelHeight = height;
        }
    
    protected:
        n_string m_panelName;
        n_float m_panelWidth;
        n_float m_panelHeight;
    };

} // namespace Novl