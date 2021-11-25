#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include "p2.h"

using namespace std;

class Estadistica
{
private:
    vector<double> _a;

public:
    Estadistica(vector<double> a) : _a(a)
    {
        sort(_a.begin(), _a.end());
    };
    double hallarMaximo()
    {
        double max = _a.at(0);
        for (auto i : _a)
            if (i > max)
                max = i;
        return max;
    }
    double hallarMinimo()
    {
        double min = _a.at(0);
        for (auto i : _a)
            if (i < min)
                min = i;
        return min;
    }
    double hallarMedia()
    {
        double sum = 0;
        for (auto i : _a)
            sum += i;
        return sum / _a.size();
    }
    double hallarMediana()
    {
        if ((_a.size()) % 2 == 0)
        {
            return (_a.at(_a.size() / 2) + _a.at((_a.size() / 2) + 1)) / 2;
        }
        else
        {
            return _a.at(((int)_a.size() / 2) + 1);
        }
    }
    void mostrarDatos()
    {
        double sum = 0;
        cout << "{";
        for (auto i : _a)
            cout << i << ", ";
        cout << "}" << endl;
    }
    ~Estadistica()
    {
        _a.clear();
    }
};

void solucion_3()
{
    Estadistica a = Estadistica(vector<double>{3, 5, 8, 10, 24, 36, 79, 80});
    cout << "Mostrar: ";
    a.mostrarDatos();
    cout << "Maximo: " << a.hallarMaximo() << endl;
    cout << "Minimo: " << a.hallarMinimo() << endl;
    cout << "Media: " << a.hallarMedia() << endl;
    cout << "Mediana: " << a.hallarMediana() << endl;
}