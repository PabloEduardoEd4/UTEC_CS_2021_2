#include <iostream>
#include "Figura.h"
#include "Cuadrado.h"
#include "Circulo.h"
#include <vector>

using namespace std;
int main() {
    // TODO: 1. Implementar la jerarquia faltante Rectangulo, Esfera, Cubo
    // TODO: 2. Sistema que registre muchas figuras geometricas (Menu) un listado general


    vector<Figura*>* figuras = new vector<Figura*>{
        new Cuadrado(0,0,10),
        new Circulo(10,10,20),
        new Circulo(50,50,5),
        new Cuadrado(100,100,50)
    };

    for(const auto figurita : *figuras){
        figurita->mostrar();
        cout << "Area: "<< figurita->calcularArea()<<endl<<endl;
        delete figurita;
    };
    delete figuras;
    return 0;
}
