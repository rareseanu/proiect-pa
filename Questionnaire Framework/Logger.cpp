#include "Logger.h"
#include <chrono>
#include <sstream>

Logger::Logger(const std::string& fileName)
{
	m_file.open(fileName, std::ofstream::out | std::ofstream::app);
	if (m_file.is_open()) {
		LOG_INFO("Open log file: " + fileName);
	}
	else {
		throw "Can't open the given file.";
	}
}

Logger& Logger::operator<<(const std::string& logMessage)
{
	m_file << logMessage;
	return *this;
}

Logger& Logger::operator<<(const LoggerLevel& level)
{
	auto now = std::chrono::system_clock::now();
	switch (level) {
	case LoggerLevel::ERROR:
		m_file << "[ERROR] ";
		break;
	case LoggerLevel::INFO:
		m_file << "[INFO]  ";
		break;
	default:
		m_file << "[WARING]";
		break;
	}
	return *this;
}

void Logger::log(const LoggerLevel& level, const std::string logMessage)
{
	const auto currentDateTime = std::chrono::system_clock::now();
	const auto currentDateTimeTimeT = std::chrono::system_clock::to_time_t(currentDateTime);
	struct tm timeinfo;
	errno_t result = localtime_s(&timeinfo,&currentDateTimeTimeT);
	std::string timeString = std::to_string(timeinfo.tm_mday) + '-' + std::to_string(timeinfo.tm_mon + 1) + '-' +
			std::to_string(timeinfo.tm_year + 1900) + ' ' + std::to_string(timeinfo.tm_hour) + 
			':' + std::to_string(timeinfo.tm_min);

	*this <<  "[" << timeString <<"] " << level << " " << logMessage << "\n";
}
