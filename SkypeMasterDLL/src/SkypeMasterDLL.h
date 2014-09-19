#pragma once
//	Define exports for DLL
#include <windows.h>

#ifdef SKYPEMASTERDLL_EXPORTS
	#define SKYPEMASTERDLL_API __declspec(dllexport)
#else
	#define SKYPEMASTERDLL_API __declspec(dllimport)
#endif

/**
 *	User message for closing, gets forwarded to main app
 *	wParam - HWND where message originated
 *	lParam - 0
 */
#define SM_CLOSE WM_USER + 102

//	Window title and class shared between DLL and App
static TCHAR* g_StrWindowClass = TEXT("SMWindowClass");
static TCHAR* g_StrWindowTitle = TEXT("SMWindowTitleIsHidden");

/***
 *	Sets window hook that listens for all closed window messages
 */
bool SKYPEMASTERDLL_API WINAPI SMInstallHook();

/***
 *	Releases the hook 
 */
void SKYPEMASTERDLL_API WINAPI SMUninstallHook();