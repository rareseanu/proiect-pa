#include "WindowsAPIUtils.h"

HHOOK SetupHook(LPCWSTR windowTitle, std::wstring dllName)
{
	//HWND hShellTray = FindWindow(L"ConsoleWindowClass", szShellTray); - for console window
	HWND windowHandle = FindWindow(windowTitle, NULL);

	DWORD processId;
	DWORD tid = GetWindowThreadProcessId(windowHandle, &processId);

	TCHAR path[MAX_PATH];
	DWORD dwRes = GetModuleFileName(NULL, (LPWSTR)path, MAX_PATH);

	std::wstring modulePath(path);
	std::wstring nameDll(dllName);
	std::wstring pathDll = modulePath.substr(0, modulePath.find_last_of('\\') + 1) + nameDll;
	std::wcout << pathDll;
	LPWSTR lpFullPath = (LPWSTR)(pathDll.c_str());

	HMODULE dll = LoadLibrary(lpFullPath);
	HOOKPROC addr = (HOOKPROC)GetProcAddress(dll, "HookFunction");

	HHOOK hook = SetWindowsHookEx(WH_CALLWNDPROC, addr, dll, tid);

	return hook;
}