#include <iostream>
#include <fstream>
#include <string>
#include "cleaning.h"

namespace settings
{
	void settings_main()
	{
		bool control_back{ false };
		do
		{
			std::cout << "1. clean status \n";
			std::cout << "2. back \n";

			short choice;
			std::cin >> choice;

			if (choice)
			{
				cleaning::status_clean(cleaning::reloading_clean());
				control_back = true;
			}
			else if (choice == 2)
				control_back = true;
			else
				std::cout << "wrong \n";
			
		} while (!control_back);
	}
}