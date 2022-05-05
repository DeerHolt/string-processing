#ifndef __COMPLEXSTR__
#define __COMPLEXSTR__
#include "Stroka.h"
#include <iostream>

class ComplexStr : public Stroka {
public:
    ComplexStr(int = 0);
    ComplexStr(const char*);
    ComplexStr(const ComplexStr&);
    virtual ~ComplexStr();
    double Get_real() const;
    double Get_imaginary() const;
    //переопределение некоторых операций
    ComplexStr& operator= (const ComplexStr&); //заносит значения в соответствующие поля this 
    friend ComplexStr operator* (const ComplexStr&, const ComplexStr&);
    friend bool operator== (const ComplexStr&, const ComplexStr&); //возвращает результат сравнения мнимых и вещественных частей двух чисел
};

#endif
#pragma once
