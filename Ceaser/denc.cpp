#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>

std::string dencCeaser(std::string file)
{
	std::string addr;
	std::string passw;
	size_t hashpasw;
	std::hash <std::string> hashf;
	char c;

	std::cout << "Введите пароль для файла" << std::endl;
	std::cin >> passw;
	hashpasw = hashf(passw);
	addr.clear();
	for (int i = 0; i < file.length(); i++)
	{
		c = file[i];
		c -= hashpasw % 128;
		if (c < 0)
			c = 128 + c;
		addr.push_back((char)c);
	}
	return addr;
}

