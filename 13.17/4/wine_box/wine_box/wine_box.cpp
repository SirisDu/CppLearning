// wine_box.cpp
// test Port and VintagePort classes

#include <iostream>
#include <cctype>
#include "port.h"

int main()
{
    Port* p_port[4];
	char temp_brand[40]{};
	char temp_style[20]{};
	int temp_bottles{};
	char kind{};

	for (int i = 0; i < 4; i++)
	{
		std::cout << "Enter wine brand: ";
		std::cin.getline(temp_brand, 40);
		std::cout << "Enter wine style: ";
		std::cin.getline(temp_style, 20);
		std::cout << "Enter bottles: ";
		std::cin >> temp_bottles;
		std::cin.get();
		for (int i = 0; i < strlen(temp_style); i++)
		{
			temp_style[i] = tolower(temp_style[i]);
		}
		if (strcmp(temp_style, "vintage") != 0)
		{
			p_port[i] = new Port(temp_brand, temp_style, temp_bottles);
		}
		else
		{
			char temp_nickname[40]{};
			int temp_year{};

			std::cout << "Enter nickname: ";
			std::cin.getline(temp_nickname, 40);
			std::cout << "Enter year: ";
			std::cin >> temp_year;
			std::cin.get();
			p_port[i] = new VintagePort(temp_brand, temp_bottles,
				temp_nickname, temp_year);
		}
	}

	std::cout << "Display using Show():" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		p_port[i]->Show();
		std::cout << std::endl;
	}
	std::cout << "Display using std::ostream << :" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << *p_port[i] << std::endl;
	}                     // wrong

	for (int i = 0; i < 4; i++)
	{
		delete p_port[i];
	}
}
