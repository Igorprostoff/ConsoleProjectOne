// Avtomat.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "templ.h"
#include <iostream>



int main()
{
	Matrix <double> a;
	Matrix <double> b;
	Matrix <double> c(0,0);

	for (int i = 0; i < a.ll1; i++)
	{
		for (int j = 0; j < a.ll2; j++)
		{
			
			a[i][j] = 1.5;
		}
	}

	std::cout << std::endl << "First matrix" << a;

	for (int i = 0; i < b.ll1; i++)
	{
		for (int j = 0; j < b.ll2; j++)
		{
	
			b[i][j]=3.6;
		}
	}
	std::cout << "Second matrix" << b;


	c = a + b;
	std::cout << "SUM : " << std::endl;
	std::cout << c;

	c = a - b;
	std::cout << "Subtraction : " << std::endl;
	std::cout << c;

	c = a * b;
	std::cout << "Multiplication : " << std::endl;
	std::cout << c;

	
	for (int i = 0; i < c.ll1; i++)
	{
		for (int j = 0; j < c.ll2; j++)
		{

			c[i][j] = 1;
		}
	}

	cout << endl << c[1][1]<< endl;

	cout << c;
	system("pause");
    return 0;
}

