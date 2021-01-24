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
		DWORD processID;
		//DWORD currentProcessID = GetCurrentProcessId();
		GetWindowThreadProcessId(pt_stMessage->hwnd, &processID);
		//DWORD errorID = GetLastError();
		//LPSTR errorBuffer = nullptr;
		//size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		//	NULL, errorID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&errorBuffer, 0, NULL);
		//std::string message(errorBuffer, size);
		//
		//if (processID != currentProcessID) {
		if (pt_stMessage->message == WM_ACTIVATEAPP && pt_stMessage->wParam == FALSE) {
		//	|| (pt_stMessage->message == WM_SIZE && pt_stMessage->wParam == SIZE_MINIMIZED))
			std::fstream fileStream;
			fileStream.open("C:\\temp\\test.txt", std::fstream::out | std::fstream::app);
			fileStream << "PRIMIT " << '\n';
			fileStream << processID << " " << GetCurrentProcessId() << '\n';
			fileStream.close();
		}

		return(CallNextHookEx(NULL, code, wParam, lParam));
	}
}