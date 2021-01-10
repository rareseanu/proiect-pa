#pragma once
#include <Windows.h>
#include <string>
#include <iostream>
#include <thread>
class QuestionnaireFramework; //Forward declaration to avoid circular include dependency.

__declspec(dllexport) HWND GetHandlerFromTitle(LPCWSTR windowTitle, bool isConsole);
__declspec(dllexport) std::string GetLastErrorString();
__declspec(dllexport) void MinimizeOtherApps(HWND questionnaireHandle);
__declspec(dllexport) std::wstring GetUniqueWindowTitle();
__declspec(dllexport) HHOOK SetupHook(LPCWSTR windowTitle, std::wstring dllName, bool isConsole, QuestionnaireFramework* quiz);
__declspec(dllexport) bool CheckIfCheatingFromDll();