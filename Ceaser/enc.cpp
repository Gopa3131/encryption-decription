#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>

std::string encodeCeaser(std::string file)
{
	std::string addr;
	std::string passw;
	size_t hashpasw;
	std::hash <std::string> hashf;
	char c;

	std::cout << "Enter pasword" << std::endl;
	std::cin >> passw;
	hashpasw = hashf(passw);
	addr.clear();
	for (int i = 0; i < file.length(); i++)
	{
		c = file[i];
		c += hashpasw % 128;
		c %= 128;
		addr.push_back(c);
	}
	return addr;
}
