#pragma once
#include <Windows.h>
#include <string>
#include <iostream>

HWND GetHandlerFromTitle(LPCWSTR windowTitle, bool isConsole);
std::string GetLastErrorString();
HHOOK SetupHook(LPCWSTR windowTitle, std::wstring dllName, bool isConsole);