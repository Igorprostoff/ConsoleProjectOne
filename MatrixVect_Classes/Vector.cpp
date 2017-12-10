#include "stdafx.h"
#include "Vector.h"
#include <iostream>
using namespace std;









void Vector::vect_vect(Vector vect1, Vector Vect2, Vector VectRes)
{
	
	int g1 = vect1.l2;
	int g2 = Vect2.l2;
	if (g1 != 3 || g2 != 3) { cout << "Uncountable pair of vectors" << endl; }
	else 
	{
		if (g1 == g2)
		{
			for (int i = 0; i < g1; i++)
			{
				VectRes.vectDyn[0][i] =vect1.vectDyn[0][(i + 1) % 3] * Vect2.vectDyn[0][(i + 2) % 3] - vect1.vectDyn[0][(i + 2) % 3] * Vect2.vectDyn[0][(i + 2) % 3];

			}
		}
		else { cout <<"Uncountable pair of vectors" << endl; }
	}
//	vyvod_mat(VectRes);
}

		


//Vector::Vector()
//{cout<<"INHERITED CLASS CONSTRUCTOR STARTED"<<endl;
//	
//	cout << "enter vector height ";
//	
//	cin >> l2;
//	
//	vectDyn = new int *[l1];
//
//	for (int i = 0; i < l1; i++)
//	{
//		vectDyn[i] = new int[l2];
//
//	}
//
//	for (int i = 0; i < l1; i++) {
//		for (int j = 0; j < l2; j++)
//		{
//			vectDyn[i][j] = 2;
//		}
//	}
//}


//Vector::Vector(int **Vector1, int g1)
//{
//	
//	vectDyn = new int *[l1];
//	for (int i = 0; i <1; i++)
//	{
//		vectDyn[i] = new int[g1];
//
//	}
//
//	for (int i = 0; i<1; i++)
//	{
//		for (int j = 0; j < g1; j++) {
//			vectDyn[i][j] = Vector1[i][j];
//		}
//	}
//}

Vector::~Vector()
{
}
