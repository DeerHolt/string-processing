#ifndef __STROKA__
#define __STROKA__
#include <iostream>

class Stroka { 
protected:
    int len;    //длина строки в байтах
    char* ptrChar; //указатель на массив символов
public:
    Stroka(int = 0);//получение длины строки
    Stroka(char);
    Stroka(const char*); ////конструктор, принимающий в качестве параметра строку (заканчивается нулевым байтом)
    Stroka(const Stroka&); //конструктор копирования
    virtual ~Stroka(); //деструктор
    char* GetStr(void)const { 

        return ptrChar;
    }
    int GetLen(void)const { 
        return len;
    }
    void Show(void)const;//функция, выводит содержимое pChar
};
// используем базовый класс «STROKA» и производные от него классы «IdentStr», «ComplexStr»
#endif
#pragma once
