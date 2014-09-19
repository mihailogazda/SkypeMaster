#include "SkypeMasterDLL.h"

//	global hook instance
HHOOK g_GlobalHook = NULL;

//	Listener method
LRESULT CALLBACK SMListener(int nCode, WPARAM wParam, LPARAM lParam){
	//	OK to process
	if (nCode >= 0){
		LPMSG msg = (LPMSG)lParam;
		LPCWPSTRUCT msg2 = (LPCWPSTRUCT)lParam;
		if (msg->message == SC_CLOSE){
			//	Window is closing - forward to main app
			HWND mainWindow = FindWindow(g_StrWindowClass, g_StrWindowTitle);
			return SendMessage(mainWindow, SM_CLOSE, (WPARAM)msg2->hwnd, 0);
		}
	}
	//	Hook chaining - forward
	return CallNextHookEx(g_GlobalHook, nCode, wParam, lParam);
}

bool WINAPI SMInstallHook()
{
	bool state = false;
	extern HINSTANCE g_GlobalInstance;

	//	Set hook
	g_GlobalHook = SetWindowsHookEx(WH_CALLWNDPROC, SMListener, g_GlobalInstance, 0);
	state = g_GlobalHook != 0;
	
	//	return state
	return state;
}

void WINAPI SMUninstallHook()
{
	//	Remove hook
	if (g_GlobalHook){
		UnhookWindowsHookEx(g_GlobalHook);
		g_GlobalHook = NULL;
	}
}
