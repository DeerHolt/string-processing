#ifndef __IDENTSTR__
#define __IDENTSTR__
#include "Stroka.h"
#include <iostream>

class IdentStr : public Stroka {
public:
    IdentStr(int = 0);
    IdentStr(char);
    IdentStr(const char*); //���������� pChar ����� ���� ������ �� �������, ������� ������ � ������ ��������-���������������
    IdentStr(const IdentStr&);
    virtual ~IdentStr();
    void Uppercase();
    //��������������� ��������� ��������
    IdentStr& operator = (const IdentStr&); //������� �������� � ��������������� ���� this 
    char& operator [] (int);
    IdentStr operator ~ ();
    friend int operator > (const IdentStr&, const IdentStr&); 
    //���������� ��� ������ �� ���� ��������, 
    //�� ����� ������� ������, ���� ������� ����������, �� ������� �������� ������ ������� �����
    friend IdentStr  operator + (const IdentStr&, const IdentStr&);
    friend IdentStr operator + (const IdentStr&, const char*);
    friend IdentStr operator + (const char*, const IdentStr&);
    //�������� ����� ������ ����� ����������� ���������� ���� �����
};

#endif
#pragma once
