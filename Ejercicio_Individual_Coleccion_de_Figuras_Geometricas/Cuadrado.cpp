//
// Created by estan on 12/3/2021.
//

#include "Cuadrado.h"
#include <iostream>
using namespace std;

Cuadrado::Cuadrado(int x, int y, float lado) : Figura(x, y), lado(lado) {}

float Cuadrado::getLado() const {
    return lado;
}

void Cuadrado::setLado(float lado) {
    Cuadrado::lado = lado;
}

float Cuadrado::calcularArea() {
    return lado*lado;
}

void Cuadrado::mostrar() {
    Figura::mostrar();
    cout << "Lado: "<<lado<<endl;
}

Cuadrado::~Cuadrado() {
    lado=0;
}
