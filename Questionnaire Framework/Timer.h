#pragma once
#include <functional>
#include <iostream>
#include<thread>
#include <chrono>

class Timer
{
public:
	void SetTimeout(const std::function<void()>& func,int waitTime);
	int GetTimeLeft()const;
	bool IsRunning();
	void Start();
	void Stop();
private:
	std::function<void()> m_functionToRun;
	int m_waitingTime = 0;
	int m_endTime = 0;
	int m_timeLeft;
	bool m_running = false;
};

