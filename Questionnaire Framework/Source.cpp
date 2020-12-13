#include "TerminalQuestionnaire.h"
#include <string>
#include <Windows.h>
#include "WindowsAPIUtils.h"

int main() {
	//HHOOK hook = SetupHook(L"Notepad", L"WindowsHooking.dll");
	//printf("Press enter to unhook.\n");
	//getchar();
	//UnhookWindowsHookEx(hook);
	TerminalQuestionnaire test(4, 3670);
	test.Start();
}
