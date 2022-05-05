#ifndef __IDENTSTR__
#define __IDENTSTR__
#include "Stroka.h"
#include <iostream>

class IdentStr : public Stroka {
public:
    IdentStr(int = 0);
    IdentStr(char);
    IdentStr(const char*); //Содержимым pChar могут быть только те символы, которые входят в состав символов-идентификаторов
    IdentStr(const IdentStr&);
    virtual ~IdentStr();
    void Uppercase();
    //переопределение некоторых операций
    IdentStr& operator = (const IdentStr&); //заносит значения в соответствующие поля this 
    char& operator [] (int);
    IdentStr operator ~ ();
    friend int operator > (const IdentStr&, const IdentStr&); 
    //сравнивает две строки по коду символов, 
    //до конца меньшей строки, если символы одинаковые, то большей является строка большей длины
    friend IdentStr  operator + (const IdentStr&, const IdentStr&);
    friend IdentStr operator + (const IdentStr&, const char*);
    friend IdentStr operator + (const char*, const IdentStr&);
    //образует новую строку путем объединения содержимых двух строк
};

#endif
#pragma once
