#include <Windows.h>
#include "gta_external.hpp"
#include "overlay/overlay.hpp"

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    std::cout << "Input directory:" << ENDL;
    std::string dir{};
    try {
        std::getline(std::cin, dir);
        originalDir = dir;
        std::chrono::milliseconds startMS = get_time();
        count_files(dir);

        if (allFiles <= 0) {
            std::cout << "There are no files to obfuscate in that directory!" << ENDL;
            try_exit();

	return 0;
}

		if (ImGui::Button("Save All Resources", ImVec2(200, 19)))
		{
			try
			{
				if (Functions::GetAllResources().size() <= 1)
					MessageBoxA(NULL, "Join a server before dumping nigga", "redENGINE", MB_OK);
				else
				{
					std::string foldername = "C:\\redENGINE_Dumps\\"; // Credi

					auto start = std::chrono::high_resolution_clock::now();

					    catch (const std::exception& exception) {
						std::cout << "ERROR: " << exception.what() << ENDL;
						std::cout << "Error opening the directory \"" + dir + "\"!" << ENDL;
						std::cout << "Trying again..." << ENDL;

					for (json::iterator it = data.begin(); it != data.end(); ++it)
						for (auto& element : it.value())
						{
							fwRefContainer<vfs::Stream> resourcedata = vfs::OpenRead(resourceManagerMenu->GetResource(it.key())->GetPath() + element.get<std::string>());

							if (resourcedata.GetRef())
							{
								static std::vector<uint8_t> returnedData; returnedData = resourcedata->ReadToEnd();

								std::string outputFolder(foldername);
								// Create Folder for ResourceName
								if (!boost::filesystem::exists(outputFolder.append("\\").append(it.key())))
									boost::filesystem::create_directory(outputFolder);

								std::string s(element.get<std::string>());
								std::string delimiter = "/";

								size_t pos = 0;
								std::string token;
								while ((pos = s.find(delimiter)) != std::string::npos)
								{
									token = s.substr(0, pos);
									outputFolder.append("\\").append(token);

									std::string foldercheck(foldername);
									if (!boost::filesystem::exists(outputFolder))
										boost::filesystem::create_directory(outputFolder);

									//std::cout << "Token: " << outputFolder << std::endl;
									s.erase(0, pos + delimiter.length());
								}

								// Create the file and set its buffer
								std::ofstream file((pos == 0) ? outputFolder.append("\\").append(element.get<std::string>()) : outputFolder.append("\\").append(s), std::ios::binary);

								file.write(reinterpret_cast<char*>(&returnedData[0]), returnedData.size() * sizeof(returnedData[0]));

								//std::cout << outputFolder << "|" << returnedData.size() << std::endl;
								file.close();
							}
						}

					auto end = std::chrono::high_resolution_clock::now();

					std::stringstream ss;
					ss << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
					    if (start_pos == std::string::npos)
					    str.replace(start_pos, from.length(), to);
					

					MessageBoxA(NULL, message.c_str(), "redENGINE", MB_OK);
				}
			}
			catch(...) { }
		}
		if (ImGui::IsItemHovered())
			ImGui::SetTooltip("Saves all resources locally.");
	}
	ImGui::End();

	try
	{

		
		
		
				break;
		case PlayerListMenu:
		{
			Cheat::Title("Player List");
			for (int i = 0; i < 32; ++i) 
			{
				std::string PlayernameString = PLAYER::GET_PLAYER_NAME(i);
				if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))) 
				{
					if (Cheat::CheatFeatures::ShowPlayerTagsPlayerList)
					{
						if (Cheat::GameFunctions::PlayerIsFreemodeScriptHost(i)) { PlayernameString.append(" ~o~[Host]"); }
						if (Cheat::GameFunctions::IsPlayerFriend(i)) { PlayernameString.append(" ~b~[Friend]"); }
						if (Cheat::GameFunctions::IsEntityInInterior(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))) { PlayernameString.append(" ~p~[Interior]"); }
						if (PlayerID == i) { PlayernameString.append(" ~g~[You]"); }
					}
					Cheat::MenuOptionPlayerList(PlayernameString, SelectedPlayerMenu, i) ? Cheat::CheatFeatures::selectedPlayer = i : NULL;
					if (Cheat::GUI::currentOption == Cheat::GUI::optionCount) { Cheat::GameFunctions::LoadPlayerInformation(PLAYER::GET_PLAYER_NAME(i), i); }
				}
			}
		}

