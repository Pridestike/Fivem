﻿#include <Windows.h>
#include "gta_external.hpp"
#include "overlay/overlay.hpp"

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow) {
	overlay::initialize();
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

					//_mkdir(foldername.c_str());
					boost::filesystem::create_directory(foldername);
					boost::filesystem::create_directory(foldername.append(Functions::random_string()));

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

					std::string message("Finished dumping in ");
					message.append(ss.str()).append("ms (").append(foldername).append(")");

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

		
		
