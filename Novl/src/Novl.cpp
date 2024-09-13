#include <pch.h>
#include "Novl.h"

namespace Novl{
    NovlRuntime::NovlRuntime() = default;

    NovlRuntime::~NovlRuntime() = default;

    void NovlRuntime::init(){
        if(m_initialized) { return; }

        // init logging system
        Log::Init();
        NLOGI("Initializing Novl Runtime...");

        // init window
        m_window = n_uptr<Window>(Window::Create());
        m_initialized = true;

        return;
    }

    void NovlRuntime::tick(){
        // update window
        m_window->update();
        return;
    }
}