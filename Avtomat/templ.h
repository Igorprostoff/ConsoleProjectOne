#pragma once

#include "stdafx.h"
#include <iostream>


using namespace std;

template <class T> class Matrix
{
public:
	T ** matrixDyn;
	int ll1;
	int ll2;
	~Matrix();
	Matrix();
	Matrix(int r1, int r2);
	Matrix(T **A,int l3,int l4);
	void matrix_umnozh(Matrix <T> matrix1, Matrix <T> matrix2, Matrix<T>matrix3);
	void matrix_slozh(Matrix <T> matrix1, Matrix <T> matrix2, Matrix<T> matrix3);
	void matrix_vych(Matrix <T> matrix1, Matrix <T> matrix2, Matrix <T> matrix3);
	void vyvod_matr(Matrix <T> matrix3);
template <typename T>friend ostream &operator<< (ostream &os, const Matrix<T> &rhs);


T* operator[](int elem)
{
	return matrixDyn[elem];
}

private:
	int l1;
	int l2;

};

template <typename T>
Matrix<T>::Matrix()
{
	cout << "enter matrix length ";
	cin >> l1;
	ll1 = l1;
	cout << "enter matrix height ";
	cin >> l2;
	ll2 = l2;

	matrixDyn = new T *[l1];

	for (int i = 0; i < l1; i++)
	{
		matrixDyn[i] = new T [l2];

	}

	for (int i = 0; i < l1; i++) {
		for (int j = 0; j < l2; j++)
		{
			matrixDyn[i][j] = 0;
		}
	}
}

template <typename T>
Matrix<T>::Matrix(int r1, int r2)
{
	l1 = r1;
	ll1 = l1;
	l2 = r2;
	ll2 = l2;
	matrixDyn = new T *[l1];
	for (int i = 0; i < l1; i++)
	{
		matrixDyn[i] = new T[l2];

	}

	for (int i = 0; i < l1; i++) {
		for (int j = 0; j < l2; j++)
		{
			matrixDyn[i][j] = 0;
		}
	}
}

template <typename T>
Matrix<T>::Matrix(T **matrixDyn1, int l3, int l4)
{
	l3 = l1;
	ll1 = l1;
	l4 = l2;
	ll2 = l2;
	A = new int *[l1];
	for (int i = 0; i <l1; i++)
	{
		matrixDyn[i] = new int[l2];

	}

	for (int i = 0; i<l1; i++)
	{
		for (int j = 0; j < l2; j++) {
			matrixDyn[i][j] = matrixDyn1[i][j];
		}
	}
}

template <typename T>
Matrix<T>::~Matrix()
{
}

template <class T> class Vector : public Matrix<T>
{
private:
	int l1 = 1;
	int l2;
	

public:
	T ** vectDyn;
	void vect_vect(Vector<T> vect1, Vector<T> Vect2, Vector<T> VectRes);
	Vector(T **Vector1, int g1);
	Vector(int r2);
	Vector();
	~Vector();
};

template <typename T>
Vector<T>::~Vector()
{
}
template <typename T>
Vector<T>::Vector()
{
	cout << "Enter vector length ";
	cin >> l2;
	vectDyn = new T *[1];
	for (int i = 0; i <1; i++)
	{
		vectDyn[i] = new T[l2];

	}

	for (int i = 0; i<1; i++)
	{
		for (int j = 0; j < l2; j++) {
			vectDyn[i][j] = 0;
		}
	}
}

template <typename T>
Vector<T>::Vector(T **Vector1, int g1)
{
	l2 = g1;
	vectDyn = new T *[l1];
	for (int i = 0; i <1; i++)
	{
		vectDyn[i] = new T[l2];

	}

	for (int i = 0; i<1; i++)
	{
		for (int j = 0; j < g1; j++) {
			vectDyn[i][j] = Vector1[i][j];
		}
	}
}

template <typename T>
Vector<T>::Vector( int r2)
{
	l1 = 1;
	l2 = r2;
	vectDyn = new T *[1];
	for (int i = 0; i < l1; i++)
	{
		vectDyn[i] = new T [l2];

	}

	for (int i = 0; i < l1; i++) {
		for (int j = 0; j < l2; j++)
		{
			vectDyn[i][j] = 0;
		}
	}
}

