#include "LogEntry.h"

LogEntry::LogEntry(EventType type, const std::chrono::system_clock::time_point& timestamp, const std::string& details)
    : m_Type(type), m_Timestamp(timestamp), m_Details(details)
{
}

EventType LogEntry::GetType() const
{
    return m_Type;
}

std::chrono::system_clock::time_point LogEntry::GetTimestamp() const
{
    return m_Timestamp;
}

const std::string& LogEntry::GetDetails() const
{
    return m_Details;
}