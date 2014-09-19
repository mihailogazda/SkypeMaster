#pragma once
#include <windows.h>

/***
 *	Initializes WIndows hook and starts DLL injection.
 */
class SMWindowHook {
private:
public:

	SMWindowHook();
	virtual ~SMWindowHook();

	/**
	 *	Sets window hook.
	 *	\return True if hook was set
	 */
	bool install();

	/**
	 *	Removes window hook.
	 */
	void uninstall();
};