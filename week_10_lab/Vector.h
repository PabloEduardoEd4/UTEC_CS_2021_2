//
// Created by estan on 11/4/2021.
//

#ifndef LAB028_VECTOR_H
#define LAB028_VECTOR_H

class Vector {
private:
    int * items;
    int longitud;
public:
    int getLongitud() const;

private:
    int capacidad;
    const int buffer=5;
    void redimensionar();
    void inicializar();
public:
    // Metodos constructores
    Vector();
    Vector(const int longitudInicial, const int valor);
    Vector(Vector* vector);
    // Metodos de comportamiento
    void adicionar(int dato);
    void insertar(int dato, int posicion);
    int getItem(int posicion);
    void setItem(int dato, int posicion);
    void mostrar();
    // Métodos destructores
    virtual ~Vector();


};


#endif //LAB028_VECTOR_H
