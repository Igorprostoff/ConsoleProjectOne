// Strings_Files.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <bitset>
//СТРОКИ
//
//Строки старого С - типа представляют из себя массив символов с нулевым окончанием
char cstr1[] = "C-style string";
char cstr2[] = {'C', 's' ,'t' ,'y' ,'l', 'e' ,' ','s', 't' ,'r' ,'i' ,'n', 'g' ,'\0'};

std::string cppstr1 = "C++ - style string";
std::string cppstr2 = "C++ - style string";

using namespace std;
//Функции для работы с С-строками
//вывод на печать printf(char[], , ,)

//С помощью printf можно не просто печатать готовую строку
//но и подставлять в нее другие переменные, попутно преобразовывая их
//в символьный вид и применяя форматирование

//позиции, куда будут подставляться параметры, обозначаются в базовой строке
//Символом '%'

// значение смимволов форматирования берется из таблицы справки к функции http://www.cplusplus.com/reference/cstdio/printf/
//значение некоторых из них
//%f - параметр подставляется на место %f, оформленное в виде числа с плавающей точкой
//%s - параметр подставляется на место %s как строка
//%d - параметр подставляется на место как целое число
//%e - параметр подставляется на место как число в экспоненциальном виде
//

//форматирование  printf("базовая %s строка %f", парметр1, параметр2)

//объединение строк strcat(* char, * char)
//копирование из одной строки в другую strcpy
// сравнение двух строк strcmp()
//длина строки strlen()

int main()
{
	printf(cstr2);
	printf("\n \n"); // в функцию передается массив(а имя массива является указателем на самый первый элемент) char, либо указатель на *char
	printf("Insert double: %f"
		"\n insert long long: %d"
		"insert string : %s"
		"\n, insert exponensial: %e" //мантисса - дробное число между 1 и 2 возводимое в степень 10^экспонента
		"\n insert double with precision:%10.2f" //10.2 - 10 пустых мест до запятой и 2 после
		"\n ERROR insert long long as double: %f"
		"\n ERROR insert double as int: %010d\n",
		1000.15,
		132456789,
		"string = )",
		1123456.1123456,
		1.1123456,
		(long long)10000,
		10.5);

	//В стандартной библиотеке С++ массив символов инкапсулирован в класс std::string
	//в который также собраны самые частоиспользуемы методы обработки и для которого перегружены операторы

	char cstr3[255];
	
	//Сравнение
	int i = strcmp(cstr1, cstr2);

	printf_s("Result of strcmp(%s, %s) = %d\n", cstr1, cstr2, i+1);
	
	cout<<" (cppstr1 == cppstr2) = \t" << (cppstr1 == cppstr2) << endl;
	//Длина
	int length = strlen(cstr1);
	
	printf_s("Result of strlen(%s) = %d\n", cstr1, length);
	
	cout << " std::string.length() \t" << cppstr1.length() << endl;
	//Копирование
	strcpy_s(cstr3, 255, cstr2);
	
	printf_s("Result of strcpy(%s, %s) = %s\n", cstr1, cstr2, cstr3);
	
	cppstr2 = cppstr1;
	
	cout << " Instead of strcpy use operator  = \t" << cppstr2 << endl;
	//Конкатинация
	strcat_s(cstr3, 255, cstr1);
	
	cout << "Result of strcat (cstr2, cstr1) = " << cstr3 << endl;
	
	cout << " instead of concat use operator + \t " << (cppstr1 + cppstr2) << endl;
	
	// std::fstream - универсальный класс для ввода (чтения из файла) и для вывода (запись в файл)
	// std::ifstream  - класс для ввода (чтения из файла)
	// std::ofstream  - класс для вывода (запись в файл)
	//Аналогично cout- потоку , предназначенному для вывод на консоль
	//fstream является потоком, предназначенным для ввода\вывода из\в файл
	fstream fs;
	fs.open("some text file.txt", //при открытии файла необходимо указать имя файла
								  //а также режим открытия: с перезаписью или без, для чтения\для записи\оба режима и т.д.
		std::fstream::in  //добавляется режим вывода из файла
		| std::fstream::out//добавляется режим записи в файл
	// | std::fstream::out //добавляется режим с записью в конец файла
		|	std::fstream::trunc); //trunc = truncate - режим с перезаписью файла
	
		auto fstream_mode = std::fstream::in | std::fstream::out | std::fstream::app; 
		//чтобы не вникать в типы стандартной библиотеки, используется тип auto
		//в зависимости от правой части выражения компилятор сам подбирает тип
		cout << "std::fstream::in | std::fstream::out | std::fstream::app = " << bitset<8>(fstream_mode)<< endl;
		fs << 1000.15 << endl<<123456789<<endl << "string =)"<<endl << 1123456.1123456 <<endl << 1.1123456<<endl << (long long)10000 <<endl << 10.5<<endl << endl;
		fs.close();
	getchar();
    return 0;
}

