#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string transporate(string line);
string detransporate(string line);

string transporate(string line) {

	int size = line.size();
	const int b = ceil(size / 5);

	string v1 = "";
	string v2 = "";
	string v3 = "";
	string v4 = "";
	string v5 = "";
	string final_line = "";

	int kol = 0;

	for (int j = 0; j <= b; j++) {
		v1 += " ";
		v2 += " ";
		v3 += " ";
		v4 += " ";
		v5 += " ";
	}

	for (int i = 0; i <= b; i++) {
		v1[i] = line[i];
	}

	kol = 0;
	for (int i = b + 1; i <= 2 * b + 1; i++) {
		v2[kol] = line[i];
		kol++;
	}
	kol = 0;
	for (int i = 2 * b + 2; i <= 3 * b + 2; i++) {
		v3[kol] = line[i];
		kol++;
	}
	kol = 0;
	for (int i = 3 * b + 3; i <= 4 * b + 3; i++) {
		v4[kol] = line[i];
		kol++;
	}
	kol = 0;
	for (int i = 4 * b + 4; i <= 5 * b + 3; i++) {
		v5[kol] = line[i];
		kol++;
	}

	for (int i = 0; i <= b; i++) {
		final_line = final_line + v1[i] + v2[i] + v3[i] + v4[i] + v5[i];
	}

	return final_line;
}

string detransporate(string line) {
	int size = line.size();
	const int b = ceil(size / 5);

	string v1 = "";
	string v2 = "";
	string v3 = "";
	string v4 = "";
	string v5 = "";
	string final_line = "";

	int kol = 0;

	// for (int j = 0; j <= b; j++) {
	// 	v1 += " ";
	// 	v2 += " ";
	// 	v3 += " ";
	// 	v4 += " ";
	// 	v5 += " ";
	// }

	for (int i = 0; i < size; i++) {
		switch (kol)
		{
		case 0:
			v1.push_back(line[i]);
			kol++;
			break;

		case 1:
			v2.push_back(line[i]);
			kol++;
			break;

		case 2:
			v3.push_back(line[i]);
			kol++;
			break;

		case 3:
			v4.push_back(line[i]);
			kol++;
			break;

		case 4:
			v5.push_back(line[i]);
			kol=0;
			break;

		default:
			break;
		}
	}

	final_line = v1 + v2 + v3 + v4 + v5;

	return final_line;
}
