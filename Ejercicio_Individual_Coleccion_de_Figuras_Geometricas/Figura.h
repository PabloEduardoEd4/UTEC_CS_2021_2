//
// Created by estan on 12/3/2021.
//

#ifndef LAB036_FIGURA_H
#define LAB036_FIGURA_H

// Clase Abstracta
class Figura {
protected:
    int x;
    int y;
public:
    // constructor
    Figura(int x, int y);
    // acceso
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    // comportamiento
    // OJO PESTAÑA CEJA Y OREJA Metodo Abstracto:
    // Metodo que se define pero que no se implementa
    virtual float calcularArea() = 0;
    virtual void mostrar();
    // destructor
    virtual ~Figura();
};


#endif //LAB036_FIGURA_H
