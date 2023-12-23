#pragma once
#include <iostream>

namespace settings
{
	enum class menu_options;
	void print_menu_options();
	void set_menu_options(std::string choice, menu_options& element_menu_options);
	void reloading_position_menu_options(menu_options element_menu_options);
	void settings_main();
}