/**
 * < Novl Engine > Novl.h
 * Author: DeckardZ46
 * Date: 2024/09/09
 * Note: NovlRuntime class header file
 * Codebase: https://github.com/DeckardZ46/NovlEngine
 */
#pragma once
#include <RuntimeCommon.h>
#include <Core/Log/Log.h>
#include <Core/Types.h>
#include "Platform/Window/NovlWindow.h"

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

        inline Window& getWindow() {return *m_window;}

        void init();
        void tick();

        inline bool isWindowClose() { return m_window->isClose(); }

    private:
        bool m_initialized = false;
        bool m_running = false;
        n_uptr<Window> m_window;
    };
}