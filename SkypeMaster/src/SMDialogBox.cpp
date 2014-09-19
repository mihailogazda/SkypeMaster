#include "SMDialogBox.h"

int SMDialogBox::showMessage(TCHAR* message, TCHAR* title, SMDialogBoxType type, HWND window)
{
	DWORD mType = MB_OK;

	switch (type){
	case SMDialogInfo:
		mType |= MB_ICONINFORMATION;
		break;
	case SMDialogWarning:
		mType |= MB_ICONWARNING;
		break;
	case SMDialogError:
		mType |= MB_ICONERROR;
	case SMDialogQuestion:
		mType = MB_YESNO | MB_ICONQUESTION;
	};
	
	return MessageBox(window, message, title, mType);
}
