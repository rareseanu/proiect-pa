#pragma once
#include <Windows.h>
#include <string>
#include <iostream>
#include <thread>

HWND GetHandlerFromTitle(LPCWSTR windowTitle, bool isConsole);
std::string GetLastErrorString();
void MinimizeOtherApps(HWND questionnaireHandle);
HHOOK SetupHook(LPCWSTR windowTitle, std::wstring dllName, bool isConsole);