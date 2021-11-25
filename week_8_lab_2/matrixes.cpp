#include <iostream>
#include <time.h>

int ingresarDimensionesMatrix()
{
    int dimensions = 0;
    do
    {
        std::cout << "Matrix of Dimensions: " << std::endl;
    } while (dimensions < 0);
    return dimensions;
}
int **createMatrix(int dimension)
{
    int **pMatrix = new int *[dimension]();
    for (int i = 0; i < dimension; ++i)
    {
        pMatrix[i] = new int[dimension]();
    }
    srand(time(0));
    for (int i = 0; i < dimension; ++i)
    {
        for (int j = 0; j < dimension; ++j)
            pMatrix[i][j] = rand() % 100;
        std::cout << pMatrix[i][0] << std::endl;
    }
    return pMatrix;
}
void showMatrix(int **pMatrix, int dimension)
{
    for (int i = 0; i < dimension; ++i)
    {
        for (int j = 0; j < dimension; ++j)
            std::cout << pMatrix[i][j] << ' ';
        std::cout << std::endl;
    }
    std::cout << "--------------------------" << std::endl;
}
void rotateMatrixDown(int **pMatrix, int dimension)
{
    int *lastLine = pMatrix[dimension - 1];
    for (int line = dimension - 1; line > 0; line--)
        pMatrix[line] = pMatrix[line - 1];
    pMatrix[0] = lastLine;
}
void rotateMatrixRight(int **pMatrix, int dimension)
{
    int temp;
    for (int i = 0; i < (int)(dimension / 2); ++i)
    {
        for (int j = 0; j < dimension; ++j)
        {
            temp = pMatrix[j][i];
            pMatrix[j][i] = pMatrix[i][j];
            pMatrix[i][j] = temp;
        }
    }
}

void freeMatrix(int **&pMatrix, int dimension)
{
    for (int i = 0; i < dimension; ++i)
        delete[] pMatrix[i];
    delete[] pMatrix;
}
