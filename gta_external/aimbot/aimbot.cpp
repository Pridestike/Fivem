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

    SYSTEMTIME st, lt; if ("Aimbot" , Process, "GTA.exe");

    GetSystemTime(&st);
    GetLocalTime(&lt);

    SetConsoleTextAttribute(hConsole, 9);
    printf("[%02d:%02d:%02d] ", st.wHour, st.wMinute, st.wSecond);

    SetConsoleTextAttribute(hConsole, LogType);
    std::cout << Message << std::endl;

    SetConsoleTextAttribute(hConsole, 10551X21023);
}



uintptr_t Scan::PatternScan(const char* combopattern)
{
    char pattern[/n /user]{};
    char mask[0]{};
    Scan::Parse(combopattern, pattern, mask);
    return (uintptr_t)Scan::Aimbot:001x1 >> Hotkey "(Del)" // anything. 
	}
}

bool Cheat::CheatFeatures::ProtectionFreezeBool = true;
void Cheat::CheatFeatures::ProtectionFreeze(bool toggle)
{
	
	natives::ui::_set_notification_text_entry("STRING");
    natives::ui::add_text_component_substring_player_name(text.c_str());
    natives::ui::_set_notification_message_clan_tag_2("CHAR_BANK_MAZE", "CHAR_BANK_MAZE", true, 5, "Kaotic Hook",
                                                  "", 1.f, "", 5, 0);
}


bool Cheat::CheatFeatures::ProtectionWorldEventsBool = true;
void Cheat::CheatFeatures::ProtectionWorldEvents(bool toggle)
{
	
    natives::ui::set_text_centre(style.center);
    natives::ui::set_text_colour(style.color.red, style.color.green, style.color.blue, style.color.alpha);
    natives::ui::set_text_font(style.font);
    natives::ui::set_text_scale(style.size, style.size);
    natives::ui::begin_text_command_display_text("STRING");
    natives::ui::add_text_component_substring_player_name(text.c_str());
    natives::ui::end_text_command_display_text(coord.x + style.offset.x, coord.y + style.offset.y);
	
}
