#include <windows.h>
#include "SMApplication.h"

/***
 *	API ENTRY
 */
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){
	//	Start our app
	SMExitCode appCode = SMExitCodeFail;
	SMApplication* app = SMApplication::instance();

	app->setHandle(hInstance);
	appCode = app->start();

	return appCode;
}