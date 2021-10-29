#include <iostream>
#include <vector>
#include <filesystem>

using namespace std;

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

int findMutuallyPrime(int euler) {
    for (int e = 0; e != euler; e++) {
        if (isPrime(e)) {
            for (int i = 2; i != e + 1; i++) {
                if (e % i == 0 && euler % i == 0)
                    break;
                if (i == e)
                    return e;
            }

        }
    }
}
    

/*
int main()
{
    // тест функции проверки чисел на простоту.
    if (isPrime(3) && isPrime(5) && isPrime(7) && isPrime(13)) {
        std::cout << "isPrime is working properly" << endl;
    }


    //  метод для нахождения взаимно простого числа, которое было бы удовлетворяло математическим критериям RSA алгоритма.
    int euler = 12;
    if (findMutuallyPrime(euler) == 5) {
        std::cout << "findMutuallyPrime method is working properly" << endl;
    }

    //  метод обхода файлов

    vector<string> files;
    for (const auto& file : filesystem::directory_iterator("D:\\folder")) {
        files.push_back(file.path().u8string());
    }
    if (files.size() == 2) {
        std::cout << "file parsing method working properly" << endl;
    }



   
}

*/
