#include "Cubo.h"

Cubo::Cubo(int x, int y, float lado) : Cuadrado(x, y, lado) {}

float Cubo::calcularArea() { return 6 * lado * lado; }

float Cubo::calcularVolumen() { return lado * lado * lado; }