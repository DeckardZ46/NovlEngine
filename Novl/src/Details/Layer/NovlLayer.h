/**
 * < Novl Engine > NovlLayer.h
 * Author: DeckardZ46
 * Date: 2024/09/17
 * ---
 * Note: This is Layer interface of Novl Engine, design of Layer & LayerStack is inspired by < Hazel Engine > by Cherno
 *       Hazel Engine: https://hazelengine.com/
 * ---
 * Codebase: https://github.com/DeckardZ46/NovlEngine
 */
#pragma once
#include <RuntimeCommon.h>

namespace Novl{
    class NOVL_API LayerBase{
    public:
        LayerBase(const n_string& name = "DefaultLayer"):m_name(name) {}
        virtual ~LayerBase(){}

        virtual void onAttach() = 0;
        virtual void onDetach() = 0;
        virtual void onUpdate() = 0;

        inline const n_string& getName() const { return m_name; }
        
    private:
        n_string m_name;
    };
}