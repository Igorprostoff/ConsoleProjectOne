// Structures.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <array>
#include <vector>
#include <list>
#include <map>
#include <iostream>
#include <string>
#include <cmath>
#include <math.h>
#include <exception>
//std::array
//инкапсулирует массивы неизменной длины, является шаблоном
//std::vector
//std::list
//std::map


//STD - стандартная библиотека языка С++ (функции printf, getchar, fopen, read - из данной библиотеки)
//Является связующим звеном
//[C++] -> [STD] -> [OC]

// STL - standard template library (template - шаблон)
// это расширение STD, содержащиее структуры данных 
// и функции по работе с ними
//именно из STL подключаются потоки cout, cin, fstream, ifstream, ofstream, 
// контейнеры array, vector, list, map,
//итераторы,
//Адгоритмы sort, copy, 
int main()
{
	std::array<double, 10> double_array; //объект, построеный из шаблона std::array, инкпсулирующий массив
	//для создания двухмерных массивов 
	std::array<std::array<int, 3>, 3> mat33;
	double_array[5] = 10.5;
	double_array.fill(0.0);
	int array_length = double_array.size();
	//double_array.swap() - функция для обмена между содержимым двух массивов
	std::sort(double_array.begin(), double_array.end());
	std::array<double, 20> double_array1;
	std::copy(double_array.begin(), double_array.end(), double_array.begin());
	//итератор - объект, сылающийся на элемент массива,
	//вектора или списка, "улучшеный" вариант переменной счетчика
	//нужен для связи шаблонов STL
	std::array<double, 10>::iterator array_iterator;

	//std::vector
	//инскапсулирует одномерный массив и предоставляет средства
	// для изменеия его длины
	// очень близким к std::vector по функционалу является std::string
	//ОСНОВНОЙ НЕДОСТАТОК
	//Однако, каждый раз при увеличении длины vector запрашивает у ОС новую лбласть памяти и копирует туда старую. Старую освобождает.
	//ОСНОВНОЕ ПРЕИМУЩЕСТВО
	//Доступ к элементам осуществляется быстро напряму по адресу
	// [адрес_1+i]
	//ВЫВОД
	//Доступ быстрый, а увеличение или вставка - медленное

	std::vector<long long> long_vector = { 50, 10, 20 };

	std::cout << "vector<> = ";
	for (long long value : long_vector)
		std::cout << value << '\t';
	std::cout << std::endl;


	long_vector.push_back(25);
	long_vector.push_back(0);

	std::cout << "vector<> = after push() ";
	for (long long value : long_vector)
		std::cout << value << '\t';
	std::cout << std::endl;

	//также у std::vector пристутствует весь функционал std::array
	//размер, сортировка, итераторы, копирование, обмен и тд

	std::sort(long_vector.begin(), long_vector.end());

	std::cout << "vector<> = after sort ";
	for (long long value : long_vector)
		std::cout << value << '\t';
	std::cout << std::endl;
	long_vector[2] = 11;

	//вставка в vector
	long_vector.insert(long_vector.begin() + 1, 100/*с помощью шаблона можно вставить несколько значений*/);
	std::cout << "vector<> = after insert ";
	for (long long value : long_vector)
		std::cout << value << '\t';
	std::cout << std::endl;

	//std::list
	// все наоборот - вставка и увеличение списка производится быстрее, чем в vector
	//а доступ - медленнее, причем, чем дальше от 1 элемента, тем медленнее
	//так как для доступа к i-ому элементу (определению его адреса в ОП) необходимо
	//пройти по цепочке от 1-го элемента

	//в отличие от array и vector не является компактным массивом памяти 
	//элементы в std::list представлены отдельными объектами, связанными др с другом указателями, которые они хранят
	// [null|данные|указатель] ----> [указатель|данные|указатель] ---->
	//
	//
	//          [указатель|данные|указатель]----> 
	//  [указатель|данные|] 

	std::list<char> char_list;
	char_list.push_front('a'); // вставка перед первым элементом
	char_list.push_back('c'); //вставка после последнего

	for (char ch : char_list)
	{
		std::cout << ch << std::endl;
	}
	//если класс простой и не содержит динамических данных

	class sample_class
	{
		int a;
		double b;


	};
	//список можно составлять из объектов класса
	std::list<sample_class>obj_list1;
	// в противном случае - из указателей на обекты
	std::list<sample_class>obj_list2;

	//std::map
	//состоит из пар "ключ" - "значение"
	//Например "Ту-154" - "5000", "Boeing 777" - "6000", "A320" - "6500"
	std::map<std::string, double> plane_and_range = { {"Ту-154" ,5000}, {"Boeing 777" ,6000}, {"A320" ,6500} };

	std::cout << "The range of Boeing 777 is " << plane_and_range["Boeing 777"] << std::endl;
	plane_and_range.insert({ "Boeing 737", 7000});
	std::cout << "The range of Boeing 737 is " << plane_and_range["Boeing 737"] << std::endl;

	double d_array[5] = { 1,2,3,4,5 };
	int i = 60000;
	try// в try помещается код, потенциально способный вызывать исключение
		//функции, не получающие доступа к файлам, портам, устройствам и тд
		//функции, неправильно работающие с памятью
		//
	{
		d_array[i] = 15;
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Error in \"d_array[i] = 15\"" << std::endl;
	}
	getchar();
    return 0;
}

// в курс не вошли темы, необходимые для штатной коммерческой разработки ПО
// - юнит - тестирование (на каждый модуль или проект, создается проект, который производит тестирование
//, причем, сборка и запуск sln настраивается таким образом, что в первую очередь собирается базовый проект
//затем собирается код теста и запускается)
// - технологии, процессы и шаблоны разработки (SCRUM, Waterfall, Agile, ...)
// - создание графических приложений
// - многопоточные и ассинхронные приложения