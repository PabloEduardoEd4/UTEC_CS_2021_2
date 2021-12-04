//
// Created by estan on 12/3/2021.
//

#ifndef LAB036_CIRCULO_H
#define LAB036_CIRCULO_H
#include "Figura.h"
// Clase Concreta que debe redefinir de todas manera el metodo: calcularArea()
class Circulo: public Figura{
protected:
    float radio;
public:
    // constructor
    Circulo(int x, int y, float radio);
    // acceso
    float getRadio() const;
    void setRadio(float radio);
    // comportamiento
    float calcularArea() override;

    void mostrar() override;

    ~Circulo() override;


};


#endif //LAB036_CIRCULO_H
