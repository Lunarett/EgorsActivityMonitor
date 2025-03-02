#include "Log.h"

// Define the static logger instance
std::shared_ptr<spdlog::logger> Log::s_Logger;

void Log::Init()
{
    std::vector<spdlog::sink_ptr> sinks;
    sinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
    sinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("Logs/EgorsActivityMonitor.log", true));

    sinks[0]->set_pattern("%^[%T] %n: %v%$");
    sinks[1]->set_pattern("[%T] [%l] %n: %v");

    s_Logger = std::make_shared<spdlog::logger>("EAM", sinks.begin(), sinks.end());
    spdlog::register_logger(s_Logger);
    s_Logger->set_level(spdlog::level::trace);
    s_Logger->flush_on(spdlog::level::trace);

    LOG_INFO("Logger initialized.");
}