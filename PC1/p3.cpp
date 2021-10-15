#include <iostream>
#include "p3.h"

using namespace std;

const float PI = 3.14;
const int exca = 100;
const int recub = 150;

//No es nescario pero ahora memoria
float volumen(int &radio, int &profundidad)
{
    return PI * radio * radio * profundidad;
}

//No es nescario pero ahora memoria
float area(int &radio, int &profundidad)
{
    return 2 * PI * radio * profundidad + PI * radio * radio;
}

void solucion3()
{
    int profundidad = 0;
    int radio = 0;
    std::cout << "Construccion de Piscina Circular"
              << std::endl;
    do
    {
        std::cout << "Profundidad:";
        std::cin >> profundidad;
    } while (profundidad <= 0);
    do
    {
        std::cout << "Radio:";
        std::cin >> radio;
    } while (radio <= 0);
    std::cout << ' ' << std::endl;
    int cost_ex = exca * volumen(radio, profundidad);
    int cost_re = recub * area(radio, profundidad);
    std::cout << "Costos (s/.)\n"
              << "Excavacion:" << cost_ex << '\n'
              << "Recubrimiento:" << cost_re << '\n'
              << "Total:" << cost_ex + cost_re << std::endl;
}