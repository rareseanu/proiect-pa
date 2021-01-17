#include <windows.h>
#include <fstream>
#include "../Questionnaire Framework/Logger.cpp"
#include <functional>

std::function<void()> *functionToCall;

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

extern  "C" __declspec(dllexport) void SetQuiz(std::function<void()> *function) {
	functionToCall = function;
}

extern "C" __declspec(dllexport) int HookFunction(int code, WPARAM wParam, LPARAM lParam) {
	LPCWPSTRUCT pt_stMessage = (LPCWPSTRUCT)lParam;
	if (code >= 0)
	{
		if(GetProcessId((HANDLE) pt_stMessage->lParam) != GetCurrentProcessId()) {
			if ((pt_stMessage->message == WM_ACTIVATE && pt_stMessage->wParam == WA_INACTIVE) || 
				(pt_stMessage->message == WM_SIZE && pt_stMessage->wParam == SIZE_MINIMIZED))
			{
				(*functionToCall)();
				std::fstream fileStream;
				fileStream.open("C:\\temp\\test.txt", std::fstream::out | std::fstream::app);
				fileStream << GetProcessId((HWND)lParam) << " " << GetCurrentProcessId() << '\n';
				fileStream.close();
			}
		}
		return(CallNextHookEx(NULL, code, wParam, lParam));
	}
}