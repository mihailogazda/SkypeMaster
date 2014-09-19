SkypeMaster
===========
We all know and love Skype but its latest addition like no more option to close it fully without going to the taskbar and tapping "Quit" can be annoying some times.

This application injects to Skype and offers "Do you want to close Skype?" message when you are closing it.

###Installation
Currently there are is nothing to set up, just run SkypeMaster.exe and you are all set.

If the app gets any traction I will write easy install program for it.

###How to remove it
Application in this point has to be killed via Task Manager. You will find it as "SkypeMaster.exe *32" in processes list.

###How it works
App uses Windows Hooks to detect when WM_CLOSE message is sent and forwards that to the main application that then asks user if he wants to kill Skype. Skype is blocked untill user decides weather to kill it or not.

