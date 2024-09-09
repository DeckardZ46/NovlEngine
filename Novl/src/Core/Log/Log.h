/**
 * < Novl Engine > Log.h
 * Author: DeckardZ46
 * Date: 2024/07/10
 * Note: This is logger for Novl Engine (including Runtime & Editor)
 * Codebase: https://github.com/DeckardZ46/NovlEngine
 */

#pragma once
#include <RuntimeCommon.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Novl {
	class NOVL_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetRuntimeLogger() { return s_RuntimeLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetEditorLogger() { return s_EditorLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_RuntimeLogger;
		static std::shared_ptr<spdlog::logger> s_EditorLogger;
	};
}

// Runtime log macros
#define NLOGD(...)	    ::Novl::Log::GetRuntimeLogger()->debug(__VA_ARGS__)
#define NLOGI(...)		::Novl::Log::GetRuntimeLogger()->info(__VA_ARGS__)
#define NLOGW(...)		::Novl::Log::GetRuntimeLogger()->warn(__VA_ARGS__)
#define NLOGE(...)		::Novl::Log::GetRuntimeLogger()->error(__VA_ARGS__)

// Editor log macros
#define ELOGD(...)		::Novl::Log::GetEditorLogger()->debug(__VA_ARGS__)
#define ELOGI(...)		::Novl::Log::GetEditorLogger()->info(__VA_ARGS__)
#define ELOGW(...)		::Novl::Log::GetEditorLogger()->warn(__VA_ARGS__)
#define ELOGE(...)		::Novl::Log::GetEditorLogger()->error(__VA_ARGS__)
