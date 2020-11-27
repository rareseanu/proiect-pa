#pragma once
#include <ostream>
#include <fstream>

class Logger
{
private:
	std::ofstream m_file;
public:
	enum class LoggerLevel {
		INFO,
		WARNING,
		ERROR
	};

	Logger(const std::string& fileName = "log.txt");
	Logger(Logger const&) = delete;
	
	Logger& operator <<(const std::string& logMessage);
	Logger& operator <<(const LoggerLevel& level);

	void log(const LoggerLevel& level, const std::string logMessage);
	#define LOG_WARN(message)   log(Logger::LoggerLevel::WARNING, message)
	#define LOG_INFO(message)   log(Logger::LoggerLevel::INFO   , message)
	#define LOG_ERROR(message)  log(Logger::LoggerLevel::ERROR  , message)
};


