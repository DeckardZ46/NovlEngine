/**
 * < Novl Engine > Novl.h
 * Author: DeckardZ46
 * Date: 2024/09/09
 * Note: This is header file for Novl Engine Runtime
 * Codebase: https://github.com/DeckardZ46/NovlEngine
 */
#pragma once
#include <RuntimeCommon.h>
#include <Core/Log/Log.h>
#include <Core/Types.h>
#include "Details/Window/NovlWindow.h"

namespace Novl{
    class NOVL_API NovlRuntime{
    private:
        NovlRuntime();
        NovlRuntime(const NovlRuntime&) = delete;
        NovlRuntime(NovlRuntime&&) = delete;
        NovlRuntime &operator=(const NovlRuntime&) = delete;
        NovlRuntime &operator=(NovlRuntime&&) = delete;

    public:
        ~NovlRuntime();

        inline static NovlRuntime& Get() {
            static NovlRuntime s_Runtime;
            return s_Runtime;
        }

        void init();
        void shutdown();

        void tick();
        void flush();

        inline WindowBase& getWindow() {return *m_window;}
        inline bool isWindowClose() { return m_window->isClose(); }

    private:
        bool m_initialized = false;
        bool m_running = false;
        
        n_uptr<WindowBase> m_window;
    };
}