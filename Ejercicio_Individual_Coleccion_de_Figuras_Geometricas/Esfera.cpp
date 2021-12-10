#include "Esfera.h"

const float four_thirds = 4 / 3;
const float pi = 3.14159265359;

Esfera::Esfera(int x, int y, float radio) : Circulo(x, y, radio) {}

float Esfera::calcularArea() { return 4 * pi * radio * radio; }

float Esfera::calcularVolumen() { return four_thirds * pi * radio * radio * radio; }

Esfera::~Esfera() { x = 0, y = 0; }