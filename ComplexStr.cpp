#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <regex>
#include "Stroka.h"
#include "ComplexStr.h"

using namespace std;

ComplexStr::ComplexStr(int val) : Stroka(val) {
    cout << "ComplexStr::ComplexStr(int val): Stroka(val)" << endl;
}

ComplexStr::ComplexStr(const char* str) : Stroka(str) {
    int len1 = strlen(str);
    string s = str;
    if (regex_match(s, regex("[+-]?\\d+.?\\d*i[+-]?\\d+.?\\d*"))) {
        for (int i = 0; i < len1; i++) {
            pCh[i] = s[i];
        }
        pCh[len1] = '\0';
    }
    else {
        if (pCh) {
            delete[] pCh;
            len = 0;
            pCh = new char[len + 1];
            pCh[0] = '\0';
        }
        return;
    }
    cout << "ComplexStr::ComplexStr(const char* str)" << endl;
}

ComplexStr::ComplexStr(const ComplexStr& from) : Stroka(from) {
    cout << "ComplexStr::ComplexStr(const ComplexStr& from):Stroka(from)" << endl;
}

ComplexStr:: ~ComplexStr() {
    cout << "ComplexStr:: ~ComplexStr()" << endl;
}

ComplexStr& ComplexStr:: operator= (const ComplexStr& CS) {
    if (&CS != this) {
        delete[] pCh;
        len = strlen(CS.pCh);
        pCh = new char[len + 1];
        strcpy_s(pCh, len + 1, CS.pCh);
    }
    cout << "ComplexStr& ComplexStr:: operator= (const ComplexStr& CS)" << endl;
    return *this;
}

double ComplexStr::Get_real() const {
    int i = 0, t = 0;
    double real = 0;
    int sign_re = 1;
    if (pCh[0] == '-') {
        sign_re = -1;
        i++;
    }
    if (pCh[0] == '+') i++;
    while (pCh[i] != 'i' && pCh[i] != '.') {
        real *= 10;
        real += (static_cast<int>(pCh[i]) - 48);
        i++;
    }
    if (pCh[i] == '.') {
        i++;
        while (pCh[i] != 'i') {
            real *= 10;
            real += (static_cast<int>(pCh[i]) - 48);
            i++;
            t++;
        }
    }
    for (int j = 0; j < t; j++) {
        real /= 10;
    }
    real *= sign_re;
    return real;
}

double ComplexStr::Get_imaginary() const {
    int i = 0, t = 0;
    double imaginary = 0;
    int sign_im = 1;
    while (pCh[i] != 'i') {
        i++;
    }
    i++;
    if (pCh[i] == '-') {
        sign_im = -1;
        i++;
    }
    if (pCh[i] == '+') i++;
    while (pCh[i] != '.' && pCh[i] != '\0') {
        imaginary *= 10;
        imaginary += (static_cast<int>(pCh[i]) - 48);
        i++;
    }
    if (pCh[i] == '.') {
        i++;
        while (pCh[i] != '\0') {
            imaginary *= 10;
            imaginary += (static_cast<int>(pCh[i]) - 48);
            i++;
            t++;
        }
    }
    for (int j = 0; j < t; j++) {
        imaginary /= 10;
    }
    imaginary *= sign_im;
    return imaginary;
}

ComplexStr operator* (const ComplexStr& left, const ComplexStr& right) {
    ComplexStr res;
    string real, im;
    double res_re = left.Get_real() * right.Get_real() - left.Get_imaginary() * right.Get_imaginary();
    double res_im = left.Get_real() * right.Get_imaginary() - left.Get_imaginary() * right.Get_real();
    if ((int)res_re != res_re && (int)res_im != res_im) {
        real = to_string(res_re);
        im = to_string(res_im);
    }
    else {
        if ((int)res_re == res_re) {
            real = to_string((int)res_re);
        }
        if ((int)res_im == res_im) {
            im = to_string((int)res_im);
        }
    }
    int i = 0, j = 0;
    res.len = real.length() + im.length() + 1;
    delete[] res.pCh;
    res.pCh = new char[res.len + 2];
    while (real[i] != '\0') {
        res.pCh[i] = real[i];
        i++;
    }
    res.pCh[i] = 'i';
    i++;
    while (im[j] != '\0') {
        res.pCh[i + j] = im[j];
        j++;
    }
    res.pCh[i + j] = '\0';
    cout << i + j << " " << res.GetLen() << endl;
    return res;
}

bool operator==(const ComplexStr& left, const ComplexStr& right) {
    return left.Get_real() == right.Get_real() && right.Get_imaginary() == right.Get_imaginary();
}
