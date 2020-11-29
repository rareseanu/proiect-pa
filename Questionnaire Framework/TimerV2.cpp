#include "TimerV2.h"

void TimerV2::cronometru(int ore, int minute, int secunde)
{
	for (;;)
	{
		if (ore == 0 && minute == 0 && secunde == 0)
		{
			break;
		}
		if (secunde == 0 && minute == 0)
		{
			minute = 60;
			ore--;
		}
		if (secunde == 0)
		{
			secunde = 60;
			minute--;
		}
		cout << ore << ":" << minute << ":" << secunde--;
		Sleep(1000);
	}
}
