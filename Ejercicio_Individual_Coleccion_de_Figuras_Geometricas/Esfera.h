#ifndef LAB036_ESFERA_H
#define LAB036_ESFERA_H

#include "Circulo.h"

class Esfera : public Circulo
{
public:
    Esfera(int x, int y, float radio);
    float calcularArea() override;
    float calcularVolumen();
};

#endif