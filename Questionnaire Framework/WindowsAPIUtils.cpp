#include "WindowsAPIUtils.h"

HWND GetHandlerFromTitle(LPCWSTR windowTitle)
{
	//HWND hShellTray = FindWindow(L"ConsoleWindowClass", windowTitle); - for console window
	HWND windowHandle;
	windowHandle = FindWindow(windowTitle, NULL);
	if (!windowHandle) {
		std::cout << "No window with the given title.\n";
		return NULL;
	}
	return windowHandle;
}

HHOOK SetupHook(LPCWSTR windowTitle, std::wstring dllName)
{
	HWND windowHandle = GetHandlerFromTitle(windowTitle);
	DWORD processId;
	DWORD tid = GetWindowThreadProcessId(windowHandle, &processId);

	TCHAR path[MAX_PATH];
	DWORD dwRes = GetModuleFileName(NULL, (LPWSTR)path, MAX_PATH);
	if (!dwRes) {
		std::cout << "Directory not found.\n";
		return NULL;
	}
	std::wstring modulePath(path);
	std::wstring nameDll(dllName);
	std::wstring pathDll = modulePath.substr(0, modulePath.find_last_of('\\') + 1) + nameDll;
	std::wcout << pathDll;
	LPWSTR lpFullPath = (LPWSTR)(pathDll.c_str());

	HMODULE dll = LoadLibrary(lpFullPath);
	if (dll == NULL) {
		std::cout << "DLL not found.\n";
		return NULL;
	}
	HOOKPROC addr = (HOOKPROC)GetProcAddress(dll, "HookFunction");
	if (addr == NULL) {
		std::cout << "There was an error while calling HookFunction.\n";
		return NULL;
	}
	HHOOK hook = SetWindowsHookEx(WH_CALLWNDPROC, addr, dll, tid);
	if (hook == NULL) {
		FreeLibrary(dll);
		return NULL;
	}
	return hook;
}