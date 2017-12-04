#pragma once

#include "Matrix.h"

class Vector : public Matrix
{
private:

	int l1= 1;
	int l2;
	int ** vectDyn;
	
public:

	//Vector(int **Vector1, int g1);

	//Vector();



	void vect_vect(Vector vect1, Vector Vect2, Vector VectRes);

	~Vector();
};

