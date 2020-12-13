#pragma once
#include <Windows.h>
#include <string>
#include <iostream>
HHOOK SetupHook(LPCWSTR windowTitle, std::wstring dllName);