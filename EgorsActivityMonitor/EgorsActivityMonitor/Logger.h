#pragma once

#include "LogEntry.h"
#include <fstream>
#include <string>
#include <mutex>

class Logger
{
public:
    Logger(const std::string& filePath);
    ~Logger();

    void LogEvent(EventType type, const std::string& details);
    void LogFileChange(const std::string& filePath, const std::string& changeType);
    void LogSystemSettingChange(const std::string& setting, const std::string& value);

private:
    std::ofstream m_LogFile;
    std::mutex m_Mutex;

    void WriteLogEntry(const LogEntry& entry);
};