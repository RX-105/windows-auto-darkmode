# windows-auto-darkmode
A tool for auto switching dark mode on Windows.

I have this idea for bad experiences when I'm using Auto Dark Mode. It sometimes fail to switch automatically to dark mode. So I made this tool to replace it.

# How to use
You can get binary file either from releases or compile by yourself. 

If you need it, however, to start automatically along with Windows, you'll need the auto-switch.vbs file(from releases). You need a shortcut to it and put it at Startup folder(C:\Users\\*username*\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup), so that it'll auto start.

If you have your own way to set auto start, you can do as you like.:)

Darkmode start and end time was set default to 19:00 and 08:00. You can set it to your own preferences in `time.json`.

# Modifying
I'm using conan for package managing. To modify, you need to first run `conan install conanfile.txt` to install dependencies.

If you wish to use it on other platforms, you can modify enableDarkmode() and disableDarkmode() and compile for your target platform.

# And...
I miss maven. ( ›´ω`‹ )

I HATE using conan with vscode. (　^ω^)