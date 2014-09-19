#pragma once
#include <windows.h>

/**
 *	Dialog types
 */
enum SMDialogBoxType {
	SMDialogInfo,
	SMDialogWarning,
	SMDialogError,
	SMDialogQuestion
};

/**
 *	Simple MessageBox wrapper class.
 *	Use this for notifying users.
 */
class SMDialogBox {
public:
	static int showMessage(TCHAR* message, TCHAR* title, SMDialogBoxType type = SMDialogInfo, HWND window = NULL);
};