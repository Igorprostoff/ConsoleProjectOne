// Funct_Overload.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;
// ПЕРЕГРУЗКА ФУНКЦИЙ, МЕТОДОВ И ОПЕРАТОРОВ 
// Перегрузка - объявление нескольких фукнций (а также методов классов и операторов, которые тоже 
// явяются функциями) с одинаковыми именами, но разным набором аргументов.
int fnc1(double p1, char p2)
{
	cout << "  fnc1(double, char)"<< endl;
	return p1 + p2;
}
int fnc1(int p1, short p2)
{
	cout <<"  fnc1(int, short)"<< endl;
	return p1 + p2;
}
int fnc1(long long p1, long long p2)
{
	cout<<" fnc1(long long, long long)"<< endl;
	return p1 + p2;
}

class sample_class {
public:
	sample_class(){}
	sample_class & operator -= (const sample_class & operand);
	int property1; //property- свойство
	double property2;

	int fnc1(double p1, char p2) {
		cout << "Sample_class::fnc1(double, char)" << endl;
		return p1 + p2;
	}

	int fnc1(int p1, short p2) {
		cout << "sample_class::fnc1(int, short)" << endl;
		return p1 + p2;
	}


	sample_class & operator +=(const sample_class & operand)
		//здесь Const - защита от забывчиывости - не дает изменить внутри метода операнд
		// который по логике и не должен меняться
	{
		property1 = property1 + operand.property1;
		this->property2 = this->property2 + operand.property2; // c this - эффект не менятеся
		return (*this);
	}
	
	//Общий синтаксис перегрузки операторов :
	/*Тип operator символ_оператора (тип имя_параметра, тип имя_парамера, ...)
	{

	}*/
};

/*	Также различие функций по одному выходному параметру не является перегрузкой
		int fnc1(double p1, char p2) 
		{
cout << "Sample_class::fnc1(double, char)" << endl;
return p1 + p2;

}  */

 
/* для компилтора критерием является сигнатура функции - имя + последовательность аргументов + их типы
даже если аргументы имеют разные названия, но типы и последовательности одинаковые
компилятор считает такой случай не перегрузкой, а повторным объявлением, что является ошибкой
*/
sample_class & sample_class::operator -= (const sample_class & operand) {
	property1 = property1 - operand.property1;
	this->property2 = this->property2 - operand.property2; // c this - эффект не менятеся
	return (*this);
}

int main() //Функция MAIN не может быть перегружена
{
	
	double a = 10.5;
	char b = 15;
	int c = 10000;
	short d = 101325;
	long long e = 1;

	fnc1(a,b);
	fnc1(e, e);
	fnc1(c, d);

	sample_class obj1;
	sample_class obj2;
	obj1.fnc1(a, b);
	obj1.fnc1(c, d);

	obj1.property1 = 11;
	obj1.property2 = 10.5;
	obj2.property1 = 111;
	obj2.property2 = 101.5;
	cout << endl;

	//Применение и проверка работы оператора "+="
	cout << "BEFORE += " << endl;
	cout << "obj1.property1 = " << obj1.property1 << endl;
	cout << "obj1.property2 = " << obj1.property2 << endl;
	obj1 -= obj2;
	cout << "AFTER += " << endl;
	cout << "obj1.property1 = " << obj1.property1 << endl;
	cout << "obj1.property2 = " << obj1.property2 << endl;
	getchar();
    return 0;
}
	
/*Высокоуровневая работа компилятора С++:
1.Прописывание коа по передаче параметров функций в стек перед вызовом
и очистка стека после вызова
2.Автоматический вызов конструктора и деструктора
3.Передача указателя для this внутри методов классов
*/
