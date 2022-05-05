#ifndef __STROKA__
#define __STROKA__
#include <iostream>

class Stroka { 
protected:
    int len;    //����� ������ � ������
    char* pCh; //��������� �� ������ ��������
public:
    Stroka(int = 0);//��������� ����� ������
    Stroka(char);
    Stroka(const char*); ////�����������, ����������� � �������� ��������� ������ (������������� ������� ������)
    Stroka(const Stroka&); //����������� �����������
    virtual ~Stroka(); //����������
    char* GetStr(void)const { 

        return pCh;
    }
    int GetLen(void)const { 
        return len;
    }
    void Show(void)const;//�������, ������� ���������� pChar
};
// ���������� ������� ����� �STROKA� � ����������� �� ���� ������ �IdentStr�, �ComplexStr�
#endif
#pragma once