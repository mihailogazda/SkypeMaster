#include "SMWindow.h"
#include "SMApplication.h"
#include "SkypeMasterDLL.h"

SMWindow::SMWindow()
{
	_handle = NULL;
}

SMWindow::~SMWindow()
{
	close();
}

bool SMWindow::create()
{
	bool status = false;
	
	WNDCLASSEX wcex;
	memset(&wcex, 0, sizeof(WNDCLASSEX));
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.hInstance = SMApplication::instance()->getHandle();
	wcex.lpszClassName = g_StrWindowClass;
	wcex.lpfnWndProc = statWndProc;

	//	Register window class
	if (RegisterClassEx(&wcex)){

		//	Create window
		_handle = CreateWindowEx(
			0,
			wcex.lpszClassName,
			g_StrWindowTitle,
			/*WS_VISIBLE | WS_SYSMENU*/0, 
			0, 0, 1024, 1024,
			NULL, NULL,
			wcex.hInstance,
			0);

		status = _handle != 0;

		if (status){
			//	Allow messaging between processes for UIPI
			ChangeWindowMessageFilterEx(_handle, SM_CLOSE, MSGFLT_ALLOW, NULL);	
		}
		
	}

	return status;
}

void SMWindow::close()
{
	if (_handle){
		CloseWindow(_handle);
		UnregisterClass(g_StrWindowClass, SMApplication::instance()->getHandle());
		_handle = NULL;
	}
}

HWND SMWindow::getHandle() const
{
	return _handle;
}

LRESULT CALLBACK SMWindow::statWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (msg == SM_CLOSE){
		HWND wnd = (HWND)wParam;
		if (SMApplication::instance()->processWindowCloseEvent(wnd))
			return 0;
	}
	else if (msg == WM_CLOSE){
		SMApplication::instance()->getStateManager()->setState(SMStateClosing);
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}


