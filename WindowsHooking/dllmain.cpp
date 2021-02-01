#include <windows.h>
#include <fstream>
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
		break;
	case DLL_PROCESS_DETACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	}
	return true;
}

extern  "C" __declspec(dllexport) void SetCallbackFunction(std::function<void()> *function) {
	functionToCall = function;
}

const std::string GetLastErrorString() {
	DWORD errorID = GetLastError();
	LPSTR errorBuffer = nullptr;
	size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL, errorID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&errorBuffer, 0, NULL);
	std::string message(errorBuffer, size);

	return message;
}

extern "C" __declspec(dllexport) LRESULT HookFunction(int code, WPARAM wParam, LPARAM lParam) {
	LPCWPSTRUCT pt_stMessage = (LPCWPSTRUCT)lParam;
	if (code >= 0)
	{
		TCHAR path[MAX_PATH];
		DWORD dwRes = GetModuleFileName(NULL, (LPWSTR)path, MAX_PATH);
		std::wstring modulePath(path);
		std::wstring fileName(L"dllInfo.txt");
		std::wstring pathDLLinfo = modulePath.substr(0, modulePath.find_last_of('\\') + 1) + fileName;

		DWORD quizPID = GetCurrentProcessId();
		std::string error = GetLastErrorString();
		
		if (pt_stMessage->message == WM_ACTIVATEAPP && pt_stMessage->wParam == FALSE) {

			std::fstream fileStream;
			fileStream.open(pathDLLinfo, std::fstream::out | std::fstream::app);
			fileStream << "Quiz pID: " << quizPID << '\n';
			fileStream << error << '\n';
			fileStream.close();

			(*functionToCall)();
		}

		return(CallNextHookEx(NULL, code, wParam, lParam));
	}
	return -1;
}