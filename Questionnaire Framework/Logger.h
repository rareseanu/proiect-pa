#pragma once
#include <ostream>
#include <fstream>

class Logger
{
private:
	std::ofstream m_file;
	static Logger* instance;
	Logger(const std::string& fileName);
public:
	enum class LoggerLevel {
		Info,
		Warning,
		Error
	};

	static Logger* getLogger(const std::string& fileName = "log.txt");

	Logger& operator <<(const std::string& logMessage);
	Logger& operator <<(const LoggerLevel& level);

	std::string getCurrentTime();
	void log(const LoggerLevel& level, const std::string logMessage);
};

#define LOG_WARN(message)   Logger::getLogger()->log(Logger::LoggerLevel::Warning, message)
#define LOG_INFO(message)   Logger::getLogger()->log(Logger::LoggerLevel::Info   , message)
#define LOG_ERROR(message)  Logger::getLogger()->log(Logger::LoggerLevel::Error  , message)





