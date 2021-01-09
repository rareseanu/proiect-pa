#pragma once
#include <ostream>
#include <fstream>
#include <chrono>
#include <sstream>
#include <iostream>
#include <iomanip>

class __declspec(dllexport) Logger
{
private:
	std::ofstream m_file;
	static Logger* instance;
	Logger(const std::string& fileName);
	static bool m_activated;
public:
	enum class LoggerLevel {
		Info,
		Warning,
		Error
	};

	Logger(const Logger&) = delete;
	Logger(Logger&&) = delete;
	Logger& operator=(const Logger&) = delete;
	Logger& operator=(Logger&&) = delete;

	static void ActivateLogger();
	static Logger* getLogger(const std::string& fileName = "log.txt");

	Logger& operator <<(const std::string& logMessage);
	Logger& operator <<(const LoggerLevel& level);

	std::string getCurrentTime();
	void log(const LoggerLevel& level, const std::string logMessage);
};

#define LOG_WARN(message)   Logger::getLogger()->log(Logger::LoggerLevel::Warning, message)
#define LOG_INFO(message)   Logger::getLogger()->log(Logger::LoggerLevel::Info   , message)
#define LOG_ERROR(message)  Logger::getLogger()->log(Logger::LoggerLevel::Error  , message)




