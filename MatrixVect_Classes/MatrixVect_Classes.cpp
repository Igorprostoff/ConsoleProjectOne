// MatrixVect_Classes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Matrix.h"
#include "Vector.h"


Matrix operator + (Matrix lhs,
	Matrix rhs)
{
	Matrix result(1, 1);
	return result.matrix_slozh(lhs, rhs);
}

Matrix operator - (Matrix lhs,
	Matrix rhs)
{
	Matrix result(1, 1);
	return result.matrix_vych(lhs, rhs);
}

Matrix operator * (Matrix lhs,
	Matrix rhs)
{
	Matrix result(1, 1);
	return result.matrix_umnozh(lhs, rhs);
}

ostream & operator << (ostream & os,
	Matrix & rhs)
{
	rhs.vyvod_mat(rhs);
	return os;
}

using namespace std;

int main()
{

	Matrix Matr1;
	Matrix Matr2;

	for (int i = 0; i < Matr1.ll1; i++)
	{
		for (int j = 0; j < Matr1.ll2; j++)
		{
			cout << "Enter element "<<"["<<i<<"]"<<'['<<j<<"] ";
			cin >> Matr1.matrixDyn[i][j];
		}
	}

	cout << endl << "First matrix" << Matr1;
	for (int i = 0; i < Matr2.ll1; i++)
	{
		for (int j = 0; j < Matr2.ll2; j++)
		{
			cout << "Enter element " << "[" << i <<"]"<< '[' << j << "] ";
			cin >> Matr2.matrixDyn[i][j];
		}
	}
	cout <<"Second matrix" <<Matr2;

	cout << "Multiply"<< (Matr1 * Matr2);

	cout <<"Sum"<< Matr1 + Matr2;

	cout << "Difference" << Matr1 - Matr2;

	system("pause");

	return 0;
}

