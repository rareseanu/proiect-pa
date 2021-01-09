#pragma once
#include <ostream>
#include <fstream>
#include <chrono>
#include <sstream>
#include <iostream>
#include <iomanip>

class Logger
{
private:
	std::ofstream m_file;
	static Logger* instance;
	__declspec(dllexport) Logger(const std::string& fileName);
	static bool m_activated;
public:
	enum class LoggerLevel {
		Info,
		Warning,
		Error
	};

	__declspec(dllexport) Logger(const Logger&) = delete;
	__declspec(dllexport) Logger(Logger&&) = delete;
	__declspec(dllexport) Logger& operator=(const Logger&) = delete;
	__declspec(dllexport) Logger& operator=(Logger&&) = delete;

	__declspec(dllexport) static void ActivateLogger();
	__declspec(dllexport) static Logger* getLogger(const std::string& fileName = "log.txt");

	__declspec(dllexport) Logger& operator <<(const std::string& logMessage);
	__declspec(dllexport) Logger& operator <<(const LoggerLevel& level);

	__declspec(dllexport) std::string getCurrentTime();
	__declspec(dllexport) void log(const LoggerLevel& level, const std::string logMessage);
};

#define LOG_WARN(message)   Logger::getLogger()->log(Logger::LoggerLevel::Warning, message)
#define LOG_INFO(message)   Logger::getLogger()->log(Logger::LoggerLevel::Info   , message)
#define LOG_ERROR(message)  Logger::getLogger()->log(Logger::LoggerLevel::Error  , message)




