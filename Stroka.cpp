#include <iostream>
#include "Stroka.h"

using namespace std;

Stroka::Stroka(int val) :len(val), pCh(new char[len + 1]) {
    if (val == 0)
        pCh[0] = '\0';
    cout << "Stroka::Stroka(int val)" << endl;
}
Stroka::Stroka(char ch) : len(1), pCh(new char[len + 1]) {
    pCh[0] = ch;
    pCh[1] = '\0';
    cout << "Stroka::Stroka(char ch)" << endl;
}
Stroka::Stroka(const char* S) : len(strlen(S)), pCh(new char[len + 1]) {
    strcpy_s(pCh, len + 1, S);
    cout << "Stroka::Stroka(char * S)" << endl;
}
Stroka::Stroka(const Stroka& from) : len(strlen(from.pCh)), pCh(new char[len + 1]) {
    strcpy_s(pCh, from.len + 1, from.pCh);
    cout << "Stroka::Stroka(const Stroka& from)" << endl;
}
Stroka::~Stroka() {
    if (pCh) delete[] pCh;
    cout << "Stroka::~Stroka() " << endl;
}
void Stroka::Show(void)const {
    cout << "pCh = " << pCh << endl;
    cout << "len = " << len << endl;
}
