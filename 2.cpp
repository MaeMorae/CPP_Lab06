#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;
//use only lowercase in keyword
const string keyword = "or";
int main() {
    SetConsoleOutputCP(CP_UTF8);
    string text;
    int s = 0;
    cout << "Введите текст: \n";
    getline(cin, text);
    stringstream ss(text);
    string word;
    while (ss >> word) {
        string lowercase_word;
        for (char c : word) {
            lowercase_word += tolower(c);
        }
        if (lowercase_word == keyword) s++;
    }
    cout << "Количество вхождений слова " << keyword << " в текст: " << s;
}
