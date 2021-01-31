#pragma once
#include <Windows.h>
#include <string>
#include <iostream>
#include <thread>

class QuestionnaireFramework; //Forward declaration to avoid circular include dependency.

__declspec(dllexport) HWND GetHandlerFromTitle(LPCSTR windowTitle, bool isConsole);
__declspec(dllexport) const std::string GetLastErrorString();
__declspec(dllexport) const std::string GetUniqueWindowTitle();

__declspec(dllexport) HHOOK SetupGUIAnticheat(LPCSTR windowTitle, const std::wstring& dllName, QuestionnaireFramework* quiz);
__declspec(dllexport) LRESULT CALLBACK MouseHookProc(int nCode, WPARAM wParam, LPARAM lParam);

__declspec(dllexport) void SetupConsoleAnticheat(QuestionnaireFramework* quiz);
__declspec(dllexport) void MinimizeOtherApps(HWND questionnaireHandle);