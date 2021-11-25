//
// Created by Jose Fiestas on 19/11/21.
//

#ifndef INC_2021_II_TEO3_SEM12_U6_S2_FAMILIA_H
#define INC_2021_II_TEO3_SEM12_U6_S2_FAMILIA_H
#include <iostream>
#include <vector>
using namespace std;

class Familia
{
    string apellido;

public:
    Familia(){};
    Familia(string n) { this->apellido = n; }

    void set_apellido(string l) { apellido = l; }
    string get_apellido() { return this->apellido; }

    // usamos metodos virtuales para elegir el metodo correcto
    // al llamar a una clase base o derivada

    virtual ~Familia() { cout << "Destruye Familia" << endl; }
};
#endif //INC_2021_II_TEO3_SEM12_U6_S2_FAMILIA_H
