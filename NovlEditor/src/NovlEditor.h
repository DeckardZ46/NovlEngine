/*
< Novl Engine > NovlEditor.h
Author: DeckardZ46
Date: 2024/09/09
Note: NovlEditor class header file
Codebase: https://github.com/DeckardZ46/NovlEngine
*/

#pragma once 
#include <Novl.h>

namespace Novl{
    class NovlEditor{
    public:
        NovlEditor();
        ~NovlEditor();

        void init();
        void close();
        void update();

    private:

    };
}