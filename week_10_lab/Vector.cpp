//
// Created by estan on 11/4/2021.
//

#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector()
{
    inicializar();
}

Vector::Vector(const int longitudInicial, const int valor)
{
    inicializar();
    for (auto i = 0; i < longitudInicial; i++)
        adicionar(valor);
}

Vector::Vector(Vector *vector)
{
    inicializar();
    for (auto i = 0; i < vector->getLongitud(); i++)
        adicionar(vector->getItem(i));
}

void Vector::inicializar()
{
    capacidad = buffer;
    longitud = 0;
    items = new int[capacidad];
}

void Vector::redimensionar()
{
    capacidad += buffer;
    int *nuevosElementos = new int[capacidad];
    for (auto i = 0; i < longitud; i++)
        nuevosElementos[i] = items[i];
    delete[] items;
    items = nuevosElementos;
}

void Vector::adicionar(int dato)
{
    if (longitud == capacidad)
        redimensionar();
    items[longitud] = dato;
    longitud++;
}

int Vector::getItem(int posicion)
{
    if (posicion > 0 && posicion < longitud)
        return items[posicion];
    else
        throw new exception();
}

void Vector::setItem(int dato, int posicion)
{
    if (posicion >= 0 && posicion < longitud)
        items[posicion] = dato;
}

Vector::~Vector()
{
    delete[] items;
}

void Vector::mostrar()
{
    for (auto i = 0; i < longitud; i++)
        cout << "Items[" << i << "] = " << items[i] << endl;
}

int Vector::getLongitud() const
{
    return longitud;
}

void Vector::insertar(int dato, int posicion)
{
    if (posicion >= 0 && posicion < longitud)
    {
        adicionar(items[longitud - 1]);
        for (auto i = longitud - 2; i > posicion; i--)
            items[i] = items[i - 1];
        items[posicion] = dato;
    }
}
