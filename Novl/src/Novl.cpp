#include <pch.h>
#include "Novl.h"

namespace Novl{
    NovlRuntime::NovlRuntime(){

    }

    NovlRuntime::~NovlRuntime(){

    }

    void NovlRuntime::init(){
        if(m_initialized) { return; }

        Log::Init();
        NLOGI("Initializing Novl Runtime...");

        m_window = n_uptr<Window>(Window::Create());
        m_initialized = true;
        return;
    }

    void NovlRuntime::tick(){
        m_window->update();
        return;
    }
}