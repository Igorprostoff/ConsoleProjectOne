// Avtomat.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "templ.h"
#include <iostream>

using namespace std;
int main()
{
	Matriz <int> a;
	Matriz <int> b;
	Matriz<int>c;
	c = a + b;
	c = a - b;
	c = a * b;
    return 0;
}

