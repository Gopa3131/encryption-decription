#include "RSA.h"

pair<short, short> Coder::get_secret_key() { return this->secret_key; }


bool Coder::isPrime(int n)
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



short Coder::encode(string path, int p, int q) {
    cout << "initialized encoding.." << endl;
    bool directory_empty = filesystem::is_empty(path);
    if (directory_empty) {
        return 1;  // error code, directory empty
    }
    vector<string> files;
    for (const auto& file : filesystem::directory_iterator(path)) {
        files.push_back(file.path().u8string());
    }
    cout << "total number of files: " << files.size() << "." << endl;

    //  service part
    fstream file_stream;
    vector<string> ::iterator files_iter;
    string file_line;
    long long int val;


    //encoding part and calculating keys
    int n = p * q;
    int euler = (p - 1) * (q - 1);
    int e;  // has to change later, otherwise error
    bool e_not_finded = true;
    for (e = 0; e != euler; e++) {
        if (isPrime(e)) {
            for (int i = 2; i != e + 1; i++) {
                if (e % i == 0 && euler % i == 0)
                    break;
                if (i == e)
                    e_not_finded = false;
            }
        }
        if (!e_not_finded) {
            break;
        }
    }
    if (e_not_finded) {
        return 2;  // has not find e value;
    }
    this->open_key = make_pair(e, n);
    cout << "open key is " << open_key.first << " , " << open_key.second << endl;

    // calculating secret_key;
    int d = 1;
    while (true) {
        if ((d * e) % euler == 1 && d != e) {
            break;
        }
        d++;
    }
    this->secret_key = make_pair(d, n);

    for (files_iter = files.begin(); files_iter != files.end(); files_iter++) {
        cout << "encoding " << *files_iter << ".." << endl;
        file_stream.open(*files_iter, ios::in);
        getline(file_stream, file_line);
        cout << "file contains " << file_line << endl;
        val = stoi(file_line);
        // encoding value
        val = pow(val, e);
        val = val % n;
        file_stream.close();
        file_stream.open(*files_iter, ios::out | ios::trunc);
        file_stream << val;
        file_stream.close();
    }
    cout << "encoding is done" << endl;
    return 0;  // files encoded


}


short Coder::decode(string path, int d, int n) {
    cout << "initialized decoding " << endl;
    bool directory_empty = filesystem::is_empty(path);
    if (directory_empty) {
        return 1;  // error code, directory empty
    }
    vector<string> files;
    for (const auto& file : filesystem::directory_iterator(path)) {
        files.push_back(file.path().u8string());
    }
    cout << "total number of files: " << files.size() << "." << endl;

    //  service part
    fstream file_stream;
    vector<string> ::iterator files_iter;
    string file_line;
    long long int val;

    for (files_iter = files.begin(); files_iter != files.end(); files_iter++) {
        cout << "decoding " << *files_iter << ".." << endl;
        file_stream.open(*files_iter, ios::in);
        getline(file_stream, file_line);
        cout << "file contains " << file_line << endl;
        val = stoi(file_line);
        // decoding value
        val = pow(val, d);
        val = val % n;
        file_stream.close();
        file_stream.open(*files_iter, ios::out | ios::trunc);
        file_stream << val;
        file_stream.close();
        cout << "decoded value " << val << endl;
    }
    cout << "decoding is done" << endl;
    return 0;  // files decoded
}
