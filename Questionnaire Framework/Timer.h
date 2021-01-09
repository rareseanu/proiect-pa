#pragma once
#include <functional>
#include <iostream>
#include<thread>
#include <chrono>

class Timer
{
public:
	__declspec(dllexport) void SetTimeout(const std::function<void()>& func,int waitTime);
	__declspec(dllexport) int GetTimeLeft()const;
	__declspec(dllexport) bool IsRunning();
	__declspec(dllexport) void Start();
	__declspec(dllexport) void Stop();
private:
	std::function<void()> m_functionToRun;
	int m_waitingTime = 0;
	int m_endTime = 0;
	int m_timeLeft = 0;
	bool m_running = false;
};

