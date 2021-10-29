#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <cmath>

using namespace std;


class Coder
{
public:
    pair<short, short> get_secret_key();

    short encode(string path, int p, int q);

    short decode(string path, int d, int n);

private:
    bool isPrime(int n);
    pair<short, short> open_key;
    pair<short, short> secret_key;
};
