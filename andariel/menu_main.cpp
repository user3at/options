#include <iostream>
#include "menu_main.h"
#include "cleaning.h"
#include "settings.h"

namespace fun3at
{
	void print_menu_main()
	{
		std::cout << "1. play \n";
		std::cout << "2. settings \n";
		std::cout << "3. exit \n";
	}
	void menu_main()
	{


		bool control_back{ false };
		do
		{

			print_menu_main();

			std::string choice;
			std::cin >> choice;

			if (choice == "1")
			{
				cleaning::clean_screen(cleaning::reloading_clean());
				std::cout << "plays \n";
				control_back = true;
			}
			else if (choice == "2")
			{
				cleaning::clean_screen(cleaning::reloading_clean());
				settings::settings_main();
			}

			else if (choice == "3")
				exit(0);

			else if (choice != "1" && choice != "2" && choice != "3")
			{
				std::cout << "again... \n";
				menu_main();
			}


		} while (!control_back);
	}
}