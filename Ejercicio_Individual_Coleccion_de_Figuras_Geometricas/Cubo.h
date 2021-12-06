#ifndef LAB036_CUBO_H
#define LAB036_CUBO_H

#include "Cuadrado.h"

class Cubo : public Cuadrado
{
public:
    Cubo(int x, int y, float lado);
    float calcularArea() override;
    float calcularVolumen();
};

#endif