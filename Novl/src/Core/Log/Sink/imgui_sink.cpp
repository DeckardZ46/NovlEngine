#include "imgui_sink.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/base_sink.h>

const imgui_sink_mt_t imgui_sink_mt() {
	auto dearlog = spdlog::create<dear_spdlog::imgui_sink<std::mutex>>(std::string("dearlog"));

	// I don't understand this step, shouldn't it log to all registered loggers?
	spdlog::set_default_logger(dearlog);

	return std::dynamic_pointer_cast<dear_spdlog::imgui_sink<std::mutex>>(dearlog->sinks()[0]);
}

std::string nformat_time(const std::chrono::system_clock::time_point& time_point)
{
    auto time_t = std::chrono::system_clock::to_time_t(time_point);
    std::ostringstream oss;
    oss.imbue(std::locale("en_US.UTF-8"));
    oss << std::put_time(std::localtime(&time_t), "%Y-%m-%d %H:%M:%S");

    return oss.str();
}
