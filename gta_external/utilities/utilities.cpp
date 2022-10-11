#include "utilities.hpp"

int utilities::get_frame_rate()
{
	static int i_fps, i_last_fps;
	static float fl_last_tick_count, fl_tick_count;
	fl_tick_count = clock() * 0.001f;
	i_fps++;
	if ((fl_tick_count - fl_last_tick_count) >= 1.0f)
	{
		fl_last_tick_count = fl_tick_count;
		i_last_fps = i_fps;
		i_fps = 0;
	}
	return i_last_fps;
};


void Cheat::GameFunctions::SubtitleNotification(char* Message, int ShowDuration)
{
	UI::BEGIN_TEXT_COMMAND_PRINT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(Message);
	UI::END_TEXT_COMMAND_PRINT(ShowDuration, 1);
}

void Cheat::GameFunctions::GetBlipMarker()
{
	static Vector3 zero;
	Vector3 coords;

	bool blipFound = false;
	int blipIterator = UI::_GET_BLIP_INFO_ID_ITERATOR();
	for (Blip i = UI::GET_FIRST_BLIP_INFO_ID(blipIterator); UI::DOES_BLIP_EXIST(i) != 0; i = UI::GET_NEXT_BLIP_INFO_ID(blipIterator))
	{
		if (UI::GET_BLIP_INFO_ID_TYPE(i) == 4)
		{
			coords = UI::GET_BLIP_INFO_ID_COORD(i);
			blipFound = true;
			break;
		}
	}
	if (blipFound)
	{
		return coords;
	}

	return zero;
}

