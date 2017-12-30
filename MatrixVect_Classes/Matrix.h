#pragma once

#include <iostream>

using namespace std;
//template <class Type>
class Matrix
{
private:
	int l1;

	int l2;

public:
	int ** matrixDyn;

	int ll1;
	
	int ll2;

	Matrix(int **matrix1Dyn, int l3, int l4);
	Matrix(int l1, int l2);
	Matrix();

	void vyvod_mat(Matrix Matr);

	Matrix matrix_slozh(Matrix Matr1, Matrix Matr2);

	Matrix matrix_umnozh(Matrix Matr1, Matrix Matr2);

	Matrix matrix_vych(Matrix Matr1, Matrix Matr2);


	~Matrix();

};



	



