#include <pch.h>
#include "Log.h"

namespace Novl {
	std::shared_ptr<spdlog::logger> Log::s_RuntimeLogger;
	std::shared_ptr<spdlog::logger> Log::s_EditorLogger;

	void Log::Init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");

		s_RuntimeLogger = spdlog::stdout_color_mt("Novl");
		s_RuntimeLogger->set_level(spdlog::level::trace);

		s_EditorLogger = spdlog::stderr_color_mt("NovlEditor");
		s_EditorLogger->set_level(spdlog::level::trace);
	}
}