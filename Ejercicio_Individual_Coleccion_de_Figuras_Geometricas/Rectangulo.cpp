
#include <iostream>
#include "Rectangulo.h"

Rectangulo::Rectangulo(int x, int y, float base, float altura) : Figura(x, y), base(base), altura(altura) {}

float Rectangulo::calcularArea() { return base * altura; }

void Rectangulo::mostrar()
{
    Figura::mostrar();
    std::cout << "Base: " << base << '\n'
              << "Altura: " << altura << std::endl;
}

Rectangulo::~Rectangulo() { base = 0, altura = 0; }