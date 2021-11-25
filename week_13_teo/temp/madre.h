//
// Created by Jose Fiestas on 19/11/21.
//

#ifndef INC_2021_II_TEO3_SEM12_U6_S2_MADRE_H
#define INC_2021_II_TEO3_SEM12_U6_S2_MADRE_H
class Madre : public Familia
{
    string nombre = " ";
    int edad = 0;

public:
    Madre(){};
    Madre(string a, string n, int e) : Familia(a), nombre(n), edad(e) {}
    string get_nombre() { return this->nombre; }

    virtual ~Madre() { cout << "Destruye Madre" << endl; }
};
#endif //INC_2021_II_TEO3_SEM12_U6_S2_MADRE_H
