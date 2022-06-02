#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <thread>

using namespace ::std;

vector<string> splitString(string str, char delimiter)
{
    vector<string> result;
    string s = "";
    for (char e : str)
    {
        if (e != delimiter)
        {
            s += e;
        }
        else
        {
            result.push_back(s);
            s = "";
        }
    }
    result.push_back(s);
    return result;
}

void enableDarkmode()
{
    system("reg.exe add HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize /v AppsUseLightTheme /t REG_DWORD /d 0 /f >NUL 2>&1");
    system("reg.exe add HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize /v SystemUsesLightTheme /t REG_DWORD /d 0 /f >NUL 2>&1");
}

void disableDarkmode()
{
    system("reg.exe add HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize /v AppsUseLightTheme /t REG_DWORD /d 1 /f >NUL 2>&1");
    system("reg.exe add HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize /v SystemUsesLightTheme /t REG_DWORD /d 1 /f >NUL 2>&1");
}

int main()
{
    bool exitFlag = false; // exit flag will never be true
    int status = 0;        // 0 for default, 1 for in dark, 2 for out of dark
    int DARKMODE_START = 19;
    int DARKMODE_END = 8;
    while (!exitFlag)
    {
        auto time = chrono::system_clock::now();
        time_t t = chrono::system_clock::to_time_t(time);
        int hour;
        try
        {
            hour = stoi(splitString(ctime(&t), ' ')[3].substr(0, 2));
        }
        catch (const invalid_argument &e)
        {
            cerr << e.what() << '\n';
        }

        if (hour >= DARKMODE_START || hour < DARKMODE_END)
        {
            // need to switch dark mode
            if (status != 1)
            {
                status = 1;
                enableDarkmode();
                cout << "enabled dark mode" << endl;
            }
        }
        else
        {
            // needn't to switch dark mode
            if (status != 2)
            {
                status = 2;
                disableDarkmode();
                cout << "disabled dark mode" << endl;
            }
        }
        this_thread::sleep_for(chrono::seconds(1));
    }
    return 0;
}
