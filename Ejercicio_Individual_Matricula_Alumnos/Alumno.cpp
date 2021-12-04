//
// Created by estan on 12/2/2021.
//

#include "Alumno.h"

Alumno::Alumno(const string &codigo, const string &nombre, const string &apellidoPaterno, const string &apellidoMaterno)
    : codigo(codigo), nombre(nombre), apellidoPaterno(apellidoPaterno), apellidoMaterno(apellidoMaterno) {}

const string &Alumno::getCodigo() const
{
    return codigo;
}

void Alumno::setCodigo(const string &codigo)
{
    Alumno::codigo = codigo;
}

const string &Alumno::getNombre() const
{
    return nombre;
}

void Alumno::setNombre(const string &nombre)
{
    Alumno::nombre = nombre;
}

const string &Alumno::getApellidoPaterno() const
{
    return apellidoPaterno;
}

void Alumno::setApellidoPaterno(const string &apellidoPaterno)
{
    Alumno::apellidoPaterno = apellidoPaterno;
}

const string &Alumno::getApellidoMaterno() const
{
    return apellidoMaterno;
}

void Alumno::setApellidoMaterno(const string &apellidoMaterno)
{
    Alumno::apellidoMaterno = apellidoMaterno;
}

void Alumno::mostrar()
{
    cout << codigo << "\t" << apellidoMaterno << " " << apellidoPaterno << ", " << nombre << "\t";
}

Alumno::~Alumno()
{
    codigo = "";
    nombre = "";
    apellidoPaterno = "";
    apellidoMaterno = "";
}
