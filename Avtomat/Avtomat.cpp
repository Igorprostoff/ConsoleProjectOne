// Avtomat.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "templ.h"
#include <iostream>



int main()
{
	Matriz <int> a;
	Matriz <int> b;
	Matriz <int> c(1,1);

	for (int i = 0; i < a.ll1; i++)
	{
		for (int j = 0; j < a.ll2; j++)
		{
			
			a.A[i][j] = rand() % 5;
		}
	}

	cout << endl << "First matrix" << a;

	for (int i = 0; i < b.ll1; i++)
	{
		for (int j = 0; j < b.ll2; j++)
		{
	
			b.A[i][j]=rand()%5;
		}
	}
	cout << "Second matrix" << b;


	c = a + b;
	cout << c;
	c = a - b;
	std::cout << c;
	c = a * b;
	cout << c;

	system("pause");
    return 0;
}

