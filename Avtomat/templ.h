#pragma once

#include "stdafx.h"
#include <iostream>
#include <initializer_list>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

template <class T> class Matriz
{
public:
	int ** A;
	int ll1;
	int ll2;
	~Matriz();
	Matriz();
	Matriz(T l1, T l2);
	Matriz(T **A, T l3, T l4);
	void umnozhenie(Matriz <T> obj1, Matriz <T> obj2, Matriz<T>obj3);
	void slozhenie(Matriz <T> obj1, Matriz <T> obj2, Matriz<T> obj3);
	void vychitanie(Matriz <T> obj1, Matriz <T> obj2, Matriz <T> obj3);
	void vyvod(Matriz <T> obj3);
template <typename T>friend ostream &operator<< (ostream &os, const Matriz<T> &rhs);
private:
	int l1;
	int l2;

};

template <typename T>
Matriz<T>::Matriz()
{
	cout << "enter matrix length ";
	cin >> l1;
	ll1 = l1;
	cout << "enter matrix height ";
	cin >> l2;
	ll2 = l2;
	A = new int *[l1];
	for (int i = 0; i < l1; i++)
	{
		A[i] = new int[l2];

	}

	for (int i = 0; i < l1; i++) {
		for (int j = 0; j < l2; j++)
		{
			A[i][j] = 2;
		}
	}
}

template <typename T>
Matriz<T>::Matriz(T lll1, T lll2)
{
	l1 = lll1;
	ll1 = l1;
	l2 = lll2;
	ll2 = l2;
	A = new int *[l1];
	for (int i = 0; i < l1; i++)
	{
		A[i] = new int[l2];

	}

	for (int i = 0; i < l1; i++) {
		for (int j = 0; j < l2; j++)
		{
			A[i][j] = 0;
		}
	}
}
template <typename T>
Matriz<T>::Matriz(T **A1, T l3, T l4)
{
	l3 = l1;
	ll1 = l1;
	l4 = l2;
	ll2 = l2;
	A = new int *[l1];
	for (int i = 0; i <l1; i++)
	{
		A[i] = new int[l2];

	}

	for (int i = 0; i<l1; i++)
	{
		for (int j = 0; j < l2; j++) {
			A[i][j] = A1[i][j];
		}
	}
}

template <typename T>
Matriz<T>::~Matriz()
{
}

template <typename T>
void Matriz<T>::umnozhenie(Matriz <T> obj1, Matriz <T> obj2, Matriz<T> obj3)
	{
	int l3 = obj1.l1;
	int l4 = obj1.l2;
	int l5 = obj2.l1;
	int l6 = obj2.l2;

		int l1 = l3;
		int l2 = l4;
		for (int i = 0; i < l1; i++)
		{
			for (int j = 0; j < l1; j++)
			{
				obj3.A[i][j] = 0;
				for (int k = 0; k < l4; k++)
					obj3.A[i][j] = obj3.A[i][j] + obj1.A[i][k] * obj2.A[k][j];
			}
		}

	}


template <typename T>
void Matriz<T>::slozhenie(Matriz <T> obj1, Matriz <T> obj2, Matriz<T> obj3)
{

	int l3 = obj1.l1;
	int l5 = obj2.l1;
	int l4 = obj1.l2;
	int l6 = obj2.l2;

		int l1 = l3;
		int l2 = l4;
		for (int i = 0; i < l1; i++)
		{
			for (int j = 0; j < l2; j++)
			{
				obj3.A[i][j] = 0;

				obj3.A[i][j] = obj1.A[i][j] + obj2.A[i][j];
			}
		}
}

template <typename T>
void Matriz<T>::vychitanie(Matriz<T>  obj1, Matriz <T> obj2, Matriz<T> obj3)
{
	
	int l3 = obj1.l1;
	int l5 = obj2.l1;
	int l4 = obj1.l2;
	int l6 = obj2.l2;

		int l1 = l3;
		int l2 = l4;
		for (int i = 0; i < l1; i++)
		{
			for (int j = 0; j < l2; j++)
			{
				obj3.A[i][j] = 0;

				obj3.A[i][j] = obj1.A[i][j] - obj2.A[i][j];
			}
		}
}

template <typename T>
void Matriz<T>::vyvod(const Matriz <T> obj3)
{
	cout << endl;
	int k1 = obj3.l1;
	int k2 = obj3.l2;
	for (int i = 0; i < k1; i++) {
		for (int j = 0; j < k2; j++)
		{
			cout << obj3.A[i][j] << " \t";
		}
		cout << std::endl;
	}
	cout << std::endl;
}

template <typename T>
Matriz <T> operator + (Matriz <T> lhs,
	Matriz <T> rhs)
{
	if ((lhs.ll1==rhs.ll1)&&(lhs.ll2==rhs.ll2))
	{
	Matriz <T> result(lhs.ll1, rhs.ll2);
	result.slozhenie(lhs, rhs, result);
	return result;
	}
	else {
		Matriz <T> result(1, 1);
		return result;
	}
	
}

template <typename T>
Matriz <T> operator - (Matriz <T> lhs,
	Matriz <T> rhs)
{
	if ((lhs.ll1 == rhs.ll1) && (lhs.ll2 == rhs.ll2))
	{
		Matriz <T> result(lhs.ll1, lhs.ll2);
		result.vychitanie(lhs, rhs, result);
		return result;
	}
	else {
		Matriz <T> result(1, 1);
		return result;
	}
}

template <typename T>
Matriz <T> operator * (Matriz <T> lhs,
	Matriz <T> rhs)
{
	if (lhs.ll1 == rhs.ll2)
	{
		Matriz <T> result(lhs.ll1, rhs.ll2);
		result.umnozhenie(lhs, rhs, result);
		return result;
	}
	else {
		Matriz <T> result(1, 1);
		return result;
	}
}

template <typename T>
ostream &operator <<(ostream &os, Matriz<T>& rhs)
{
	rhs.vyvod(rhs);
	return os;
}
