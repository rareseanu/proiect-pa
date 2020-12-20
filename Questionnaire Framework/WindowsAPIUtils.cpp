#include "WindowsAPIUtils.h"

HWND GetHandlerFromTitle(LPCWSTR windowTitle, bool isConsole)
{
	HWND windowHandle;
	if (isConsole) {
		windowHandle = FindWindow(L"ConsoleWindowClass", windowTitle);
	}
	else {
		windowHandle = FindWindow(windowTitle, NULL);
	}
	if (!windowHandle) {
		std::cout << "No window with the given title.\n";
		return NULL;
	}
	std::wcout << "Window " << windowTitle << " found.\n";
	return windowHandle;
}

std::string GetLastErrorString() {
	DWORD errorID = GetLastError();
	LPSTR errorBuffer = nullptr;
	size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL, errorID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&errorBuffer, 0, NULL);
	std::string message(errorBuffer, size);

	return message;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	std::cout << message << std::endl;
	return DefWindowProc(hWnd, message, wParam, lParam);
}

HHOOK SetupHook(LPCWSTR windowTitle, std::wstring dllName, bool isConsole)
{
	HWND windowHandle = GetHandlerFromTitle(windowTitle, isConsole);
	const std::wstring consoleClassName(L"ConsoleWindowClass");

	char className[256];
	if (!GetClassName(windowHandle, (LPWSTR) className, 256)) {
		std::cout << "ClassName not found!\n";
		return NULL;
	}

	DWORD processId;
	DWORD tid = GetWindowThreadProcessId(windowHandle, &processId);
	std::cout << "Initial console id: " << tid << '\n';
	HWND messageOnlyHandle;
	if (consoleClassName == (LPWSTR)className) {
		WNDCLASSEX wc = { 0 };
		wc.cbSize = sizeof(wc);
		wc.lpfnWndProc = WindowProc;
		wc.hInstance = GetModuleHandle(NULL);
		wc.lpszClassName = L"messageOnly";

		if (!RegisterClassEx(&wc)) {
			std::cout << "Error while registering the message-only window class.\n";
			return NULL;
		}

		messageOnlyHandle = CreateWindowEx(0, L"messageOnly", NULL, 0, 0, 0,0, 0,
			HWND_MESSAGE, NULL, GetModuleHandle(NULL), NULL);
		if (!messageOnlyHandle) {
			std::cout << GetLastErrorString();
			return NULL;
		}
		//tid = GetWindowThreadProcessId(messageOnlyHandle, &processId);
		//ChangeWindowMessageFilterEx(messageOnlyHandle, WM_KILLFOCUS, MSGFLT_ALLOW, 0);
		std::cout << "Message-only window created\n";
		ShowWindow(messageOnlyHandle, 5);

	}
	HWND test = FindWindowEx(HWND_MESSAGE, NULL,  L"someClass", NULL);
	DWORD pid;
	DWORD testba;
	testba = GetWindowThreadProcessId(test, &pid);
	std::cout << testba;
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
	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	if (hook == NULL) {
		FreeLibrary(dll);
		return NULL;
	}
	std::cout << "\nAjuns\n";
	return hook;

}