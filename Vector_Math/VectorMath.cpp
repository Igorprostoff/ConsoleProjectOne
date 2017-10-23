// VectorMath.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

//сложение матриц, сложение векторов, умножение матриц,
//умножение матрицы на вектор, скалярное умножение векторов, 
//векторное умножение векторов реализовать программно
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
}

void vyvod_mas(int vector1[1][3])
{
	for (int i = 0; i < 3; i++) {
		std::cout << vector1[0][i] << " \t";
	}
}

int main()
{
	int otvet = 0; //инициализируем переменную для записи результата скалярного произведения векторов
	int matrix1[3][3] = { { 1, 2, 3 }, //инициализируем первую матрицу
						  { 4, 5, 6 },
						  { 7, 8, 9 } };
	int matrix2[3][3] = { {10, 11, 12}, //инициализируем вторую матрицу
						  {13, 14, 15},
						  {16, 17, 18} };
	int matrix_sum[3][3] = { {0,0,0}, //инициализируем матрицу для записи результата сложения матриц и умножения матриц
						     {0,0,0},
						     {0,0,0} };
	int vector1[1][3] = { 1, 2, 3 }; //инициализируем первый вектор-столбец
	int vector2[1][3] = { 1, 2, 3 };//инициализируем второй вектор-столбец
	int vector_sum[1][3] = { 0,0,0 }; //инициализируем вектор - столбец для записи результата векторного произведения и сложения векторов
	// сложение матриц
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {    
			matrix_sum[i][j] = matrix1[i][j] + matrix2[i][j]; //через вложеный цикл поочередно складываем соответственные элементы матриц 
		}                                                     //и записываем их в соответственные элементы матрицы matrix_sum
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			std::cout << matrix_sum[i][j] << " \t"; //выводим матрицу поэлементно с табуляцией и переносом строки каждые 3 элемента
		}
		std::cout << std::endl;
	}

	//сложение векторов
	for (int i = 0; i < 3; i++) {
		vector_sum[0][i] = vector1[0][i] + vector2[0][i]; //через цикл складываем соответственные элементы векторов 
	}                                                      //и записываем результаты поэлементно в третий вектор

	std::cout << std::endl;

	std::cout << vector_sum[0][0] << "\n" << vector_sum[0][1] << "\n" << vector_sum[0][2] << std::endl; //выводим по одному элементу вектора 
	                                                                                                      //с переносом строки между ними
	std::cout << std::endl;

	//умножение матриц
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix_sum[i][j] = 0; //обнуляем каждый элемент матрицы, с которым будем работать далее
			
				for (int k = 0; k < 3; k++)
					matrix_sum[i][j] = matrix_sum[i][j] + matrix1[i][k] * matrix2[k][j]; //попарно перемножаем соответственные элементы матриц 
			                                                                             //и последовательно суммируем их с элементом матрицы matrix_sum (далее будет именоваться "матрица-ответ")
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			std::cout << matrix_sum[i][j] << "\t ";   //по одному выводим элементы матрицы-ответа с табуляцией 
		}                                             //и переносом строки каждые 3 элемента
		std::cout << std::endl;

	}
	std::cout << std::endl;


	//матрица на вектор
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix_sum[i][j] = 0; //обнуляем значение каждого элемента матрицы-ответа
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix_sum[i][0] = matrix_sum[i][0] + matrix1[i][j] * vector1[0][j]; //в 1 столбец матрицы-ответа записываем поочередно результаты 
		}                                                                        //произведения элементов матрицы с элементом вектора
	}
	std::cout << std::endl; 
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			std::cout << matrix_sum[i][j] << " \t"; //по одному выводим элементы матрицы-ответа с табуляцией 
		}                                             //и переносом строки каждые 3 элемента
		std::cout << std::endl;
	}
	std::cout << std::endl;
	//скалярное пр-ие
	otvet = 0;
	for (int i = 0; i < 3; i++) {
		otvet = otvet + vector1[0][i] * vector2[0][i]; //поочередно складываем результаты произведений соответственных элементов векторов
	}
	std::cout << otvet << std::endl; //выводим ответ
	std::cout << std::endl;



	//векторное произведение
	int matrix_vect[3][3]; //объявление матрицы для последующего вычисления определителя
	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			for (int j = 0; j < 3; j++) {
				matrix_vect[i][j] = 1; //присвоение элементам первой строки значений единицы (т.к. там единичные векторы)
			}

		}
		else {
			if (i == 1) {
				for (int j = 0; j < 3; j++) {
					matrix_vect[i][j] = vector1[0][j];  //присвоение второй строке значений первого вектора
				}
			}
			else {
				for (int j = 0; j < 3; j++) {
					matrix_vect[i][j] = vector2[0][j]; //присвоение третьей строке значений второго вектора
				}
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		vector_sum[0][i] = 0; //обнуление вектора в который будет записываться результат
	}

	vector_sum[0][0] = matrix_vect[1][1] * matrix_vect[2][2] - matrix_vect[1][2] * matrix_vect[2][1];
	std::cout << vector_sum[0][0] << "\n";  
	vector_sum[0][1] = matrix_vect[1][0] * matrix_vect[2][2] - matrix_vect[1][2] * matrix_vect[2][0];
	std::cout << vector_sum[0][1] << "\n"; 
	vector_sum[0][2] = matrix_vect[1][0] * matrix_vect[2][1] - matrix_vect[1][1] * matrix_vect[2][0];
	std::cout << vector_sum[0][2] << "\n";  //вычисление определителя матрицы matrix_vect, запись результата и его вывод
	std::cout << "\n";

	//проверка автоапдейта на гитлабе
	// Второй вариант решения векторного произведения

	for (int i = 0; i < 3; i++) {
		vector_sum[0][i] = 0;      //Обнуление вектора для вывода
	} 
	for (int i = 2; i > -1; i--) { //Используем математическую закономерность между числовыми значениями индексами перемножаемых элементов и через цикл высчитываем определитель
		(i == 0) ?
			(vector_sum[0][i] = matrix_vect[1][(i + 1) / 3] * matrix_vect[2][i + 1] - matrix_vect[1][i + 1] * matrix_vect[2][(i + 1) / 3]) 
			:
			(vector_sum[0][i] = matrix_vect[1][(i + 1) / 3] * matrix_vect[2][2] - matrix_vect[1][2] * matrix_vect[2][(i + 1) / 3]);
	}
	for (int i = 0; i < 3; i++) {
		std::cout << vector_sum[0][i] << std::endl; //вывод матрицы
	}
	getchar();
	return 0;
}

