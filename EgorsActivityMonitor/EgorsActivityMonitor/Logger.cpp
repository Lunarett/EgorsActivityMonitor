#include "Logger.h"
#include <chrono>
#include <ctime>

Logger::Logger(const std::string& filePath)
{
    m_LogFile.open(filePath, std::ios::binary | std::ios::app);
    if (!m_LogFile.is_open())
    {
        throw std::runtime_error("Failed to open log file: " + filePath);
    }
}

Logger::~Logger()
{
    if (m_LogFile.is_open())
    {
        m_LogFile.close();
    }
}

void Logger::LogEvent(EventType type, const std::string& details)
{
    std::lock_guard<std::mutex> lock(m_Mutex);
    auto now = std::chrono::system_clock::now();
    LogEntry entry(type, now, details);
    WriteLogEntry(entry);
}

void Logger::LogFileChange(const std::string& filePath, const std::string& changeType)
{
    LogEvent(EventType::FileChange, "File: " + filePath + " Change: " + changeType);
}

void Logger::LogSystemSettingChange(const std::string& setting, const std::string& value)
{
    LogEvent(EventType::SystemChange, "Setting: " + setting + " New Value: " + value);
}

void Logger::WriteLogEntry(const LogEntry& entry)
{
    if (!m_LogFile.is_open())
    {
        return;
    }

    // Serialize LogEntry to binary file
    EventType type = entry.GetType();
    auto timestamp = entry.GetTimestamp();
    std::string details = entry.GetDetails();

    std::time_t time = std::chrono::system_clock::to_time_t(timestamp);
    int32_t typeInt = static_cast<int32_t>(type);
    size_t detailsSize = details.size();

    m_LogFile.write(reinterpret_cast<const char*>(&typeInt), sizeof(typeInt));
    m_LogFile.write(reinterpret_cast<const char*>(&time), sizeof(time));
    m_LogFile.write(reinterpret_cast<const char*>(&detailsSize), sizeof(detailsSize));
    m_LogFile.write(details.c_str(), detailsSize);
}