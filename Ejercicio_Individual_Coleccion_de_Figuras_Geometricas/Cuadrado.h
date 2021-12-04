//
// Created by estan on 12/3/2021.
//

#ifndef LAB036_CUADRADO_H
#define LAB036_CUADRADO_H
#include "Figura.h"

class Cuadrado: public Figura{
protected:
    float lado;
public:
    Cuadrado(int x, int y, float lado);

    float getLado() const;
    void setLado(float lado);

    float calcularArea() override;

    void mostrar() override;

    ~Cuadrado() override;

};


#endif //LAB036_CUADRADO_H
