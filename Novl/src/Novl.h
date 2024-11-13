/**
 * < Novl Engine > Novl.h
 * Author: DeckardZ46
 * Date: 2024/09/09
 * Note: This is header file for Novl Engine Runtime
 * Codebase: https://github.com/DeckardZ46/NovlEngine
 */
#pragma once
#include "Details/Window/NovlWindow.h"
#include <Core/Log/Log.h>
#include <Core/Types.h>

namespace Novl {
class NovlRuntime {
    friend class NovlApp;
  private:
    NovlRuntime();
    NovlRuntime(const NovlRuntime &) = delete;
    NovlRuntime(NovlRuntime &&) = delete;
    NovlRuntime &operator=(const NovlRuntime &) = delete;
    NovlRuntime &operator=(NovlRuntime &&) = delete;

  public:
    ~NovlRuntime();

    /**
     * public functions
     */
    inline static NovlRuntime &Get() {
        static NovlRuntime s_Runtime;
        return s_Runtime;
    }

    // window system
    inline WindowBase &getWindow() const {
        return *m_window;
    }
    inline void* getNativeWindow() {
        return m_window->getNativeWindow();
    }

  private:
    /**
     * private functions
     */
    void init();
    void shutdown();

    void tick();
    void flush();

  private:
    /**
     * private members
     */
    // status
    bool m_initialized = false;

    // managers & systems
    n_uptr<WindowBase> m_window;
};
} // namespace Novl