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

void Matrix::matrix_slozh(Matrix Matr1, Matrix Matr2, Matrix & Matr3)
{
	int l3 = Matr1.l1;
	int l5 = Matr2.l1;
	int l4 = Matr1.l2;
	int l6 = Matr2.l2;

	if ((l3 == l5) && (l4 == l6)) 
	{
		int l1 = l3;
		int l2 = l4;
		for (int i = 0; i < l1; i++) 
		{
			for (int j = 0; j < l2; j++) 
			{
				Matr3.matrixDyn[i][j] = 0;

				Matr3.matrixDyn[i][j] = Matr1.matrixDyn[i][j] + Matr2.matrixDyn[i][j];

			}
		}
		
	}

}

void Matrix::matrix_vych(Matrix Matr1, Matrix Matr2, Matrix & Matr3)
{
	int l3 = Matr1.l1;
	int l5 = Matr2.l1;
	int l4 = Matr1.l2;
	int l6 = Matr2.l2;

	if ((l3 == l5) && (l4 == l6))
	{
		int l1 = l3;
		int l2 = l4;
		for (int i = 0; i < l1; i++)
		{
			for (int j = 0; j < l2; j++)
			{
				Matr3.matrixDyn[i][j] = 0;

				Matr3.matrixDyn[i][j] = Matr1.matrixDyn[i][j] - Matr2.matrixDyn[i][j];

			}
		}
	
	}

}


void Matrix::matrix_umnozh(Matrix Matr1, Matrix Matr2, Matrix & Matr3) 
{
		int l3 = Matr1.l1;

		int l4 = Matr1.l2;

		int l5 = Matr2.l1;

		int l6 = Matr2.l2;
		

	if ((l3 == l6) && (l3 != 1) && (l5 !=1)) 
	{
		Matrix Otv(Matr1.l1, Matr2.l2);
		
		for (int i = 0; i < l3; i++) 
		{
			for (int j = 0; j < l6; j++)
			{
				Otv.matrixDyn[i][j] = 0;

				for (int k = 0; k < l5; k++) 
				{

					Otv.matrixDyn[i][j] += (Matr1.matrixDyn[i][k] * Matr2.matrixDyn[k][j]);

				
				}
			
			}
		}
	}

	if ((l3 == 1) && (l5 == 1)) 
	{

		Matrix Otv(1, 1);

		int * vectDyn = new int [Matr2.l2];
		for (int i = 0; i < l2; i++) {
			vectDyn[i] = Matr2.matrixDyn[0][i];
		}

		int g1 = l3;
		int g2 = l5;
		if (g1 == g2) {
			int	otvet = 0;
			for (int i = 0; i < g1; i++) {

				otvet = otvet + Matr1.matrixDyn[0][i] * vectDyn[i];
			}
			Otv.matrixDyn[0][0] = otvet;
			for (int i = 1; i < Matr3.l2; i++) 
			{
				Otv.matrixDyn[0][i] = 0;
			}
		}
	}
}



Matrix::Matrix()
{
	
	cout << "enter matrix length ";
	cin >> l1;
	cout << "enter matrix height ";
	cin >> l2;
	matrixDyn = new int *[l1];
	for (int i = 0; i < l1; i++)
	{
		matrixDyn[i] = new int[l2];

	}

	for (int i = 0; i < l1; i++) {
		for (int j = 0; j < l2; j++)
		{
			matrixDyn[i][j] = 2;
		}
	}
}

Matrix::Matrix(int l1, int l2)
{
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
	l2 = l4;
	matrixDyn= new int *[l1];
	for (int i = 0; i <l3 ; i++)
	{
		matrixDyn[i] = new int[l4];

	}
	
	for (int i=0; i<l3;i++)
	{
		for (int j = 0; j < l4; j++) {
			matrixDyn[i][j] = matrix1Dyn[i][j];
		}
	}
}


Matrix::~Matrix()
{
	/*for (int i = 0; i < l1; i++)
	{
		delete matrixDyn[i];
	}
	delete[] matrixDyn;*/
}

