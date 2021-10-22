#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main()
{
	std::string file;
	std::string response;
	bool state;

	std::ifstream fi;

	fi.open(file, std::ifstream::in);
	if (fi.fail())
	{
		std::cerr << "Error with file" << std::endl;
		return (-1);
	}
	std::cout << "Encrypt or decrypt? 1/0" << std::endl; 
	std::cin >> state;

	if (state)
	{
		std::cout << "Choose method: 1 - Ceaser, 2 - Atbash, 3 - transporate, 4 - Metod Sanka)))" << std::endl;
		std::cin >> response;
	}
}
