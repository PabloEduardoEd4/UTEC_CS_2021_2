#ifndef matrixes
#define matrixes

int ingresarDimensionesMatrix();
int **createMatrix(int dimension);
void showMatrix(int **pMatrix, int dimension);
void rotateMatrixDown(int **pMatrix, int dimension);
void rotateMatrixRight(int **pMatrix, int dimension);
void freeMatrix(int **&pMatrix, int dimension);

#endif