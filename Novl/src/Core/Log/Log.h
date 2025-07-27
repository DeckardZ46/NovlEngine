/**
 * < Novl Engine > Log.h
 * Author: DeckardZ46
 * Date: 2024/07/10
 * Note: This is logger for Novl Engine (including Runtime & Editor)
 * Codebase: https://github.com/DeckardZ46/NovlEngine
 */

#pragma once
#include <spdlog/spdlog.h>
#include <spdlog/sinks/base_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Novl {
// sink bitmask
const char ConsoleSink = 1 << 0; // 0001
const char UISink = 1 << 1;      // 0010
const char FileSink = 1 << 2;    // 0100
const char NoneSink = 1 << 3;    // 1000

using log_sink = std::shared_ptr<spdlog::sinks::sink>;

class Log {
  public:
    static void Init();
    static void Clear();

    static void AddSink(log_sink &&sink);
    static void ReloadSink(char sink_mask);

    inline static std::shared_ptr<spdlog::logger> &GetRuntimeLogger() {
        return s_RuntimeLogger;
    }
    inline static std::shared_ptr<spdlog::logger> &GetEditorLogger() {
        return s_EditorLogger;
    }

  private:
    static std::shared_ptr<spdlog::logger> s_RuntimeLogger;
    static std::shared_ptr<spdlog::logger> s_EditorLogger;
};
} // namespace Novl

// Runtime log macros
#ifdef NOVL_RT
#define NLOGD(...) ::Novl::Log::GetRuntimeLogger()->debug(__VA_ARGS__)
#define NLOGI(...) ::Novl::Log::GetRuntimeLogger()->info(__VA_ARGS__)
#define NLOGW(...) ::Novl::Log::GetRuntimeLogger()->warn(__VA_ARGS__)
#define NLOGE(...) ::Novl::Log::GetRuntimeLogger()->error(__VA_ARGS__)
#endif // NOVL_RT

// Editor log macros
#ifdef NOVL_EDT
#define ELOGD(...) ::Novl::Log::GetEditorLogger()->debug(__VA_ARGS__)
#define ELOGI(...) ::Novl::Log::GetEditorLogger()->info(__VA_ARGS__)
#define ELOGW(...) ::Novl::Log::GetEditorLogger()->warn(__VA_ARGS__)
#define ELOGE(...) ::Novl::Log::GetEditorLogger()->error(__VA_ARGS__)
#endif // NOVL_EDT
