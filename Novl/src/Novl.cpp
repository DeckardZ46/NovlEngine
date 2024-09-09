#include <pch.h>
#include "Novl.h"

namespace Novl{
    void NovlRuntime::init(){
        Log::Init();
        m_window = n_uptr<Window>(Window::Create());
    }

    void NovlRuntime::run(){
        
    }
}