// MatrixVect_Classes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Matrix.h"
#include "Vector.h"


Matrix operator + (Matrix lhs,  //left hand side
	Matrix rhs) 
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

Matrix operator * (Matrix lhs,
	Matrix rhs) 
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
using namespace std;		
int main()
{
	
	Matrix Matr1;
	Matrix Matr2;
	
	Matr1.matrixDyn[0][0] = 1;
	Matr1.matrixDyn[0][1] = 2;
	Matr1.matrixDyn[1][0] = 3;
	Matr1.matrixDyn[1][1] = 4;

	Matr2.matrixDyn[0][0] = 5;
	Matr2.matrixDyn[0][1] = 6;
	Matr2.matrixDyn[1][0] = 7;
	Matr2.matrixDyn[1][1] = 8;


	Matrix Otvet11;

	Otvet11 = Matr1 * Matr2;
	cout << Otvet11;

	system("pause");
    
	return 0;
}

