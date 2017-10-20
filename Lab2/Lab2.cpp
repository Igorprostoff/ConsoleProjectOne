// Lab2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "cmath"
#include "iostream"
#include "bitset"
/*Lab2- ������� � ���������*/

int main()
{
	// ����������, �������� ����� ������ ���������� � ������, ���������� ����������, ��� ����������� ����� �������� "*"
	//ptr=pointer
	int a = 231;
	double ch = 10.005;
	int * ptr_int = &a;
	double * ptr_ch=&ch;
	
	// ��� ��������� ������ ����� � ��� �� ����������� (�������)
	std::cout << "size of ptr_int " << sizeof(ptr_int) << std::endl;
	std::cout << "size of ptr_ch " << sizeof(ptr_ch) << std::endl;
	std::cout << "size of double * "<< sizeof(double *) << std::endl;
	std::cout << "size of  long long * "<< sizeof(long long *) << std::endl;
	// ���������� ����������
	std::cout << "size of int " << std::hex << ptr_int << std::endl;
	std::cout << "size of char " << std::hex << ptr_ch << std::endl;
	// � ���������� ����� ��������, ��� ����� �� �� ��� �������� ��� ������ (������, ������ � ��)
	// ��������� �� ���� ������ ����� �������� 4/8 ����, ��� � �������� �������� �������������

	//�������� ������������� ����������: ����� �������� ��������, ���������� �� ������� ���������, 
	//����� ��� ��� ��������� �������� "*"
	std::cout << "*ptr_int= " << std::dec<<  *ptr_int << std::endl;
	std::cout << "*ptr_ch= " << std::dec << *ptr_ch << std::endl;
	
	//������ ���� �� ���������� ���������� ������
	// �������� �������� ������ 
	// 1)������� � �������
	// 2) ��������� ����� �� 3D � 2D ���������
	// 3)���� ������ � ���� ������
	// 4) ������- ���������� ������ ��������
	// 5) �����������- ��������� ������, ��������������� �������� ������
	int arr[5] = {1, 50, 11, 12, 1000}; //���������� ������ �� 10 ����� �������� �����
	//� ����.������ ������ �������� ���������, ��� �������� ������� �� ���������
	std::cout <<
		'\t'<<
		arr[0]<<
		'\t'<<
		arr[1]<<
		'\t' <<
		arr[2]<<
		'\t'<<
		arr[3]<<
		'\t'<<
		arr[4]<<
		'\t'
		<< std::endl;
	int arr1[3][3] = { {1, 2, 3},
	                   {4, 5, 6}, 
	                   {7, 8, 9} };
	std::cout <<
		'\n' <<
		arr1[0][0] << " "<< arr1[0][1] <<" " << arr1[0][2]<<
		'\n' <<
		arr1[1][0] << " " << arr1[1][1] <<" " <<  arr1[1][2]<<
		'\n' <<
		arr1[2][0] << " " << arr1[2][1] <<" " << arr1[2][2]<<
		'\t' <<
		 std::endl;
	// ���� �� ���������������� ���������� (������� ������) - ��� �������� �������������� �����
	// ��� ������������� ����� ������� ����, ������������� ���� ���� � �������� �������
	getchar(); //1. �� ����� ���������� ����� �������� (Debug point)
	//2. � ���������� ��������� ��� ������� �� ����������, ���������� �������� ����������, ����� ��������� �� ���������� � ��� �� �������� :3
    return 0;
}

