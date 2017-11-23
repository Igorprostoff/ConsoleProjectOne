#include "stdafx.h"
#include "Matrix.h"


Matrix::Matrix()
{ 
	class Matrix {
	
	
		void Matrix::vyvod_vect(int** vectorDyn, int g1)
		{
			for (int i = 0; i < g1; i++) {
				cout << vectorDyn[0][i] << " \t";
			}
			cout << std::endl;
		}

		void Matrix::vyvod_mat(int ** matrixDyn, int l1, int l2)
		{
			for (int i = 0; i < l1; i++) {
				for (int j = 0; j < l2; j++)
				{
					cout << matrixDyn[i][j] << " \t";
				}
				cout << std::endl;
			}
			cout << std::endl;
		}

		void Matrix::matrix_slozh(int**& matrixDyn, int** matrix1Dyn, int l3, int l4, int** matrix2Dyn, int l5, int l6)
		{
			if ((l3 == l5) && (l4 == l6)) {
				int l1 = l3;
				int l2 = l4;
				for (int i = 0; i < l1; i++) {
					for (int j = 0; j < l2; j++) {
						matrixDyn[i][j] = 0;

						matrixDyn[i][j] = matrix1Dyn[i][j] + matrix2Dyn[i][j];

					}
				}
				vyvod_mat(matrixDyn, l1, l2);
			}
			else { cout << "Sum cant be found"; }
		}

		void Matrix::matrix_umnozh(int**& matrixDyn, int** matrix1Dyn, int l3, int l4, int** matrix2Dyn, int l5, int l6)
		{
			if ((l3 == l6) && (l4 == l5)) {
				int l1 = l3;
				int l2 = l4;
				for (int i = 0; i < l1; i++) {
					for (int j = 0; j < l2; j++) {

						matrixDyn[i][j] = 0;

						for (int k = 0; k < l2; k++)

							matrixDyn[i][j] = matrixDyn[i][j] + matrix1Dyn[i][k] * matrix2Dyn[k][j];

					}
				}
				vyvod_mat(matrixDyn, l1, l2);
			}
			else { cout << "Uncountable pair of matrix" << endl; }
		}

		void Matrix::matrix_x_vect(int**& matrixDyn, int** matrix1Dyn, int l3, int l4, int **vector1, int g1)
		{

			if (l4 == g1) {
				for (int i = 0; i < l3; i++) {

					matrixDyn[0][i] = 0;

				}
				for (int i = 0; i < l3; i++) {
					for (int j = 0; j < l4; j++) {

						matrixDyn[0][i] = matrixDyn[0][i] + matrix1Dyn[i][j] * vector1[0][j];

					}
				}
				vyvod_vect(matrixDyn, g1);
			}
			else { cout << "Uncountable" << endl; }
		}
	};

}


