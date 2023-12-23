#include <iostream>
#include "settings.h"
#include "cleaning.h"

namespace fun3at
{
	void menu_main()
	{


		bool control_back{ false };
		do
		{
			char choice;

			std::cout << "1. play \n";
			std::cout << "2. settings \n";
			std::cout << "3. exit \n";

			std::cin >> choice;

			if (choice == '1')
			{
				cleaning::clean_screen(cleaning::reloading_clean());
				std::cout << "plays \n";
				control_back = true;
			}
			else if (choice == '2')
			{
				cleaning::clean_screen(cleaning::reloading_clean());
				settings::settings_main();
			}
			else if (choice == '3')
				exit(0);
			else if (choice != 1 && choice != 2)
			{
				std::cout << "again... \n";
				menu_main();
			}


		} while (!control_back);
	}
}