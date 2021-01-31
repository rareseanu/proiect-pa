#include "WindowsAPIUtils.h"
#include "QuestionnaireFramework.h"

HWND GetHandlerFromTitle(LPCSTR windowTitle, bool isConsole)
{
	HWND windowHandle;
	if (isConsole) {
		windowHandle = FindWindowA("ConsoleWindowClass", windowTitle);
	}
	else {
		windowHandle = FindWindowA(NULL, windowTitle);
	}
	if (!windowHandle) {
		LOG_ERROR("[ANTICHEAT] No window with the given title.");
		return NULL;
	}
	LOG_INFO(std::string("[ANTICHEAT] Window ") + windowTitle + "  found.");
	return windowHandle;
}

const std::string GetLastErrorString() {
	DWORD errorID = GetLastError();
	LPSTR errorBuffer = nullptr;
	size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL, errorID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&errorBuffer, 0, NULL);
	std::string message(errorBuffer, size);
	if (errorID != 0) {
		LOG_ERROR(message);
	}
	return message;
}

void MinimizeOtherApps(HWND questionnaireHandle) {
	std::thread thread([]() {
		HWND hwnd = FindWindow(L"Shell_TrayWnd", NULL);
		SendMessage(hwnd, WM_COMMAND, (WPARAM)419, 0); //minimize all
		});
	thread.join();
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	SetForegroundWindow(questionnaireHandle);
	ShowWindow(questionnaireHandle, SW_SHOWMAXIMIZED);
	LOG_INFO("[ANTICHEAT] Minimized all applications and maximized the quiz.");
}

const std::string GetUniqueWindowTitle() {
	DWORD tickCount = GetTickCount64();
	DWORD processID = GetCurrentProcessId();
	std::string title = std::to_string(tickCount);
	title.push_back('/');
	title += std::to_string(processID);
	return title;
}

LRESULT CALLBACK MouseHookProc(int nCode, WPARAM wParam, LPARAM lParam) {
	MSLLHOOKSTRUCT* mouseStruct = (MSLLHOOKSTRUCT*)lParam;
	HWND handler = WindowFromPoint(mouseStruct->pt);
	DWORD currentMessagePid = 0;
	DWORD currentMessageTid = GetWindowThreadProcessId(handler, &currentMessagePid);
	DWORD quizPid = GetCurrentProcessId();

	if (nCode >= 0) {
		if (currentMessagePid == quizPid) {
			return CallNextHookEx(0, nCode, wParam, lParam);
		}
		else if(currentMessagePid != quizPid && (wParam == WM_LBUTTONDOWN || wParam == WM_LBUTTONUP ||
			wParam == WM_RBUTTONDOWN || wParam == WM_RBUTTONUP)) {
			int titleLength = GetWindowTextLengthA(handler);
			std::string title(titleLength, '\0');
			GetWindowTextA(handler, &title[0], titleLength);
			LOG_ERROR("[ANTICHEAT] User clicked outside the quiz. App name: " + title);
		}
	}
}

void DisableMouseOutsideQuiz() {
	std::thread messageLoop([]() {
		while (true) {
			MSG msg = { };
			if (GetMessage(&msg, 0, 0, 0)) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		});
	messageLoop.detach();
}

HHOOK SetupGUIAnticheat(LPCSTR windowTitle, std::wstring dllName, QuestionnaireFramework* quiz)
{
	HWND windowHandle = GetHandlerFromTitle(windowTitle, false);

	MinimizeOtherApps(windowHandle);

	DWORD processID;
	DWORD tid = GetWindowThreadProcessId(windowHandle, &processID);

	TCHAR path[MAX_PATH];
	DWORD dwRes = GetModuleFileName(NULL, (LPWSTR)path, MAX_PATH);
	if (!dwRes) {
		LOG_ERROR("[ANTICHEAT] Directory not found.");
		return NULL;
	}
	std::wstring modulePath(path);
	std::wstring nameDll(dllName);
	std::wstring pathDll = modulePath.substr(0, modulePath.find_last_of('\\') + 1) + nameDll;

	LPWSTR lpFullPath = (LPWSTR)(pathDll.c_str());

	HMODULE dll = LoadLibrary(lpFullPath);
	if (dll == NULL) {
		LOG_ERROR("[ANTICHEAT] DLL not found.");
		return NULL;
	}

	std::function<void()>* getMax = new std::function<void()>(std::bind(&QuestionnaireFramework::SetCheatingDetected, quiz));
	void(*setCallbackFunction)(std::function<void()>*) = (void(*)(std::function<void()>*))GetProcAddress(dll, "SetCallbackFunction");
	setCallbackFunction(getMax);

	HOOKPROC addr = (HOOKPROC)GetProcAddress(dll, "HookFunction");
	if (addr == NULL) {
		LOG_ERROR("[ANTICHEAT] There was an error while getting the HookFunction address.");
		return NULL;
	}
	HHOOK hook = SetWindowsHookEx(WH_CALLWNDPROC, addr, dll, tid);
	if (hook == NULL) {
		FreeLibrary(dll);
		return NULL;
	}
	LOG_INFO("[ANTICHEAT] Successfully installed CallWndProc hook.");
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
				LOG_INFO("[ANTICHEAT] Focus lost, cheating detected.");
				return NULL;
			}
		}
		});
	checkFocus.detach();
}
