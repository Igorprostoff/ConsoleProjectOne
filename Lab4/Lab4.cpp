// Lab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

//функции
//функция- фрагмент кода, имеющая свое имя (идентификатор), а также интерфейс (входные и выходные параметры ) 
//код офрмляется в виде функции в случаях:
//1. Необходимости частого использования одного и того же фрагмента кода
//2. для упорядочивания больших массивов кода
//
//синтаксис объявления функции
	//тип_выходнгого_параметра имя_функции (тип имя_параметра1, тип имя_параметра2, ...) - заголовок (объявление функции)
	//{ ... выполняемые операторы 
    // return выходное значение; (если функция-void, то просто return)} - тело (определение) функции
	//void имя_функции (тип имя_параметра1, тип имя_параметра2, ...) - не возвращает значение
	//void имя_функции() - нет входных и выходных параметров

	//пример 1
int fnc1(double p1, //размерность метры
	char p2, //размерность см
	int const p3) // размерность км
	// если переменную объявить как константу, то в теле ее нельзя изменить
{//переменные, объявленные внутри функции, видны только внутри функции
	//то, что передается в параметры, передаются в виде копий, их можно менять внутри функции(но зачем?)
	//передача параметров по значению
	p1 = 2.5;
	return p1 + p2/100 + p3*1000; //типы приводятся автоматически
}
// пример 2 объявление функции в начале отдельно от тела
int fnc2(double p1, //размерность метры
	char p2, //размерность см
	int p3); // размерность км
// using namespace std; - если уверен, что пространства имен не пересекаются
int main()
{
	double d = 1.5;
	char ch = 1000;
	int ret_value = 0;
	fnc1(d, ch, 5);
	ret_value = fnc1(d, ch, 5);
	std::cout << "fnc1(d,ch,5) = " << ret_value << std::endl;
	
	
	getchar();
	//функция должна быть объявлена до момента ее первого использования
	//потому что компилятор проходит текст программы всего один раз 
	//и если он встретит функцию где-то после, назад с объявленой функцией он уже не вернется

	

    return 0;
}
// определение функции в самом конце (заголовок повторяется)
int fnc2(double p1, //размерность метры
		char p2, //размерность см
	int p3)
{
	return p1 + p2 / 100 + p3 * 1000;
}
//1. Что такое функции 
//2. области вилдимости
//3. передача парамтров по значению
//4.
