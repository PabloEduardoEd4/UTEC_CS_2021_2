//
// Created by estan on 11/4/2021.
//

#ifndef LAB027_PROFESOR_H
#define LAB027_PROFESOR_H
#include <string>
using namespace std;

class Profesor
{
private:
    string nombre;
    string apellidos;
    int edad;
    int horasDictado;

public:
    Profesor();
    Profesor(const string &nombre, const string &apellidos, int edad, int horasDictado);

    const string &getNombre() const;
    void setNombre(const string &nombre);
    const string &getApellidos() const;
    void setApellidos(const string &apellidos);
    int getEdad() const;
    void setEdad(int edad);
    int getHorasDictado() const;
    void setHorasDictado(int horasDictado);

    virtual ~Profesor();

public:
};

#endif //LAB027_PROFESOR_H
