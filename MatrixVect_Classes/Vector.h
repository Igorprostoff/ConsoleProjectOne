#pragma once

#include "Matrix.h"

class Vector : public Matrix
{
private:

	int l1= 1;
	int l2;
	int ** vectDyn;
	
public:
	void vect_vect(Vector vect1, Vector Vect2, Vector VectRes);

	~Vector();
};

