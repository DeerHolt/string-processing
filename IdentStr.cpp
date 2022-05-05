#include <iostream>
#include "Stroka.h"
#include "IdentStr.h"

using namespace std;

IdentStr::IdentStr(int val) : Stroka(val) {
    cout << "IdentStr:: IdentStr (int val): Stroka(val)" << endl;
}
IdentStr::IdentStr(char ch) : Stroka(ch) {
    if (!((ptrChar[0] >= 'a') && (ptrChar[0] <= 'z') || (ptrChar[0] >= 'A') && (ptrChar[0] <= 'Z'))) {
        cout << "Bad simvol; ptrChar[0] = " << ptrChar[0] << endl;
        if (ptrChar) delete[] ptrChar;
        len = 0;
        ptrChar = new char[len + 1];
        ptrChar[0] = '\0';
        return;
    }
    cout << "IdentStr:: IdentStr (char ch): Stroka(ch)" << endl;
}

IdentStr::IdentStr(const char* str) : Stroka(str) {
    const char* keyword[]{
        "alignas", "alignof", "and","and_eq", "asm", "auto", "bitand", "bitor", "bool", "break", "case", "catch",
        "char", "char16_t", "char32_t", "class", "compl", "const", "constexpr", "const_cast", "continue", "decltype",
        "default", "delete", "do", "double", "dynamic_cast", "else", "enum", "explicit", "export", "extern", "false",
        "float", "for", "friend", "goto", "if", "inline", "int", "long", "mutable namespace", "new", "noexcept",
        "not", "not_eq", "nullptr", "operator", "or", "or_eq", "private", "protected", "public", "register", "reinterpret_cast",
        "return", "short", "signed", "sizeof", "static", "static_assert", "static_cast	struct", "static_cast struct",
        "switch", "template", "this", "thread_local", "throw", "true", "try", "typedef", "typeid", "typename", "union",
        "unsigned", "using", "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq" };
    for (int i = 0; i < 83; i++) {
        if (strcmp(ptrChar, keyword[i]) == 0) {
            cout << "Bad Stroka ptrChar=" << ptrChar << endl;
            if (ptrChar) delete[] ptrChar;
            len = 0;
            ptrChar = new char[len + 1];
            ptrChar[0] = '\0';
            return;
        }
    }
    if (!((ptrChar[0] >= 'a') && (ptrChar[0] <= 'z') || (ptrChar[0] >= 'A') && (ptrChar[0] <= 'Z') || (ptrChar[0] == '_'))) {
        cout << "Bad simvol; ptrChar[0] = " << ptrChar[0] << endl;
        if (ptrChar) delete[] ptrChar;
        len = 0;
        ptrChar = new char[len + 1];
        ptrChar[0] = '\0';
        return;
    }
    for (int i = 1; i < len; i++) {
        if (!((ptrChar[i] >= 'a') && (ptrChar[i] <= 'z') || (ptrChar[i] >= 'A') && (ptrChar[i] <= 'Z') || (ptrChar[i] == '_') || (ptrChar[i] >= '0') && (ptrChar[i] <= '9'))) {
            cout << "Bad simvol; ptrChar[" << i << "]" << endl;
            if (ptrChar) delete[] ptrChar;
            len = 0;
            ptrChar = new char[len + 1];
            ptrChar[0] = '\0';
            return;
        }
    }
    cout << "IdentStr:: IdentStr (const char* str): Stroka(str)" << endl;
}

IdentStr::IdentStr(const IdentStr& from) : Stroka(from) {
    cout << "IdentStr::IdentStr() : Stroka()" << endl;
}

IdentStr:: ~IdentStr() {
    cout << "IdentStr::~IdentStr() :" << endl;
}

void IdentStr::Uppercase() {
    for (int i = 0; i < len; i++) {
        if (ptrChar[i] >= 'a' && ptrChar[i] <= 'z') {
            ptrChar[i] -= 32;
        }
    }
}

IdentStr& IdentStr:: operator=(const IdentStr& S) {
    if (&S != this) {
        delete[] ptrChar;
        len = strlen(S.ptrChar);
        ptrChar = new char[len + 1];
        strcpy_s(ptrChar, len + 1, S.ptrChar);
    }
    cout << "IdentStr & IdentStr:: operator=(const IdentStr & S)" << endl;
    return *this;
}

IdentStr IdentStr:: operator~() {
    int i, j;
    char tmp;
    for (int i = 0, j = len - 1; i < len / 2; i++, j--) {
        tmp = ptrChar[i];
        ptrChar[i] = ptrChar[j];
        ptrChar[j] = tmp;
    }
    cout << "IdentStr IdentStr:: operator~()" << endl;
    return *this;
}

int operator> (const IdentStr& left, const IdentStr& right) {
    int len = min(left.GetLen(), right.GetLen());
    int t = 0;
    for (int i = 0; i < len; i++) {
        if ((int)left.ptrChar[i] > (int)right.ptrChar[i]) {
            return 1;
        }
    }
    return left.GetLen() > right.GetLen();
}

IdentStr operator+ (const IdentStr& pobj1, const IdentStr& pobj2) {
    IdentStr tmp(pobj1.GetLen() + pobj2.GetLen());
    int i = 0, j = 0;
    while (tmp.ptrChar[i++] = pobj1.ptrChar[j++]); //strcpy
    --i;
    j = 0;
    while (tmp.ptrChar[i++] = pobj2.ptrChar[j++]); //strcat
    cout << "IdentStr operator+ (const IdentStr& pobj1, const IdentStr& pobj2)" << endl;
    return tmp;
}

IdentStr operator+ (const IdentStr& pobj1, const char* pobj2) {
    IdentStr tmp1(pobj2);
    IdentStr tmp(pobj1.GetLen() + tmp1.GetLen());
    int i = 0, j = 0;
    while (tmp.ptrChar[i++] = pobj1.ptrChar[j++]);
    --i;
    j = 0;
    while (tmp.ptrChar[i++] = tmp1.ptrChar[j++]);
    cout << "IdentStr operator + (const IdentStr& pobj1, const char* pobj2)" << endl;
    return tmp;
}

IdentStr operator+ (const char* pobj1, const IdentStr& pobj2) {
    IdentStr tmp1(pobj1);
    IdentStr tmp(tmp1.GetLen() + pobj2.GetLen());
    int i = 0, j = 0;
    while (tmp.ptrChar[i++] = tmp1.ptrChar[j++]);
    --i;
    j = 0;
    while (tmp.ptrChar[i++] = pobj2.ptrChar[j++]);
    cout << "IdentStr operator + (const char* pobj1, const IdentStr& pobj2)" << endl;
    return tmp;
}

char& IdentStr:: operator [] (int index) {
    if (index >= 0 && index < len) {
        cout << "char& IdentStr:: operator [] (int index)" << endl;
        return ptrChar[index];
    }
    else return ptrChar[0];
}
