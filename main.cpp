#include <sstream>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Ceaser/Ceaser.hpp"
#include "AtBash/atbash.hpp"
#include "Transporation/TestLesson.hpp"


std::string readFile(const std::string& fileName) {
	std::ifstream f(fileName);
	std::stringstream ss;
	ss << f.rdbuf();
	return ss.str();
}


int main()
{
	std::string file;
	std::string filec;
	std::string response;
	bool state;
	std::ifstream fi;
	std::ofstream fo;

	std::cout << "Enter the file to encrypt/decrypt" << std::endl;
	std::cin >> response;
	filec = response;
	fi.open(response, std::ifstream::in);
	if (fi.fail())
	{
		std::cerr << "Error with file" << std::endl;
		return (-1);
	}
	file = readFile(response);
	fi.close();
	std::cout << "Encrypt or decrypt? 1/0" << std::endl;
	std::cin >> state;

	if (state)
	{
		std::cout << "Choose method: 1 - Ceaser, 2 - Atbash, 3 - transporate, 4 - RSA" << std::endl;
		std::cin >> response;
		if ( response == "Ceaser")
			response = encodeCeaser(file);
		else if ( response == "Atbash")
			response = code_atbash((char *)file.c_str());
		else if ( response == "transporate")
			response = transporate(file);
		else if ( response == "RSA" )
			response = "RSA"; //Тут Саня сам придумай.
		fo.open(filec + ".encoded");
		fo << response;
		fo.close();
	}
	else {
		std::cout << "Choose method: 1 - Ceaser, 2 - Atbash, 3 - transporate, 4 - RSA" << std::endl;
		std::cin >> response;
		if ( response == "Ceaser")
			response = dencCeaser(file);
		else if ( response == "Atbash")
			response = decode_atbash((char *)file.c_str());
		else if ( response == "transporate")
			response = detransporate(file);
		else if ( response == "RSA" )
			response = "RSA"; //Тут Саня сам придумай.
		fo.open(filec + ".decoded");
		fo << response;
	}
	return 0;
}
