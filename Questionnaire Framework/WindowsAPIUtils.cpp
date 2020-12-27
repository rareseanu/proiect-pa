#include "WindowsAPIUtils.h"
#include "QuestionnaireFramework.h"

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

void MinimizeOtherApps(HWND questionnaireHandle) {
	HWND hwnd = FindWindow(L"Shell_TrayWnd", NULL);
	SendMessage(hwnd, WM_COMMAND, (WPARAM)419, 0); //minimize all
	Sleep(500);
	SendMessage(questionnaireHandle, WM_SYSCOMMAND, SC_MAXIMIZE, 0); //maximize questionnaire window
}

std::wstring GetUniqueWindowTitle() {
	DWORD tickCount = GetTickCount();
	DWORD processID = GetCurrentProcessId();
	std::wstring title = std::to_wstring(tickCount);
	title.push_back('/');
	title += std::to_wstring(processID);
	return title;
}

HHOOK SetupHook(LPCWSTR windowTitle, std::wstring dllName, bool isConsole, QuestionnaireFramework* quiz)
{
	HWND windowHandle = GetHandlerFromTitle(windowTitle, isConsole);
	const std::wstring consoleClassName(L"ConsoleWindowClass");
	MinimizeOtherApps(windowHandle);
	char className[256];
	if (!GetClassName(windowHandle, (LPWSTR) className, 256)) {
		std::cout << "ClassName not found!\n";
		return NULL;
	}

	DWORD processId;
	DWORD tid = GetWindowThreadProcessId(windowHandle, &processId);
	HWND messageOnlyHandle;
	//TODO: Research other ways to receive messages from console apps. Polling inefficient.
	if (consoleClassName == (LPWSTR)className) {
		std::thread checkFocus([quiz]() {
			while (true) {
				if (GetForegroundWindow() != GetConsoleWindow()) {
					quiz->SetCheatingDetected();
					return NULL;
				}
			}
		});
		checkFocus.detach();
		/*WNDCLASSEX wc = { 0 };
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
		}*/
		//tid = GetWindowThreadProcessId(messageOnlyHandle, &processId);
		//ChangeWindowMessageFilterEx(messageOnlyHandle, WM_KILLFOCUS, MSGFLT_ALLOW, 0);
		//std::cout << "Message-only window created\n";
		//ShowWindow(messageOnlyHandle, 5);
	}
	TCHAR path[MAX_PATH];
	DWORD dwRes = GetModuleFileName(NULL, (LPWSTR)path, MAX_PATH);
	if (!dwRes) {
		std::cout << "Directory not found.\n";
		return NULL;
	}
	std::wstring modulePath(path);
	std::wstring nameDll(dllName);
	std::wstring pathDll = modulePath.substr(0, modulePath.find_last_of('\\') + 1) + nameDll;
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