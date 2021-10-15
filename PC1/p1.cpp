#include <iostream>
#include "p1.h"

using namespace std;

void solucion_1()
{

    int counter = 1;
    int promedio[5] = {0, 0, 0, 0, 0};
    char input;
    std::cout << "Ingreso de datos" << endl;
    do
    {
        std::cout << "Evaluacion Cualitativa ." << counter << ":";
        std::cin >> input;
        input = toupper(input);
        switch (input)
        {
        case 'A':
            promedio[counter - 1] = 5;
            counter++;
            break;
        case 'B':
            promedio[counter - 1] = 4;
            counter++;
            break;
        case 'C':
            promedio[counter - 1] = 3;
            counter++;
            break;
        case 'D':
            promedio[counter - 1] = 2;
            counter++;
            break;
        default:
            break;
        }
    } while (counter < 6);

    std::cout << ' ' << std::endl;

    int promedio_num = 0;
    int min = 5;
    for (int x = 0; x < 5; x++)
    {
        if (promedio[x] < min)
            min = promedio[x];
        promedio_num += promedio[x];
    }
    promedio_num -= min;
    std::cout << "Resultado\n"
              << "Promedio : " << promedio_num << '\n'
              << "Condicion: "
              << ((promedio_num >= 13)
                      ? "Aprobado"
                      : "Desaprobado")
              << '\n'
              << "Se elimino: "
              << (char)('A' + (5 - min)) << endl;
}