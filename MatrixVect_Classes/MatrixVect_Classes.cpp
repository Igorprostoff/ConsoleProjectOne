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
	Matrix Matrix1(matrixVectDyn, l3, l4);
	Matrix Matrix2();
	system("pause");
    return 0;
}

