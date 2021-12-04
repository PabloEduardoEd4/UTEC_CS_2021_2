//
// Created by estan on 12/3/2021.
//

#include "Figura.h"
#include <iostream>
using namespace std;

Figura::Figura(int x, int y) : x(x), y(y) {}

int Figura::getX() const {
    return x;
}

void Figura::setX(int x) {
    Figura::x = x;
}

int Figura::getY() const {
    return y;
}

void Figura::setY(int y) {
    Figura::y = y;
}

void Figura::mostrar() {
    cout << "Coordenada X: "<<x<<endl;
    cout << "Coordenada Y: "<<y<<endl;
}

Figura::~Figura() {
    x=0;
    y=0;
}
