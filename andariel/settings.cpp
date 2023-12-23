#include <iostream>
#include <fstream>
#include <string>
#include "cleaning.h"
#include "settings.h"

namespace settings
{
	enum class menu_options
	{
		clean_status = 1,
	};
	menu_options element_menu_options;

	void print_menu_options()
	{
		std::cout << "$ clean status \n";
		std::cout << "$ back \n";
	}

	void set_menu_options(std::string choice, menu_options& element_menu_options)
	{
		if (choice == "clean status")
			element_menu_options = menu_options::clean_status;
	}

	void reloading_position_menu_options(menu_options element_menu_options)
	{
		switch (element_menu_options)
		{
			case menu_options::clean_status:
				cleaning::status_clean(cleaning::reloading_clean());
				cleaning::clean_iostream();
		}
	}
	void settings_main()
	{
		cleaning::clean_screen(cleaning::reloading_clean());
		cleaning::clean_iostream();

		bool control_back{ false };
		do
		{
			print_menu_options();
			std::string take_position;
			getline(std::cin, take_position);

			if (take_position != "back")
			{
				set_menu_options(take_position, element_menu_options);
				reloading_position_menu_options(element_menu_options);
			}
			else if (take_position == "back")
				control_back = true;
			else
				std::cout << "give me corect value \n";
			
		} while (!control_back);
	}
}