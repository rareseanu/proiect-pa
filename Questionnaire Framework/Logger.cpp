#include "Logger.h"
#include <chrono>
#include <sstream>
#include <iostream>
#include <iomanip>

Logger* Logger::instance;

Logger::Logger(const std::string& fileName)
{
	m_file.open(fileName, std::ofstream::out | std::ofstream::app);
	if (!m_file.is_open()) {
		throw "Can't open the given file.";
	}
}

Logger* Logger::getLogger(const std::string& fileName)
{
	if (!instance) {
		std::cout << fileName;
		instance = new Logger(fileName);
	}
	return instance;
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
	case LoggerLevel::Error:
		m_file << "[ERROR] ";
		break;
	case LoggerLevel::Info:
		m_file << "[INFO]  ";
		break;
	default:
		m_file << "[WARNING]";
		break;
	}
	return *this;
}

std::string Logger::getCurrentTime() {
	const auto currentDateTime = std::chrono::system_clock::now();
	const auto currentDateTimeTimeT = std::chrono::system_clock::to_time_t(currentDateTime);
	struct tm timeinfo;
	errno_t result = localtime_s(&timeinfo, &currentDateTimeTimeT);
	std::stringstream sStream;
	timeinfo.tm_mon = 3;
	sStream << std::setw(2) << std::setfill('0') << std::to_string(timeinfo.tm_mday) << '-'
		    << std::setw(2) << std::setfill('0') << std::to_string(timeinfo.tm_mon + 1) << '-' 
			<< std::to_string(timeinfo.tm_year + 1900) << ' '
			<< std::setw(2) << std::setfill('0') << std::to_string(timeinfo.tm_hour) << ':'
			<< std::setw(2) << std::setfill('0') << std::to_string(timeinfo.tm_min) << ':' 
			<< std::setw(2) << std::setfill('0') << std::to_string(timeinfo.tm_sec);
	return sStream.str();
}

void Logger::log(const LoggerLevel& level, const std::string logMessage)
{
	*this << "[" << getCurrentTime() << "] " << level << " " << logMessage << "\n";
}
