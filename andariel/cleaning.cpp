#include <iostream>
#include <fstream>
#include <string>
#include "cleaning.h"

namespace cleaning
{
	
	////  to clean screan
	void status_clean(int control_clean)
	{
		if (control_clean)
			std::cout << "status clean == true \n";
		else
			std::cout << "status clean == false \n";

		cleaning::save_clean();
	}
	void save_clean()
	{
		//cleaning::clean_iostream();

		std::fstream file;
		file.open("..\\..\\andariel\\saved_clean.txt", std::ios::out);

		char choice;
		std::string control_clean;

		std::cout << "do you clean the screen? (y/n): ";
		std::cin >> choice;

		if (choice == 'y')
		{
			control_clean = "1";
			file << control_clean << std::endl;
			std::cout << "opening \n";
		}
		else if (choice == 'n')
		{
			control_clean = "0";
			file << control_clean << std::endl;
		}

		file.close();
	}
	int reloading_clean()
	{
		std::fstream file;
		int control_clean{ 1 };
		file.open("..\\..\\andariel\\saved_clean.txt", std::ios::in);

		//if (!file.good())
			//std::cout << "wrong file \n";
		//else
		//{
			std::string line;
			short nr_line{ 1 };

			while (getline(file, line))
			{
				switch (nr_line)
				{
				case 1:
					control_clean = atoi(line.c_str());
				}
				nr_line++;
			}
		//}
		file.close();

		return control_clean;
	}

	void clean_screen(int control_screen)
	{
		if (control_screen)
			system("clear");
	}

	//// to clean iostream
	void clean_iostream()
	{
		std::cin.clear(); // czyszczenie flag bledow w strumieniu 
		std::cin.ignore(); // odrzucenie danych ktore wywolaly bledy 
	}
}