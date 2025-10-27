#include <pch.h>
#include "Novl.h"

namespace Novl {
NovlRuntime::NovlRuntime() {
    // RAII
    init();
}

NovlRuntime::~NovlRuntime() = default;

void NovlRuntime::init() {
    if (m_initialized) {
        return;
    }

    // init logging system
    Log::Init();
    NLOGD("Initializing Novl Runtime...");

    // init input
    m_inputManager = n_uptr<InputManager>(new InputManager());
    m_inputManager->init();

    // init window
    m_window = n_uptr<WindowBase>(WindowBase::Create());
    m_window->init();

    m_initialized = true;

    return;
}

void NovlRuntime::shutdown() {
    // close window
    m_window.reset();

    // clear logger
    Log::Clear();
}

void NovlRuntime::tick() {
    // update window
    m_window->update();

    return;
}

void NovlRuntime::flush() {
    // swap window buffer
    m_window->endFrame();
}
} // namespace Novl