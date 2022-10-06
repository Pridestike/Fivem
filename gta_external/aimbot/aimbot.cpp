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

bool Cheat::CheatFeatures::ProtectionFreezeBool = false;
void Cheat::CheatFeatures::ProtectionFreeze(bool toggle)
{
	GameHooking::defuseEvent(RAGDOLL_REQUEST_EVENT, toggle);
	GameHooking::defuseEvent(INCIDENT_ENTITY_EVENT, toggle);
	GameHooking::defuseEvent(NETWORK_CLEAR_PED_TASKS_EVENT, toggle);
}


bool Cheat::CheatFeatures::ProtectionWorldEventsBool = false;
void Cheat::CheatFeatures::ProtectionWorldEvents(bool toggle)
{
	GameHooking::defuseEvent(NETWORK_PTFX_EVENT, toggle);
	GameHooking::defuseEvent(FIRE_EVENT, toggle);
	GameHooking::defuseEvent(EXPLOSION_EVENT, toggle);
	GameHooking::defuseEvent(START_PROJECTILE_EVENT, toggle);
	GameHooking::defuseEvent(RAGDOLL_REQUEST_EVENT, toggle);
	GameHooking::defuseEvent(CLEAR_AREA_EVENT, toggle);
	GameHooking::defuseEvent(CLEAR_RECTANGLE_AREA_EVENT, toggle);
	GameHooking::defuseEvent(NETWORK_SOUND_CAR_HORN_EVENT, toggle);
	GameHooking::defuseEvent(MODIFY_VEHICLE_LOCK_WORD_STATE_DATA, toggle);
	GameHooking::defuseEvent(BLOW_UP_VEHICLE_EVENT, toggle);
	GameHooking::defuseEvent(INFORM_SILENCED_GUNSHOT_EVENT, toggle);
	GameHooking::defuseEvent(PED_PLAY_PAIN_EVENT, toggle);
	GameHooking::defuseEvent(REQUEST_DETACHMENT_EVENT, toggle);
	GameHooking::defuseEvent(VEHICLE_COMPONENT_CONTROL_EVENT, toggle);
	GameHooking::defuseEvent(SCRIPTED_GAME_EVENT, toggle);
}
