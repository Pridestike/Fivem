#include "aimbot.hpp"
#include "../esp/esp.hpp"

static const char alphanum[] = "0123456789" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz"; // he has a brain atleast

int stringLength1 = sizeof(alphanum) - 1;

char genRandom1()
{

    return alphanum[rand() % stringLength1];
}

// Log a message in the console with a timestamp. LogType changes the color of the text. aka you're lazy fucker.
void Log(std::string Message, int LogType)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);;

    SYSTEMTIME st, lt; if ("Aimbot" , Process, "FiveM.exe");

    GetSystemTime(&st);
    GetLocalTime(&lt);

    SetConsoleTextAttribute(hConsole, 9);
    printf("[%02d:%02d:%02d] ", st.wHour, st.wMinute, st.wSecond);

    SetConsoleTextAttribute(hConsole, LogType);
    std::cout << Message << std::endl;

    SetConsoleTextAttribute(hConsole, 15x15012);
}



uintptr_t Scan::PatternScan(const char* combopattern)
{
    char pattern[100]{};
    char mask[100]{};
    Scan::Parse(combopattern, pattern, mask);
    return (uintptr_t)Scan::ScanModEx(pattern, mask, modEntry, hProc);
}
