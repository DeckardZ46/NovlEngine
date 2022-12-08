#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Novl {
	class NOVL_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define NOVL_CORE_TRACE(...)	::Novl::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NOVL_CORE_INFO(...)		::Novl::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NOVL_CORE_WARN(...)		::Novl::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NOVL_CORE_ERR(...)		::Novl::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NOVL_CORE_FATAL(...)	::Novl::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define NOVL_TRACE(...)		::Novl::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NOVL_INFO(...)		::Novl::Log::GetClientLogger()->info(__VA_ARGS__)
#define NOVL_WARN(...)		::Novl::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NOVL_ERR(...)		::Novl::Log::GetClientLogger()->error(__VA_ARGS__)
#define NOVL_FATAL(...)		::Novl::Log::GetClientLogger()->critical(__VA_ARGS__) // fetal->critical
