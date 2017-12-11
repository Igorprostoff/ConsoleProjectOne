#pragma once

#include <iostream>
using namespace std;

class Matrix
{
private:
	int l1;

	int l2;

	int ** matrixDyn;
		
public: 
	int ll1 = l1;
	int ll2 = l2;
		Matrix(int **matrix1Dyn, int l3, int l4);
		Matrix(int l1, int l2);
		Matrix();
		void vyvod_mat(Matrix Matr);
		
		void matrix_slozh(Matrix Matr1, Matrix Matr2, Matrix & Matr3);

		void matrix_umnozh(Matrix Matr1, Matrix Matr2, Matrix & Matr3);
	
		void matrix_vych(Matrix Matr1, Matrix Matr2, Matrix & Matr3);


		~Matrix();

	};



	



