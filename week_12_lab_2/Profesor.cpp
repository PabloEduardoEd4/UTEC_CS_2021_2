//
// Created by estan on 11/4/2021.
//

#include "Profesor.h"

Profesor::Profesor(const string &nombre, const string &apellidos, int edad, int horasDictado) : nombre(nombre),
                                                                                                apellidos(apellidos),
                                                                                                edad(edad),
                                                                                                horasDictado(
                                                                                                        horasDictado) {}

const string &Profesor::getNombre() const {
    return nombre;
}

void Profesor::setNombre(const string &nombre) {
    Profesor::nombre = nombre;
}

const string &Profesor::getApellidos() const {
    return apellidos;
}

void Profesor::setApellidos(const string &apellidos) {
    Profesor::apellidos = apellidos;
}

int Profesor::getEdad() const {
    return edad;
}

void Profesor::setEdad(int edad) {
    Profesor::edad = edad;
}

int Profesor::getHorasDictado() const {
    return horasDictado;
}

void Profesor::setHorasDictado(int horasDictado) {
    Profesor::horasDictado = horasDictado;
}

Profesor::~Profesor() {
    nombre="";
    apellidos="";
    edad=0;
    horasDictado=0;
}

Profesor::Profesor() {
    nombre="";
    apellidos="";
    edad=0;
    horasDictado=0;
}
