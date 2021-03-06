// Funct.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void matrix_slozh(int(&matrix_sum)[3][3], int matrix1[3][3], int matrix2[3][3])
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix_sum[i][j] = 0;

			matrix_sum[i][j] = matrix1[i][j] + matrix2[i][j];

		}
	}
}





void vect_slozh(int(&vector_sum)[1][3], int vector1[1][3], int vector2[1][3])
{
	for (int i = 0; i < 3; i++) {
		vector_sum[0][i] = 0;

		vector_sum[0][i] = vector1[0][i] + vector2[0][i];

	}

}



void matrix_umnozh(int(&matrix_sum)[3][3], int matrix1[3][3], int matrix2[3][3])
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			matrix_sum[i][j] = 0;

			for (int k = 0; k < 3; k++)

				matrix_sum[i][j] = matrix_sum[i][j] + matrix1[i][k] * matrix2[k][j];

		}
	}
}



void matrix_x_vect(int(&matrix_sum)[3][3], int matrix1[3][3], int vector1[1][3])
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			matrix_sum[i][j] = 0;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			matrix_sum[i][0] = matrix_sum[i][0] + matrix1[i][j] * vector1[0][j];
		}
	}
}

void vect_skal(int &otvet, int vector1[1][3], int vector2[1][3])
{
	otvet = 0;
	for (int i = 0; i < 3; i++) {

		otvet = otvet + vector1[0][i] * vector2[0][i];
	}
}
void vect_vect(int(&matrix_vect)[3][3], int vector1[1][3], int vector2[1][3], int(&vector_sum)[1][3])
{
	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			for (int j = 0; j < 3; j++) {

				matrix_vect[i][j] = 1;
			}

		}
		else {
			if (i == 1) {
				for (int j = 0; j < 3; j++) {

					matrix_vect[i][j] = vector1[0][j];

				}
			}
			else {
				for (int j = 0; j < 3; j++) {

					matrix_vect[i][j] = vector2[0][j];

				}
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		vector_sum[0][i] = 0;
	}
	for (int i = 2; i > -1; i--) {
		(i == 0) ?
			(vector_sum[0][i] = matrix_vect[1][(i + 1) / 3] * matrix_vect[2][i + 1] - matrix_vect[1][i + 1] * matrix_vect[2][(i + 1) / 3])
			:
			(vector_sum[0][i] = matrix_vect[1][(i + 1) / 3] * matrix_vect[2][2] - matrix_vect[1][2] * matrix_vect[2][(i + 1) / 3]);
	}
}
void vyvod_mat(int matrix_sum[3][3])
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			std::cout << matrix_sum[i][j] << " \t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void vyvod_vect(int vector1[1][3])
{
	for (int i = 0; i < 3; i++) {
		std::cout << vector1[0][i] << " \t";
	}
	std::cout << std::endl;
}

int main()
{
	int matrix_vect[3][3];

	int otvet = 0; 

	int matrix1[3][3] = { { 1, 2, 3 }, 
	{ 4, 5, 6 },
	{ 7, 8, 9 } };

	int matrix2[3][3] = { { 10, 11, 12 },
	{ 13, 14, 15 },
	{ 16, 17, 18 } };

	int matrix_sum[3][3] = { { 0,0,0 }, 
	{ 0,0,0 },
	{ 0,0,0 } };

	int vector1[1][3] = { 1, 2, 3 }; 

	int vector2[1][3] = { 1, 2, 3 };

	int vector_sum[1][3] = { 0,0,0 };
									  
	matrix_slozh(matrix_sum, matrix1, matrix2);

	vyvod_mat(matrix_sum);

	vect_slozh(vector_sum, vector1, vector2);

	vyvod_vect(vector_sum); std::cout<<std::endl;

	matrix_umnozh(matrix_sum, matrix1, matrix2);

	vyvod_mat(matrix_sum);

	matrix_x_vect(matrix_sum, matrix1, vector1);

	vyvod_mat(matrix_sum);

	vect_skal(otvet, vector1, vector2);

	std::cout << otvet << std::endl << std::endl;

	vect_vect(matrix_vect, vector1, vector2, vector_sum);

	vyvod_vect(vector_sum);

	getchar();
    return 0;
}

