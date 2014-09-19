SkypeMaster
===========
We all know and love Skype but its latest addition like no more option to close it fully without going to the taskbar and tapping "Quit" can be annoying some times.

This application injects to Skype and offers "Do you want to close Skype?" message when you are closing it.

###Installation
Currently there are is nothing to set up, just run SkypeMaster.exe and you are all set.

If the app gets any traction I will write easy install program for it.

Download **SkypeMasterBinary_latest.zip** from:

https://github.com/mihailogazda/SkypeMaster/raw/master/SkypeMasterBinary_latest.zip

Drag SkypeMaster.exe to the "AllPrograms/Startup" main menu item to start with PC. Other option is to add it manually using msconfig.exe utility. 

###How to remove it
Application in this point has to be killed via Task Manager. You will find it as "SkypeMaster.exe *32" in processes list.

###How it works
App uses Windows Hooks to detect when WM_CLOSE message is sent and forwards that to the main application that then asks user if he wants to kill Skype. Skype is blocked untill user decides weather to kill it or not.

###Tested on
Known to work with Windows 7 and Skype 6.x, but should work with other versions as well.
