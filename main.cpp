#include <iostream>
#include "Stroka.h"
#include "IdentStr.h"
#include "ComplexStr.h"

using namespace std;

int main() {
	Stroka** ptrs = new Stroka * [6];  //динамический массив указателей на указатель типа Stroka*
	ptrs[0] = new Stroka("June");
	ptrs[1] = new Stroka("internship");
	ptrs[2] = new IdentStr("please");
	ptrs[3] = new IdentStr("takeme");
	ptrs[4] = new ComplexStr("+1.5i-3");
	ptrs[5] = new ComplexStr("3i4");

	ptrs[0]->Show();
	Stroka* obj1 = dynamic_cast <Stroka*>(ptrs[0]); //динамическое приведение типа
	obj1->Show();
	Stroka* obj2 = dynamic_cast <Stroka*>(ptrs[1]);
	*(obj1) = *(obj2);
	obj1->Show();

	IdentStr* obj3 = dynamic_cast <IdentStr*>(ptrs[2]);
	IdentStr* obj4 = dynamic_cast <IdentStr*>(ptrs[3]);
	IdentStr res = *(obj3)+*(obj4);
	res.Show();

	ComplexStr* obj5 = dynamic_cast <ComplexStr*>(ptrs[4]);
	ComplexStr* obj6 = dynamic_cast <ComplexStr*>(ptrs[5]);
	ComplexStr comp = *(obj5) * *(obj6);
	comp.Show();

	Stroka test1; //проверка всех методом класса Stroka
	test1.Show();
	Stroka test2('O');
	test2.Show();
	Stroka test3("ZON");
	test3.Show();
	Stroka test4(test3);
	test4.Show();
	cout << test4.GetStr() << endl;
	cout << test4.GetLen() << endl;

	IdentStr test5; //проверка всех методов класса IdentStr
	test5.Show();
	IdentStr test6('I');
	test6.Show();
	IdentStr test7("tmo");
	test7.Show();
	IdentStr test8(test7);
	test8.Show();
	test8.Uppercase();
	test8.Show();
	IdentStr test9 = test8;
	test9.Show();
	cout << test9[0] << endl;
	IdentStr test10 = ~test9;
	test10.Show();
	int test11 = test6 > test7;
	cout << test11 << endl;
	IdentStr one("mos");
	IdentStr two("cow");
	one = one + two;
	one.Show();
	char three[] = "remote";
	one = one + three;
	one.Show();
	one = three + one;
	one.Show();

	ComplexStr number1; //проверка всех методов ComplexStr
	number1.Show();
	ComplexStr number2("+1i3");
	number2.Show();
	ComplexStr number3("15.22i-2i");
	number3.Show();
	ComplexStr number4("1i2");
	number4.Show();
	ComplexStr number5(number2);
	number5.Show();
	cout << number5.Get_real() << endl;
	cout << number5.Get_imaginary() << endl;
	number5 = number4;
	number5.Show();
	number5 = number4 * number3;
	number5.Show();
	int t;
	t = number2 == number5;
	cout << t << endl;

	delete[] ptrs; //очистка ptrs

	return 0;
}
