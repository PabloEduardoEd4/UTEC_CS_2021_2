#include <iostream>
#include "Vector.h"
using namespace std;

int main()
{
    Vector<int> v1(5, -100);
    v1.mostrar();

    Vector<int> *vectorInt = new Vector<int>();
    for (int i = 0; i < 10; ++i)
        vectorInt->adicionar(i * 100);

    Vector<string> *vectorString = new Vector<string>(3, "Hello!");
    Vector<float> *vectorFloat = new Vector<float>();
    vectorFloat->adicionar(10.5);
    vectorFloat->adicionar(12.5);

    vectorInt->mostrar();
    vectorFloat->mostrar();
    vectorString->mostrar();

    delete vectorFloat;
    delete vectorString;
    delete vectorInt;

    return 0;
}
