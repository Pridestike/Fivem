 #pragma once
#include "../gta_external.hpp"

class c_aimbot
{
public:

	void do_aimbot(sdk::c_ped entity);

}

void originbasev2::draw_header(const std::string& description, const int current_option, const int option_count)
{
       
    });

    auto desc = description;
    for (auto& c : desc)
        c = toupper(c);
    drawing::draw_text(desc, styles["header"].text, {
        menu_position.x - styles["header"].rect.width / 2.1f,
        menu_position.y + styles["title"].rect.height / 2 + styles["header"].rect.height / 2 - styles["header"]
                                                                                               .text.size / 25
    });

    const auto counter = std::to_string(current_option + 1) + " / " + std::to_string(option_count);
    drawing::draw_text(counter, styles["header"].text, {
        menu_position.x + styles["header"].rect.width / 2.1f - get_text_width(
            counter, styles["header"].text.font, styles["header"].text.size),
        menu_position.y + styles["title"].rect.height / 2 + styles["header"].rect.height / 2 - styles["header"]
                                                                                               .text.size / 25
 });
