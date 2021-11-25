#include <iostream>
#include "p1.h"

using namespace std;

int **matrix(int size)
{
    int **temp = new int *[size];
    for (int i = 0; i < size; i++)
    {
        temp[0] = new int[size];
    }
    for (int i = 0; i < size; i++)
    {
        temp[i][0] = 0;
    }
    return temp;
}

void solucion_1()
{
    cout << 1 << endl;
    int **a = matrix(3);
    cout << 1 << endl;
    cout << a[0][0] << endl;
    delete[] a;
}