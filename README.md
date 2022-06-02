# windows-auto-darkmode
A tool for auto switching dark mode on Windows.

I have this idea for bad experiences when I'm using Auto Dark Mode. It sometimes fail to switch automatically to dark mode. So I made this tool to replace it.

# How to use
You can get binary file either from releases or compile by yourself. 

If you need it, however, to start automatically along with Windows, you'll need the auto-switch.vbs file(from releases). You need to put it at Startup folder(C:\Users\\*username*\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup), so that it'll auto start.

If you have your own way to set auto start, you can do as you like.:)

# Modifying
Currently, darkmode start time and end time was set in the code. If you need, you can change it by yourself. I'm planning to make it configurable externally.

If you wish to use it on other platforms, you can modify enableDarkmode() and disableDarkmode() and compile for your target platform.