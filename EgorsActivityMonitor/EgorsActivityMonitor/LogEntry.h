#pragma once

#include <chrono>
#include <string>

enum class EventType
{
    UserActivity,
    FileChange,
    SystemChange
};

class LogEntry
{
public:
    LogEntry(EventType type, const std::chrono::system_clock::time_point& timestamp, const std::string& details);

    EventType GetType() const;
    std::chrono::system_clock::time_point GetTimestamp() const;
    const std::string& GetDetails() const;

private:
    EventType m_Type;
    std::chrono::system_clock::time_point m_Timestamp;
    std::string m_Details;
};