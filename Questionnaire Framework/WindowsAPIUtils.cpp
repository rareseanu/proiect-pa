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
	std::thread thread([]() {
		HWND hwnd = FindWindow(L"Shell_TrayWnd", NULL);
		SendMessage(hwnd, WM_COMMAND, (WPARAM)419, 0); //minimize all
		});
	thread.join();
	Sleep(500);
	SetForegroundWindow(questionnaireHandle);
	ShowWindow(questionnaireHandle, SW_SHOWMAXIMIZED);
}

std::wstring GetUniqueWindowTitle() {
	DWORD tickCount = GetTickCount64();
	DWORD processID = GetCurrentProcessId();
	std::wstring title = std::to_wstring(tickCount);
	title.push_back('/');
	title += std::to_wstring(processID);
	return title;
}

HHOOK SetupGUIAnticheat(LPCWSTR windowTitle, std::wstring dllName, QuestionnaireFramework* quiz)
{
	HWND windowHandle = GetHandlerFromTitle(windowTitle, false);

	MinimizeOtherApps(windowHandle);
	char className[MAX_CLASS_NAME];
	if (!GetClassNameA(windowHandle, className, MAX_CLASS_NAME)) {
		std::cout << "ClassName not found!\n";
		return NULL;
	}

	DWORD processID;
	DWORD tid = GetWindowThreadProcessId(windowHandle, &processID);

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

	std::function<void()>* getMax = new std::function<void()>(std::bind(&QuestionnaireFramework::SetCheatingDetected, quiz));
	void(*setQuiz)(std::function<void()>*) = (void(*)(std::function<void()>*))GetProcAddress(dll, "SetQuiz");
	setQuiz(getMax);

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

void SetupConsoleAnticheat(QuestionnaireFramework* quiz)
{
	HWND consoleHWND = GetConsoleWindow();
	MinimizeOtherApps(consoleHWND);

	std::thread checkFocus([quiz]() {
		while (true) {
			if (GetForegroundWindow() != GetConsoleWindow()) {
				quiz->SetCheatingDetected();
				return NULL;
			}
		}
		});
	checkFocus.detach();
}
