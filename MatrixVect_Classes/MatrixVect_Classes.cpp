// MatrixVect_Classes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Matrix.h"
#include "Vector.h"

int main()
{

	
	int l3 = 3;
	int l4 = 3;
	int ** matrixVectDyn = new int *[l3];
	for (int i = 0; i < l3; i++)
	{
		matrixVectDyn[i] = new int[l4];

	}
	for (int i = 0; i < l3; i++) {
		for (int j = 0; j < l4; j++)
		{
			matrixVectDyn[i][j] = 1;
		}
	}

	int g1 = 5;

	int ** vectDyn = new int *[1];

	for (int i = 0; i < 1; i++)
	{
		vectDyn[i] = new int[g1];

	}

	int ** vect1Dyn = new int *[1];

	for (int i = 0; i < 1; i++)
	{
		vect1Dyn[i] = new int[g1];

	}
	
	
	/*Matrix Matr1;

	Matrix Otvet;

	Matrix Matr2;

	Matr1.vyvod_mat(Matr1);
	Matr2.vyvod_mat(Matr2);
	Matr1.matrix_umnozh(Matr1, Matr2, Otvet);
	Matr1.matrix_slozh(Matr1, Matr2, Otvet);*/

	Vector Vect1;
	Vector Vect2;
	Vector Otvet1;
	Vect1.vyvod_mat(Vect1);
	
	Vect2.vyvod_mat(Vect2);
	cout << "Slozh: ";
	Vect1.matrix_slozh(Vect1, Vect2, Otvet1);
	cout << "Umnozh: ";
	Vect2.vect_vect(Vect1, Vect2, Otvet1);

	system("pause");
    
	return 0;
}

