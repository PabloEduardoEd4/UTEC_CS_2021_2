//
// Created by estan on 12/3/2021.
//

#include "Circulo.h"
#include <iostream>
using namespace std;

Circulo::Circulo(int x, int y, float radio) : Figura(x, y), radio(radio) {}

float Circulo::getRadio() const {
    return radio;
}

void Circulo::setRadio(float radio) {
    Circulo::radio = radio;
}

float Circulo::calcularArea() {
    return 3.14*radio*radio;
}

void Circulo::mostrar() {
    Figura::mostrar();
    cout << "Radio: "<<radio<<endl;
}

Circulo::~Circulo() {
    radio = 0;
}
