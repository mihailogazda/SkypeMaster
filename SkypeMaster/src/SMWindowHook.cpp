#include "SMWindowHook.h"
#include "SkypeMasterDLL.h"
#include "SMApplication.h"

SMWindowHook::SMWindowHook()
{

}

SMWindowHook::~SMWindowHook()
{
	uninstall();
}


bool SMWindowHook::install()
{
	bool status = false;
	status = SMInstallHook();
	return status;
}

void SMWindowHook::uninstall()
{
	SMUninstallHook();
}
