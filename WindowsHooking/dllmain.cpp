#include <stdio.h>
#include <windows.h>
#include "../Questionnaire Framework/Logger.h"

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		LOG_INFO("DLL process attach function called.\n");
		break;
	case DLL_PROCESS_DETACH:
		LOG_INFO("DLL process detach function called.\n");
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	}
	return true;
}

extern "C" __declspec(dllexport) int HookFunction(int code, WPARAM wParam, LPARAM lParam) {
	LPCWPSTRUCT pt_stMessage = (LPCWPSTRUCT)lParam;
	if (code >= 0)
	{
		//0x8 - WN_KILLFOCUS message
		if (pt_stMessage->message == 0x8 && pt_stMessage->wParam != NULL)
		{
			LOG_INFO("WN_KILLFOCUS called.\n");
		}
	}
	return(CallNextHookEx(NULL, code, wParam, lParam));
}