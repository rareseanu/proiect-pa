#include "Timer.h"

void Timer::setTimeout(const std::function<void()> &func, int waitTime)
{
	m_functionToRun = func;
	m_waitingTime = waitTime;
}

bool Timer::isRunning()
{
	return m_running;
}

void Timer::start()
{
	static int lastSecond = 0;
	static int timeLeft = 0;
	int currentTime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	if (m_running == false) {		
		m_endTime = m_waitingTime+currentTime;
		m_running = true;
	}
	if (m_running == true) {
		while(m_endTime > currentTime) {
			currentTime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
			timeLeft = m_endTime - currentTime;
			if (lastSecond != timeLeft) {
				lastSecond = timeLeft;
				std::cout << timeLeft << std::endl;
			}
		}
		if (timeLeft <= 0) {
			m_functionToRun();
			m_running = false;
			lastSecond = 0;
			timeLeft = 0;
		}
	}
}
