#include <iostream>

#include "matrixes.h"

int main(int argc, char *argv[])
{
	std::cout << "Hello world!" << std::endl;
	int dimension = 5;
	int **pMatrix = createMatrix(dimension);
	showMatrix(pMatrix, dimension);
	rotateMatrixDown(pMatrix, dimension);
	showMatrix(pMatrix, dimension);
	rotateMatrixRight(pMatrix, dimension);
	showMatrix(pMatrix, dimension);
	freeMatrix(pMatrix, dimension);
	return 0;
}