#include <Windows.h>
#include <iostream>
#include "Hack.h"
DWORD WINAPI OnDllAttach(PVOID base)
{
	AllocConsole();
	freopen_s((FILE**)stdin,"CONIN$","r",stdin);
	freopen_s((FILE**)stdout,"CONOUT$","w",stdout);
	SetConsoleTitleA("Aimbot - Debug");

	while (!(GetAsyncKeyState(VK_DELETE) & 0x8000))
	{
		Run();
		Sleep(1);
	}
	FreeLibraryAndExitThread(static_cast<HMODULE>(base),0);
}

VOID WINAPI OnDllDetach()
{
#ifdef _DEBUG
	fclose((FILE*)stdin);
	fclose((FILE*)stdout);

	HWND hw_ConsoleHwnd = GetConsoleWindow();
	FreeConsole();
	PostMessageW(hw_ConsoleHwnd, WM_CLOSE, 0, 0);
#endif
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);
		CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)OnDllAttach,hModule,NULL,NULL);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		OnDllDetach();
	}
	return true;
}

