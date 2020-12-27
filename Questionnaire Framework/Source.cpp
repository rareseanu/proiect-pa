#include "TerminalQuestionnaire.h"
#include <string>
#include <Windows.h>
#include "WindowsAPIUtils.h"

int main() {
	SetConsoleTitle(L"Test");
	Sleep(2000);
	HHOOK hook = SetupHook(L"Test", L"WindowsHooking.dll", true);
	if (hook == NULL)
		return 0;
	TerminalQuestionnaire test(4, 3670);
	test.Start();
	printf("Press enter to unhook.\n");
	getchar();
	UnhookWindowsHookEx(hook);
}
