#pragma once
#include <iostream>
using namespace std;
class WeaponClass1
{

public:

	WeaponClass1() {
		//� ������������ ���������� ������������� ������� ������ � ������ ��������� ��������� ��������
			 //������������ ���������� � ������������ ���� �� �����
		weight = 3.5;
		cartridges = capacity;
		cout << "WeaponClass1" << endl;
	}
private:
	int cartridges; //����� ���������� �������
	int capacity = 30; //������� ��������
public:
	double range = 1500; //���������
	double velocity; //��������� ��������
	double weight; // ���
	bool optics;
	bool loaded;

	void load()//�����������
	{
		cartridges = capacity;
	}

	void play_animation();

	void shot();

	~WeaponClass1();
};