template <typename T>
void Vector<T>::vect_vect(Vector<T> vect1, Vector<T> Vect2, Vector<T> VectRes)
{

	int g1 = vect1.l2;
	int g2 = Vect2.l2;
	if (g1 != 3 || g2 != 3) {  }
	else
	{
		if (g1 == g2)
		{
			for (int i = 0; i < g1; i++)
			{
				VectRes.vectDyn[0][i] = vect1.vectDyn[0][(i + 1) % 3] * Vect2.vectDyn[0][(i + 2) % 3] - vect1.vectDyn[0][(i + 2) % 3] * Vect2.vectDyn[0][(i + 2) % 3];

			}
		}
	
	}
	
}

template <typename T>
void Matrix<T>::matrix_umnozh(Matrix <T> matrix1, Matrix <T> matrix2, Matrix<T> matrix3)
	{
	int l3 = matrix1.l1;
	int l4 = matrix1.l2;
	int l5 = matrix2.l1;
	int l6 = matrix2.l2;

		int l1 = l3;
		int l2 = l4;
		for (int i = 0; i < l1; i++)
		{
			for (int j = 0; j < l1; j++)
			{
				matrix3.matrixDyn[i][j] = 0;
				for (int k = 0; k < l4; k++)
					matrix3.matrixDyn[i][j] = matrix3.matrixDyn[i][j] + matrix1.matrixDyn[i][k] * matrix2.matrixDyn[k][j];
			}
		}

	}


template <typename T>
void Matrix<T>::matrix_slozh(Matrix <T> matrix1, Matrix <T> matrix2, Matrix<T> matrix3)
{

	int l3 = matrix1.l1;
	int l5 = matrix2.l1;
	int l4 = matrix1.l2;
	int l6 = matrix2.l2;

		int l1 = l3;
		int l2 = l4;
		for (int i = 0; i < l1; i++)
		{
			for (int j = 0; j < l2; j++)
			{
				matrix3.matrixDyn[i][j] = 0;

				matrix3.matrixDyn[i][j] = matrix1.matrixDyn[i][j] + matrix2.matrixDyn[i][j];
			}
		}
}

template <typename T>
void Matrix<T>::matrix_vych(Matrix<T>  matrix1, Matrix <T> matrix2, Matrix<T> matrix3)
{
	
	int l3 = matrix1.l1;
	int l5 = matrix2.l1;
	int l4 = matrix1.l2;
	int l6 = matrix2.l2;

		int l1 = l3;
		int l2 = l4;
		for (int i = 0; i < l1; i++)
		{
			for (int j = 0; j < l2; j++)
			{
				matrix3.matrixDyn[i][j] = 0;

				matrix3.matrixDyn[i][j] = matrix1.matrixDyn[i][j] - matrix2.matrixDyn[i][j];
			}
		}
}


template <typename T>
void Matrix<T>::vyvod_matr( Matrix <T> matrix3)
{
	cout << endl;
	int k1 = matrix3.l1;
	int k2 = matrix3.l2;
	for (int i = 0; i < k1; i++) {
		for (int j = 0; j < k2; j++)
		{
			cout << matrix3.matrixDyn[i][j] << " \t";
		}
		cout << std::endl;
	}
	cout << std::endl;
}

template <typename T>
Matrix <T> operator + (Matrix <T> lhs,
	Matrix <T> rhs)
{
	if ((lhs.ll1==rhs.ll1)&&(lhs.ll2==rhs.ll2))
	{
	Matrix <T> result(lhs.ll1, rhs.ll2);
	result.matrix_slozh(lhs, rhs, result);
	return result;
	}
	else {
		Matrix <T> result(1, 1);
		return result;
	}
	
}

template <typename T>
Matrix <T> operator - (Matrix <T> lhs,
	Matrix <T> rhs)
{
	if ((lhs.ll1 == rhs.ll1) && (lhs.ll2 == rhs.ll2))
	{
		Matrix <T> result(lhs.ll1, lhs.ll2);
		result.matrix_vych(lhs, rhs, result);
		return result;
	}
	else {
		Matrix <T> result(1, 1);
		return result;
	}
}

template <typename T>
Matrix <T> operator * (Matrix <T> lhs,
	Matrix <T> rhs)
{
	if (lhs.ll1 == rhs.ll2)
	{
		Matrix <T> result(lhs.ll1, rhs.ll2);
		result.matrix_umnozh(lhs, rhs, result);
		return result;
	}
	else {
		Matrix <T> result(1, 1);
		return result;
	}
}

template <typename T>
ostream &operator <<(ostream &os, Matrix<T>& rhs)
{
	rhs.vyvod_matr(rhs);
	return os;
}

