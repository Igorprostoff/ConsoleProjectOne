#pragma once

#include <iostream>
using namespace std;

class Matrix
{
public: 
	    int l1;

		int l2;

		int l3;

		int l4;

		int l5;

		int l6;

		int g2;

		int g1;

		int ** matrixVectDyn = new int *[g1];

		int ** matrixDyn = new int *[l1];

		int ** matrix1Dyn = new int *[l3];

		int ** matrix2Dyn = new int *[l5];

		void vyvod_mat(int ** matrixDyn, int l1, int l2)
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

		void vyvod_vect(int** vectorDyn, int g1)
		{
			for (int i = 0; i < g1; i++) {
				cout << vectorDyn[0][i] << " \t";
			}
			cout << std::endl;
		}

		void matrix_slozh(int**& matrixDyn, int** matrix1Dyn, int l3, int l4, int** matrix2Dyn, int l5, int l6)
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





		void vect_slozh(int**& vectSumDyn, int **vector1, int g1, int ** vector2, int g2)
		{
			if (g1 == g2) {
				for (int i = 0; i < g1; i++) {
					vectSumDyn[0][i] = 0;

					vectSumDyn[0][i] = vector1[0][i] + vector2[0][i];

				}
				vyvod_vect(vectSumDyn, g1);
			}
		}






		void matrix_umnozh(int**& matrixDyn, int** matrix1Dyn, int l3, int l4, int** matrix2Dyn, int l5, int l6)
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



		void matrix_x_vect(int**& matrixDyn, int** matrix1Dyn, int l3, int l4, int **vector1, int g1)
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

		void vect_skal(int &otvet, int **vector1, int g1, int ** vector2, int g2)
		{
			if (g1 == g2) {
				otvet = 0;
				for (int i = 0; i < g1; i++) {

					otvet = otvet + vector1[0][i] * vector2[0][i];
				}
				cout << otvet << endl;
			}
			else { cout << "Uncountable" << endl; }
		}
		void vect_vect(int **& matrixVectDyn, int **vector1, int g1, int ** vector2, int g2, int**& vectSumDyn)
		{
			if ((g1 == 3) && (g2 == 3)) {
				for (int i = 0; i < 3; i++) {
					if (i == 0) {
						for (int j = 0; j < 3; j++) {

							matrixVectDyn[i][j] = 1;
						}

					}
					else {
						if (i == 1) {
							for (int j = 0; j < 3; j++) {

								matrixVectDyn[i][j] = vector1[0][j];

							}
						}
						else {
							for (int j = 0; j < 3; j++) {

								matrixVectDyn[i][j] = vector2[0][j];

							}
						}
					}
				}

				for (int i = 0; i < 3; i++) {
					vectSumDyn[0][i] = 0;
				}
				for (int i = g1 - 1; i > -1; i--) {
					(i == 0) ?
						(vectSumDyn[0][i] = matrixVectDyn[1][(i + 1) / 3] * matrixVectDyn[2][i + 1] - matrixVectDyn[1][i + 1] * matrixVectDyn[2][(i + 1) / 3])
						:
						(vectSumDyn[0][i] = matrixVectDyn[1][(i + 1) / 3] * matrixVectDyn[2][2] - matrixVectDyn[1][2] * matrixVectDyn[2][(i + 1) / 3]);
				}
				vyvod_vect(vectSumDyn, g1);
			}
			else { cout << "Uncountable pair of vectors"; }
		}
		
	};



	



