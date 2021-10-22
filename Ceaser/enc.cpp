#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>

int encodeCeaser(std::string file)
{
	std::string addr;
	std::string passw;
	size_t hashpasw;
	std::ifstream fi;
	std::ofstream fo;
	std::hash <std::string> hashf;
	char c;

	fi.open(file, std::ifstream::in);
	if (fi.fail())
	{
		std::cout << "Error while opening file" << std::endl;
		return -1;
	}
	fo.open(addr + ".enc", std::ofstream::out);
	std::cout << "Enter pasword" << std::endl;
	std::cin >> passw;
	hashpasw = hashf(passw);
	do
	{
		c = fi.get();
		if (fi.eof())
			break;
		c += hashpasw % 128;
		c %= 128;
		fo << (char)c;
	} while(!fi.eof());
	return 0;
}
