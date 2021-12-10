#ifndef LAB036_RECTANGULO_H
#define LAB036_RECTANGULO_H

#include "Figura.h"

class Rectangulo : public Figura
{
private:
    float base;
    float altura;

public:
    Rectangulo(int x, int y, float base, float altura);
    float calcularArea() override;
    void mostrar();
    ~Rectangulo();
};

#endif