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

}

		



Vector::~Vector()
{
}
