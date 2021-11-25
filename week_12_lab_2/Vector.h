//
// Created by estan on 11/5/2021.
//

#ifndef LAB029_VECTOR_H
#define LAB029_VECTOR_H
#include <iostream>
using namespace std;

template <class T>
class Vector
{
private:
    T *items;
    int longitud;
    int capacidad;
    const int buffer = 5;
    void redimensionar()
    {
        capacidad += buffer;
        T *nuevosElementos = new T[capacidad]();
        for (auto i = 0; i < longitud; i++)
            nuevosElementos[i] = items[i];
        delete[] items;
        items = nuevosElementos;
    }

    void inicializar()
    {
        capacidad = buffer;
        longitud = 0;
        items = new T[capacidad]();
    }

public:
    // Metodos constructores
    Vector()
    {
        inicializar();
    }

    Vector(const int longitudInicial, T valor)
    {
        inicializar();
        for (auto i = 0; i < longitudInicial; i++)
            adicionar(valor);
    }

    Vector(Vector<T> *vector)
    {
        inicializar();
        for (auto i = 0; i < vector->getLongitud(); i++)
            adicionar(vector->getItem(i));
    }

    // Metodos de acceso
    int getLongitud() const
    {
        return longitud;
    }

    // Metodos de comportamiento
    void adicionar(T dato)
    {
        if (longitud == capacidad)
            redimensionar();
        items[longitud] = dato;
        longitud++;
    }

    void insertar(T dato, int posicion)
    {
        if (posicion >= 0 && posicion < longitud)
        {
            adicionar(items[longitud - 1]);
            for (auto i = longitud - 2; i > posicion; i--)
                items[i] = items[i - 1];
            items[posicion] = dato;
        }
    }

    T getItem(int posicion)
    {
        if (posicion > 0 && posicion < longitud)
            return items[posicion];
        else
            throw new exception();
    }

    void setItem(T dato, int posicion)
    {
        if (posicion >= 0 && posicion < longitud)
            items[posicion] = dato;
    }

    void mostrar()
    {
        for (auto i = 0; i < longitud; i++)
            cout << "Items[" << i << "] = " << items[i] << endl;
    }

    // Métodos destructores
    virtual ~Vector()
    {
        delete[] items;
        items = nullptr;
    }
};

#endif //LAB029_VECTOR_H
