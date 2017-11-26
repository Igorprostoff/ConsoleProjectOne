#pragma once

#include <iostream>
using namespace std;

class Matrix
{
private:
	
		int l1;

		int l2;

		int ** matrixDyn = new int *[l1];
		int ** matrixDyn1;
public: 
		Matrix();

		Matrix(int **matrix1Dyn, int l3, int l4);
		
		void vyvod_mat(int ** matrixDyn, int l1, int l2);
		
		void vyvod_vect(int** vectorDyn, int g1);
		
		void matrix_slozh(int**& matrixDyn, int** matrix1Dyn, int l3, int l4, int** matrix2Dyn, int l5, int l6);
		
		void vect_slozh(int**& vectSumDyn, int **vector1, int g1, int ** vector2, int g2);

		void matrix_umnozh(int**& matrixDyn, int** matrix1Dyn, int l3, int l4, int** matrix2Dyn, int l5, int l6);
	
		void matrix_x_vect(int**& matrixDyn, int** matrix1Dyn, int l3, int l4, int **vector1, int g1);
		
		/*void vect_skal(int &otvet, int **vector1, int g1, int ** vector2, int g2);
		
		void vect_vect(int **& matrixVectDyn, int **vector1, int g1, int ** vector2, int g2, int**& vectSumDyn);*/
		
				
		~Matrix();

	};



	



