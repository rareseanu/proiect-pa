#include <windows.h>
#include <fstream>
#include "../Questionnaire Framework/Logger.cpp"
#include <functional>
bool* cheatingDetected = new bool;
std::function<void()> *m_x;

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		LOG_INFO("DLL process attach function called.");
		break;
	case DLL_PROCESS_DETACH:
		LOG_INFO("DLL process detach function called.");
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	}
	return true;
}

extern "C" __declspec(dllexport) bool GetCheating() {
	return *cheatingDetected;
}

extern  "C" __declspec(dllexport) void SetQuiz(std::function<void()> *x) {
	m_x = x;
}

extern "C" __declspec(dllexport) int HookFunction(int code, WPARAM wParam, LPARAM lParam) {
	LPCWPSTRUCT pt_stMessage = (LPCWPSTRUCT)lParam;
	if (code >= 0)
	{
		if (pt_stMessage->message == WM_ACTIVATE && pt_stMessage->wParam == WA_INACTIVE)
		{
			std::fstream fileStream;
			fileStream.open("C:\\temp\\test.txt", std::fstream::out | std::fstream::app);
			fileStream << "INTRAT" << '\n';
			fileStream.close();
		}
		return(CallNextHookEx(NULL, code, wParam, lParam));
	}
}