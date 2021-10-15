#include <iostream>
#include <string>
#include "p2.h"

using namespace std;

bool esMayusculas(string in)
{
    if (in.size() == 0)
    {
        return true;
    }
    if (in[0] == (char)toupper(in[0]))
    {
        return true & esMayusculas(in.substr(1));
    }
    return false;
}

void solucion_2()
{
    string in;
    std::cout << "Texto: ";
    std::cin >> in;
    std::cout << "El texto "
              << (esMayusculas(in)
                      ? "si"
                      : "no")
              << " esta en mayuscula" << std::endl;
}