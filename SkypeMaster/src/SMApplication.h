#pragma once
#include <windows.h>
#include "SMStateManager.h"
#include "SMWindowHook.h"
#include "SMWindow.h"

/**
 *	Possible exit codes for the application.
 */
typedef enum SMExitCode {
	SMExitCodeSuccess = 0,
	SMExitCodeFail = 1,
	SMExitCodeFailCannotCreateWindow = 2,
	SMExitCodeFailCannotInstallHook = 3,
	SMExitCodeDuplicateInstance = 4,
};

/***
*	Just simple application runner.
*/
class SMApplication {
private:
	/***
	 *	Application global instance.
	 */
	HINSTANCE _instance;

	/***
	 *	State manager.
	 */
	SMStateManager _stateManager;
	/***
	 *	Windows hook manager.
	 */
	SMWindowHook _hookManager;

	/**
	 *	Main application window that listens for messages.
	 */
	SMWindow _window;

	/**
	 *	Checks if app is already running.
	 *	So we don't have multiple instances.
	 *	\return true if running false otherwise.
	 */
	bool alreadyRunning();

	/*** Constructor (private */
	SMApplication();
public:

	/***
	 *	Sets application instance for further use.
	 *	\param instance
	 */
	void setHandle(HINSTANCE instance);
	/**
	 *	Gets global app instance.
	 *	\return instance or NULL
	 */
	HINSTANCE getHandle() const;

	/**
	 *	Starts application and exits when its done.
	 *	\return Application exit code.
	 */
	SMExitCode start();

	/***
	 *	Application shared instance singleton.
	 *	\return Application instance
	 */
	static SMApplication* instance();

	/**
	 *	Gets main application window.
	 *	\return App window SMWindow reference
	 */
	SMWindow* getWindow();

	/**
	 *	Gets application state manager.
	 *	\return SMStateManager reference
	 */
	SMStateManager* getStateManager();

	/**
	 *	Processes window handle message received from DLL.
	 *	\param Handle from process that sent the message
	 *	\return true if app will be killed / false otherwise
	 */
	bool processWindowCloseEvent(HWND window);
};