#include "Timer.h"

void Timer::SetTimeout(const std::function<void()> &func, int waitTime)
{
	m_functionToRun = func;
	m_waitingTime = waitTime;
	m_timeLeft = waitTime;
}

int Timer::GetTimeLeft() const
{
	return m_timeLeft;
}

bool Timer::IsRunning()
{
	return m_running;
}

void Timer::Start()
{
	static int lastSecond = 0;
	int currentTime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	if (m_running == false) {		
		m_endTime = m_waitingTime+currentTime;

		m_running = true;
	}
	if (m_running == true) {
		while(m_timeLeft>0) {
			currentTime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
			m_timeLeft = m_endTime - currentTime;
			if (lastSecond != m_timeLeft) {
				lastSecond = m_timeLeft;
			}
		}
		m_functionToRun();
		m_running = false;
		lastSecond = 0;
		m_timeLeft = 0;
	}
}
