#include "stdafx.h"
#include "Matrix.h"
#include <iostream>

using namespace std;

void Matrix::vyvod_mat(Matrix Matr1)
{
	cout << endl;
	cout << endl;
	int l1 = Matr1.l1;
	int l2 = Matr1.l2;
	for (int i = 0; i < l1; i++) {
		for (int j = 0; j < l2; j++)
		{
			cout << Matr1.matrixDyn[i][j] << " \t";
		}
		cout << std::endl;
	}
	cout << std::endl;
}

Matrix Matrix::matrix_slozh(Matrix Matr1, Matrix Matr2)
{
	int l3 = Matr1.l1;
	int l5 = Matr2.l1;
	int l4 = Matr1.l2;
	int l6 = Matr2.l2;

	if ((l3 == l5) && (l4 == l6))
	{
		Matrix Otv(Matr1.l1, Matr1.l2);
		int l1 = l3;
		int l2 = l4;
		for (int i = 0; i < l1; i++)
		{
			for (int j = 0; j < l2; j++)
			{
				Otv.matrixDyn[i][j] = 0;

				Otv.matrixDyn[i][j] = Matr1.matrixDyn[i][j] + Matr2.matrixDyn[i][j];

			}
		}

		return Otv;
	}

}

Matrix Matrix::matrix_vych(Matrix Matr1, Matrix Matr2)
{
	int l3 = Matr1.l1;
	int l5 = Matr2.l1;
	int l4 = Matr1.l2;
	int l6 = Matr2.l2;

	if ((l3 == l5) && (l4 == l6))
	{
		Matrix Otv(Matr1.l1, Matr1.l2);
		int l1 = l3;
		int l2 = l4;
		for (int i = 0; i < l1; i++)
		{
			for (int j = 0; j < l2; j++)
			{
				Otv.matrixDyn[i][j] = 0;

				Otv.matrixDyn[i][j] = Matr1.matrixDyn[i][j] - Matr2.matrixDyn[i][j];

			}
		}

		return Otv;
	}

}


Matrix Matrix::matrix_umnozh(Matrix Matr1, Matrix Matr2)
{
	int l3 = Matr1.l1;

	int l4 = Matr1.l2;

	int l5 = Matr2.l1;

	int l6 = Matr2.l2;

	if (l3 == l6)
	{
		Matrix Otv(Matr1.l1, Matr2.l2);

		for (int i = 0; i < l3; i++)
		{
			for (int j = 0; j < l3; j++)
			{
				Otv.matrixDyn[i][j] = 0;

				for (int k = 0; k < l4; k++)
				{
					Otv.matrixDyn[i][j] += (Matr1.matrixDyn[i][k] * Matr2.matrixDyn[k][j]);
				}

			}
		}
		return Otv;
	}
}

Matrix::Matrix()
{

	cout << "enter matrix length ";
	cin >> l1;
	ll1 = l1;
	cout << "enter matrix height ";
	cin >> l2;
	ll2 = l2;
	matrixDyn = new int *[l1];
	for (int i = 0; i < l1; i++)
	{
		matrixDyn[i] = new int[l2];

	}

	for (int i = 0; i < l1; i++) {
		for (int j = 0; j < l2; j++)
		{
			matrixDyn[i][j] = 0;
		}
	}
}

Matrix::Matrix(int lll1, int lll2)
{
	l1 = lll1;
	l2 = lll2;
	ll2 = l2;
	ll1 = l1;

	matrixDyn = new int *[l1];
	for (int i = 0; i < l1; i++)
	{
		matrixDyn[i] = new int[l2];

	}

	for (int i = 0; i < l1; i++) {
		for (int j = 0; j < l2; j++)
		{
			matrixDyn[i][j] = 0;
		}
	}
}
Matrix::Matrix(int **matrix1Dyn, int l3, int l4)
{
	l1 = l3;
	ll1 = l1;
	l2 = l4;
	ll2 = l2;
	matrixDyn = new int *[l1];
	for (int i = 0; i <l3; i++)
	{
		matrixDyn[i] = new int[l4];

	}

	for (int i = 0; i<l3; i++)
	{
		for (int j = 0; j < l4; j++) {
			matrixDyn[i][j] = matrix1Dyn[i][j];
		}
	}
}


Matrix::~Matrix()
{

}


