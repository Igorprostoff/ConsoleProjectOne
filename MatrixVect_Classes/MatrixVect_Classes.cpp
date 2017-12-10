// MatrixVect_Classes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Matrix.h"
#include "Vector.h"

Matrix operator + (Matrix lhs,  //left hand side
	Matrix rhs) //right hand side
{ 
	Matrix result;

	result.matrix_slozh(lhs, rhs, result);

	return result;
}

Matrix operator - (Matrix lhs,  //left hand side
	Matrix rhs) //right hand side
{
	Matrix result;

	result.matrix_vych(lhs, rhs, result);

	return result;
}

Matrix operator * (Matrix lhs,  //left hand side
	Matrix rhs) //right hand side
{
	Matrix result;

	result.matrix_umnozh(lhs, rhs, result);

	return result;
}

ostream & operator << (ostream & os, //левосторонний оператор, cout
	Matrix & rhs) //правосторонний оператор, собственно то, что выводится
{
	rhs.vyvod_mat(rhs);
	return os;
}

int main()
{
	
	Matrix Matr1;
	Matrix Matr2;
	Matrix Otvet11;
	Otvet11 = Matr1 + Matr2;
	
	Otvet11.vyvod_mat(Otvet11);

	Otvet11 = Matr1 - Matr2;

	Otvet11.vyvod_mat(Otvet11);

	Otvet11 = Matr1 * Matr2;

	Otvet11.vyvod_mat(Otvet11);
	cout << Otvet11;
	system("pause");
    
	return 0;
}

