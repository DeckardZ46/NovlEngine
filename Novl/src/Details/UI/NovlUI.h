/**
 * < Novl Engine > NovlUI.h
 * Author: DeckardZ46
 * Date: 2024/09/14
 * Note: This is UI interface of Novl Engine, for both Editor UI and Game UI
 * Codebase: https://github.com/DeckardZ46/NovlEngine
 */
#pragma once
#include <RuntimeCommon.h>

namespace Novl{
    class UIBase{
    public:
        UIBase(){}
        virtual ~UIBase(){}

        virtual void init() = 0;
        virtual void clear() = 0;
        virtual void update() = 0;
        virtual void draw() = 0;
        
    private:

    };
}