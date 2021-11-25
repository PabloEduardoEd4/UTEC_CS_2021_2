#include <iostream>
#include "Vector.h"
using namespace  std;

int main() {
    //
    cout << "--------------- Prueba de Constructor Vacio ----------"<<endl;

    // Invocar al metodo constructor
    Vector* vec1 = new Vector();
    for (auto i=1; i<=10; i++)
        vec1->adicionar(i*10);
    vec1->mostrar();
    cout << "--------------- Prueba de Constructor con inicializacion----------"<<endl;
    // Prueba de Constructor con inicializacion
    // Invocar al metodo constructor
    Vector* vec2 = new Vector(5,1);
    vec2->mostrar();
    cout << "--------------- Prueba de Set Items----------"<<endl;
    vec2->setItem(-100,10);
    vec2->mostrar();
    cout << "Prueba 1 de Get Items --------"<<endl;
    for (auto i =0 ; i<vec2->getLongitud(); i++)
        cout << vec2->getItem(i) <<endl;
    //cout << "Prueba 2 de Get Items (Error) --------"<<endl;
    //cout << vec2->getItem(100) <<endl;

    // Prueba de constructor que copia datos de otro vector
    cout << "--------------- Prueba de constructor que copia datos de otro vector---------"<<endl;
    Vector* vec3 = new Vector(vec1);
    vec3->mostrar();
    cout << "--------------- Prueba de insertar 100 en la posicion 2---------"<<endl;
    // Prueba de insertar
    vec3->insertar(100,2);
    vec3->mostrar();

    // Liberar a los objetps invocando al destructor
    delete vec1;
    delete vec2;
    delete vec3;
    return 0;
}
