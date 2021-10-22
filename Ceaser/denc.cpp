#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>

int dencCeaser(std::string file)
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
		std::cout << "Error opening file" << std::endl;
		return -1;
	}
	else if (addr[addr.size() - 4] + addr[addr.size() - 3] + addr[addr.size() - 2] + addr[addr.size() - 1] != '.' + 'e' + 'n' + 'c')
	{
		std::cout << "Неправильный файл" << std::endl;
		return -1;
	}
	addr.erase(addr.end() - 4, addr.end());
	fo.open(addr + ".denc", std::ofstream::out);
	std::cout << "Введите пароль для файла" << std::endl;
	std::cin >> passw;
	hashpasw = hashf(passw);
	do
	{
		c = fi.get();
		if (fi.eof())
			break;
		c -= hashpasw % 128;
		if (c < 0)
			c = 128 + c;
		fo << (char)c;
	} while(!fi.eof());
	return 0;
}
