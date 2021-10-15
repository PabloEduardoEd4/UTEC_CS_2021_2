#include "funciones.h"
#include <iostream>

int cubos(int pisos)
{
    /*Recursive Way
    if (!pisos)
    {
        return 0;
    }
    if (pisos == 1)
    {
        return 1;
    }
    return pisos + cubos(pisos - 1);
    */

    /*Iterative Way
    int sum = 0;
    for (int x; x < pisos; x++)
    {
        sum += (pisos - x);
    }
    */
    //return pisos * (pisos + 1) / 2;

    return (pisos * (pisos + 1)) >> 1;
}

int construir(int n)
{
    int c, counter = 0;
    do
    {
        counter++;
        c = cubos(counter);
    } while (n > c);
    return counter;
}

long long fast_factorial(int value)
{
    const int half_value = value >> 1;
    const int odd_even = (half_value - 1) * !(value % 2) + 1;
    long long factorial = value * odd_even;
    for (int x = 1; 2 * x < value; x++)
    {
        factorial = factorial * x * (value - x);
    }
    return factorial;
}