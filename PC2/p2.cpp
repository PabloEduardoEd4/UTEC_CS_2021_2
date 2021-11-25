#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "p2.h"

using namespace std;

int input_size()
{
    int size = 0;
    do
    {
        cout << "Numero de elementos: ";
        cin >> size;
    } while (size > 10 || size <= 0);

    return size;
}

void print_set(string name, vector<int> a)
{
    cout << name << " = {";
    for (auto i : a)
        cout << i << ",";
    cout << "}" << endl;
}

vector<int> generate_vect(int size)
{
    vector<int> temp;
    for (int i = 0; i < size; i++)
        temp.push_back(rand() % 21);
    return temp;
}

vector<int> intesect(vector<int> a, vector<int> b)
{
    vector<int> c;
    for (auto i : a)
        for (auto j : b)
            if (i == j)
            {
                c.push_back(i);
                break;
            }
    return c;
}

vector<int> symetric(vector<int> a, vector<int> b, vector<int> intesect)
{
    vector<int> c;
    bool in = false;
    for (auto i : a)
    {
        for (auto j : intesect)
            if (i == j)
            {
                in = true;
            }
        if (!in)
            c.push_back(i);
        break;
        in = false;
    }
    in = false;
    for (auto i : b)
    {
        for (auto j : intesect)
            if (i == j)
            {
                in = true;
            }
        if (!in)
            c.push_back(i);
        in = false;
    }
    return c;
}

void solucion_2()
{
    srand(time(nullptr));
    int size = input_size();
    vector<int> a = generate_vect(size);
    vector<int> b = generate_vect(size);
    vector<int> c = intesect(a, b);
    print_set("A", a);
    print_set("B", b);
    print_set("A^B", symetric(a, b, c));
    print_set("AnB", intesect(a, b));
}