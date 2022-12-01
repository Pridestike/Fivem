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


void Kaotic::Recovery::GiveAllWeapons()
{
		float w = m_vMatrix[12] * from.x + m_vMatrix[13] * from.y + m_vMatrix[14] * from.z + m_vMatrix[15];
}


inline Vector3 WorldToScreen(Vector3 from, float targetWidth, float targetHeight)
{
	Vector3 to = Vector3();

	uint64_t viewRenderer = read<uint64_t>(oBaseAddress + OFFSET_VIEWRENDER);
	uint64_t viewMatrix = read<uint64_t>(viewRenderer + OFFSET_MATRIX);
	MatrixA m = read<MatrixA>(viewMatrix);



	if (w < 0.01f) return Vector3();



	float invw = 1.0f / w;
	to.x *= invw;
	to.y *= invw;

	float x = targetWidth / 2;
	float y = targetHeight / 2;

	x += 0.5f * to.x * targetWidth + 0.5f;
	y -= 0.5f * to.y * targetHeight + 0.5f;

	to.x = x;
	to.y = y;
	to.z = 0;

	return to;
}