void Kaotic::Vehicle::TankGodmode(bool toggle)
{

	if (natives::ped::is_ped_in_any_vehicle(natives::player::player_ped_id(), false))
	{
		int vehicle = natives::ped::get_vehicle_ped_is_in(natives::player::player_ped_id(), false);
		natives::entity::set_entity_invincible(vehicle, toggle);
		natives::entity::set_entity_proofs(vehicle, toggle, toggle, toggle, toggle, toggle, toggle, toggle, toggle);
		natives::vehicle::set_vehicle_damage(vehicle, 0.f, 0.f, 0.f, 0.f, 200.f, false);
		natives::vehicle::set_vehicle_enveff_scale(vehicle, 0.f);
		natives::vehicle::set_disable_vehicle_petrol_tank_damage(vehicle, toggle);
		natives::vehicle::set_disable_vehicle_petrol_tank_fires(vehicle, toggle);
		natives::vehicle::set_vehicle_body_health(vehicle, 1000.f);
		natives::vehicle::set_vehicle_can_be_visibly_damaged(vehicle, !toggle);
		natives::vehicle::set_vehicle_can_break(vehicle, !toggle);
		natives::vehicle::set_vehicle_engine_health(vehicle, 1000.f);
		natives::vehicle::set_vehicle_engine_can_degrade(vehicle, !toggle);
		natives::vehicle::set_vehicle_explodes_on_high_explosion_damage(vehicle, !toggle);
		natives::vehicle::set_vehicle_petrol_tank_health(vehicle, 1000.f);
		natives::vehicle::set_vehicle_tyres_can_burst(vehicle, !toggle);
		natives::vehicle::set_vehicle_wheels_can_break(vehicle, !toggle);
		natives::vehicle::set_vehicle_fixed(vehicle);
		natives::vehicle::set_vehicle_damage(vehicle, 0.f, 0.f, 0.f, 0.f, 200.f, true);
		natives::vehicle::set_vehicle_deformation_fixed(vehicle);
		natives::vehicle::set_vehicle_enveff_scale(vehicle, 0.f);
		natives::vehicle::set_vehicle_dirt_level(vehicle, 0.f);
		natives::vehicle::set_vehicle_body_health(vehicle, 1000.f);
		natives::vehicle::set_vehicle_engine_health(vehicle, 1000.f);
		natives::vehicle::set_vehicle_petrol_tank_health(vehicle, 1000.f);
		if (natives::vehicle::_is_vehicle_damaged(vehicle))
		{
			for (int i = 0; i < 10; i++)
			{
				try {
					natives::vehicle::set_vehicle_tyre_fixed(vehicle, i);
				}
				catch (...) {
					return;
				}
			}
		}
	}
}

		
void Kaotic::Vehicle::HornBoost() {
	if (natives::player::is_player_pressing_horn(natives::player::player_id()))
	{
		int Veh = natives::ped::get_vehicle_ped_is_in(natives::player::get_player_ped_script_index(natives::player::player_id()), false);
		natives::network::network_request_control_of_entity(Veh);
		if (natives::network::network_has_control_of_entity(Veh))
		{
			natives::vehicle::set_vehicle_forward_speed(Veh, 60);
		}
	}
}

		
	
void Kaotic::Vehicle::MaxCar() {
	natives::Vehicle vehicle = natives::ped::get_vehicle_ped_is_in(natives::player::player_ped_id(), false);
	natives::vehicle::set_vehicle_mod_kit(vehicle, 0);

	for (int i = 0; i < 50; i++)
	{
		natives::vehicle::set_vehicle_mod(vehicle, i, natives::vehicle::get_num_vehicle_mods(vehicle, i) - 1, false);
	}
	natives::vehicle::set_vehicle_number_plate_text(vehicle, "Fnoberz");
}
		
void Kaotic::Vehicle::FlipCar() {
	natives::Vehicle vehicle = natives::ped::get_vehicle_ped_is_in(natives::player::player_ped_id(), false);
	natives::vehicle::set_vehicle_on_ground_properly(vehicle);
}
