#pragma once
class Vector
{
private:

	int g2;
	int ** vectDyn = new int *[1];
	
public:
	Vector();

	Vector(int **Vector1, int g1);

	void vyvod_mat(int ** matrixDyn, int l1, int l2);

	void vyvod_vect(int** vectorDyn, int g1);

	/*void matrix_slozh(int**& matrixDyn, int** matrix1Dyn, int l3, int l4, int** matrix2Dyn, int l5, int l6);

	void vect_slozh(int**& vectSumDyn, int **vector1, int g1, int ** vector2, int g2);

	void matrix_umnozh(int**& matrixDyn, int** matrix1Dyn, int l3, int l4, int** matrix2Dyn, int l5, int l6);

	void matrix_x_vect(int**& matrixDyn, int** matrix1Dyn, int l3, int l4, int **vector1, int g1);*/

	void vect_skal(int &otvet, int **vector1, int g1, int ** vector2, int g2);

	void vect_vect(int **& matrixVectDyn, int **vector1, int g1, int ** vector2, int g2, int**& vectSumDyn);

	~Vector();
};

