// Avtomat.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "templ.h"
#include <iostream>
#include <initializer_list>
#include <string>
#include <sstream>
#include <fstream>


int main()
{
	Matriz <int> a;
	Matriz <int> b;
	Matriz<int>c;
	c = a + b;
	c = a - b;
	c = a * b;
	std::cout << c;
    return 0;
}

