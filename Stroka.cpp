#include <iostream>
#include "Stroka.h"

using namespace std;

Stroka::Stroka(int val) :len(val), ptrChar(new char[len + 1]) {
    if (val == 0)
        ptrChar[0] = '\0';
    cout << "Stroka::Stroka(int val)" << endl;
}
Stroka::Stroka(char ch) : len(1), ptrChar(new char[len + 1]) {
    ptrChar[0] = ch;
    ptrChar[1] = '\0';
    cout << "Stroka::Stroka(char ch)" << endl;
}
Stroka::Stroka(const char* S) : len(strlen(S)), ptrChar(new char[len + 1]) {
    strcpy_s(ptrChar, len + 1, S);
    cout << "Stroka::Stroka(char * S)" << endl;
}
Stroka::Stroka(const Stroka& from) : len(strlen(from.ptrChar)), ptrChar(new char[len + 1]) {
    strcpy_s(ptrChar, from.len + 1, from.ptrChar);
    cout << "Stroka::Stroka(const Stroka& from)" << endl;
}
Stroka::~Stroka() {
    if (ptrChar) delete[] ptrChar;
    cout << "Stroka::~Stroka() " << endl;
}
void Stroka::Show(void)const {
    cout << "ptrChar = " << ptrChar << endl;
    cout << "len = " << len << endl;
}
