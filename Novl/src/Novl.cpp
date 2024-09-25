#include <pch.h>
#include "Novl.h"

namespace Novl{
    NovlRuntime::NovlRuntime() = default;

    NovlRuntime::~NovlRuntime() = default;

    void NovlRuntime::init(){
        if(m_initialized) { return; }

        // init logging system
        Log::Init();
        NLOGD("Initializing Novl Runtime...");

        // init window
        m_window = n_uptr<WindowBase>(WindowBase::Create());
        m_initialized = true;

        return;
    }

    void NovlRuntime::shutdown(){
        // close window
        m_window.reset();

        // clear logger
        Log::Clear();
    }

    void NovlRuntime::tick(){
        // update window
        m_window->update();

        return;
    }

    void NovlRuntime::flush(){
        // swap window buffer
        m_window->endFrame();
    }
}