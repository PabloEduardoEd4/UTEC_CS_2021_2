#include <iostream>
#include <vector>
#include "Figura.h"
#include "Cuadrado.h"
#include "Circulo.h"
#include "Cubo.h"
#include "Esfera.h"
#include "Rectangulo.h"
using namespace std;

void crearCuadrado(vector<Figura *> *figuras)
{
    int x, y;
    float lado;
    cout << "x-cord: ";
    cin >> x;
    cout << "y-cord: ";
    cin >> y;
    cout << "Lado: ";
    cin >> lado;
    figuras->push_back(new Cuadrado(x, y, lado));
}

void crearCirculo(vector<Figura *> *figuras)
{
    int x, y;
    float radio;
    cout << "x-cord: ";
    cin >> x;
    cout << "y-cord: ";
    cin >> y;
    cout << "Radio: ";
    cin >> radio;
    figuras->push_back(new Circulo(x, y, radio));
}

void crearRectangulo(vector<Figura *> *figuras)
{
    int x, y;
    float base, altura;
    cout << "x-cord: ";
    cin >> x;
    cout << "y-cord: ";
    cin >> y;
    cout << "Base: ";
    cin >> base;
    cout << "Altura: ";
    cin >> altura;
    figuras->push_back(new Rectangulo(x, y, base, altura));
}

void crearCubo(vector<Figura *> *figuras)
{
    int x, y;
    float lado;
    cout << "x-cord: ";
    cin >> x;
    cout << "y-cord: ";
    cin >> y;
    cout << "Lado: ";
    cin >> lado;
    figuras->push_back(new Cubo(x, y, lado));
}

void crearEsfera(vector<Figura *> *figuras)
{
    int x, y;
    float radio;
    cout << "x-cord: ";
    cin >> x;
    cout << "y-cord: ";
    cin >> y;
    cout << "Radio: ";
    cin >> radio;
    figuras->push_back(new Esfera(x, y, radio));
}

void cambio(int a, vector<Figura *> *figuras)
{
    switch (a)
    {
    case 1:
        crearCuadrado(figuras);
        break;
    case 2:
        crearCirculo(figuras);
        break;
    case 3:
        crearRectangulo(figuras);
        break;
    case 4:
        crearCubo(figuras);
        break;
    case 5:
        crearEsfera(figuras);
        break;
    default:
        break;
    }
}

void menu(vector<Figura *> *figuras)
{
    int a = 0;
    while (a != 6)
    {
        do
        {
            std::cout << "[1] Cuadrado\n"
                      << "[2] Circulo\n"
                      << "[3] Rectangulo\n"
                      << "[4] Cubo\n"
                      << "[5] Esfera\n"
                      << "[6] Exit" << std::endl;
            std::cin >> a;
        } while (a > 7 || a < 1);
        cambio(a, figuras);
    }
    return;
}

int main()
{
    // TODO: 1. Implementar la jerarquia faltante Rectangulo, Esfera, Cubo X
    // TODO: 2. Sistema que registre muchas figuras geometricas (Menu) un listado general

    vector<Figura *> *figuras = new vector<Figura *>{
        new Cuadrado(0, 0, 10),
        new Circulo(10, 10, 20),
        new Circulo(50, 50, 5),
        new Cuadrado(100, 100, 50),
        new Rectangulo(400, 400, 3, 4),
        new Cubo(200, 200, 2),
        new Esfera(300, 300, 2)};
    menu(figuras);
    for (auto figurita : *figuras)
    {
        figurita->mostrar();
        cout << "Area: " << figurita->calcularArea() << endl
             << endl;
        delete figurita;
    };
    delete figuras;
    return 0;
}
