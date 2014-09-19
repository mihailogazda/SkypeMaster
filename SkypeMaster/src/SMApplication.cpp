#include "SMApplication.h"
#include "SMDialogBox.h"
#include <Shlwapi.h>

/**
 *	Known skype window classes we will check.
 */
TCHAR* g_SkypeClasses[] = {
	TEXT("TLoginForm"),
	TEXT("tSkMainForm")
};

SMApplication::SMApplication()
{
	_instance = NULL;
}

SMApplication* SMApplication::instance()
{
	static SMApplication app;
	return &app;
}


HINSTANCE SMApplication::getHandle() const
{
	return _instance;
}

void SMApplication::setHandle(HINSTANCE instance)
{
	_instance = instance;
}

SMWindow* SMApplication::getWindow()
{
	return &_window;
}

SMStateManager* SMApplication::getStateManager()
{
	return &_stateManager;
}

SMExitCode SMApplication::start()
{
	//	Create listener window
	if (!_window.create())
		return SMExitCodeFailCannotCreateWindow;

	//	Activate hook
	if (!_hookManager.install()){
		SMDialogBox::showMessage(TEXT("Cannot install hook. Failure."), TEXT("SkypeMaster"));
		return SMExitCodeFailCannotInstallHook;
	}

	//	Message listener
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0) != 0){
		//	Process messages
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		//	Check for exit
		if (_stateManager.getState() == SMStateClosing)
			break;
	}

	//	Free the resources
	_hookManager.uninstall();
	_window.close();

	return SMExitCodeSuccess;
}

bool SMApplication::processWindowCloseEvent(HWND window)
{
	//	Read window class
	TCHAR windowCls[1000];
	int v = GetClassName(window, windowCls, 1000);
	DWORD err = GetLastError();

	//	Count known classes
	int count = sizeof(g_SkypeClasses) / sizeof(TCHAR*);

	for (int i = 0; i < count; i++){
		TCHAR* txt = g_SkypeClasses[i];
		if (StrCmp(txt, windowCls) == 0){
			//	Found Skype class
			if (SMDialogBox::showMessage(
					TEXT("Do you want to quit Skype?"), 
					TEXT("Quit skype"), 
					SMDialogQuestion, window) == IDYES)
			{
				DWORD dwID = 0;
				GetWindowThreadProcessId(window, &dwID);
				HANDLE skype = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwID);
				if (skype){
					//	Actual kill
					TerminateProcess(skype, 0);
				}
				return true;
			}

			break;
		}
	}

	return false;
}

