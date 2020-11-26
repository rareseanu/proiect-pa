#pragma once
#include <functional>
#include <iostream>
#include<thread>
#include <chrono>

class Timer
{
public:
	void setTimeout(const std::function<void()> &func,int waitTime);
	bool isRunning();
	void start();
private:
	std::function<void()> m_functionToRun;
	int m_waitingTime = 0;
	int m_endTime = 0;
	bool m_running = false;
};

