#pragma once
#include <windows.h>

class SMWindow {
private:
	/***
	 *	Native window handle.
	 */
	HWND _handle;
	
	/***
	 *	WNDPROC for messages.
	 *	\param hWnd Window handle
	 *	\param msg Message
	 *	\param wParam WPARAM
	 *	\param lParam LPARAM
	 *	\return DefWindowProc return value, always
	 */
	static LRESULT CALLBACK statWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

public:
	SMWindow();
	virtual ~SMWindow();

	/**
	 *	Creates main window.
	 *	\return True if created successfully
	 */
	bool create();
	/**
	 *	Closes main window.
	 */
	void close();
	/**
	 *	Gets native window handle of our main window.
	 *	\return HWND or 0
	 */
	HWND getHandle() const;
};