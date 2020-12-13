#pragma once
#include <Windows.h>
#include <string>
#include <iostream>

HWND GetHandlerFromTitle(LPCWSTR windowTitle);
HHOOK SetupHook(LPCWSTR windowTitle, std::wstring dllName);