//
// Created by estan on 12/3/2021.
//

#include "Universidad.h"
#include "AlumnoPreGrado.h"
#include "AlumnoPostGrado.h"
#include <algorithm>

Universidad::Universidad()
{
    // Crear a la colección de alumnos
    alumnos = new vector<Alumno *>();
}

vector<Alumno *> *Universidad::getAlumnos() const
{
    return alumnos;
}

void Universidad::setAlumnos(vector<Alumno *> *alumnos)
{
    Universidad::alumnos = alumnos;
}

void Universidad::matricularAlumnoPreGrado(const string &codigo, const string &nombre, const string &apellidoPaterno,
                                           const string &apellidoMaterno, const string &apoderado)
{
    // TODO: Validar no duplicidad de codigo
    alumnos->push_back(new AlumnoPreGrado(codigo, nombre, apellidoPaterno, apellidoMaterno, apoderado));
}

void Universidad::matricularAlumnoPostGrado(const string &codigo, const string &nombre, const string &apellidoPaterno,
                                            const string &apellidoMaterno, const string &empresaTrabajo)
{
    // TODO: Validar no dupliciada de codigo
    alumnos->push_back(new AlumnoPostGrado(codigo, nombre, apellidoPaterno, apellidoMaterno, empresaTrabajo));
}

// TODO: Listado salga ordenado por Apellido Paterno

bool comp(Alumno *a, Alumno *b) { return a->getApellidoPaterno() < b->getApellidoPaterno(); }

void Universidad::emitirListadoAlumnosMatriculados()
{
    sort(alumnos->begin(), alumnos->end(), comp);
    for (const auto alumno : *alumnos)
        alumno->mostrar();
}

bool Universidad::codigoValido(std::string codigo)
{
    for (const auto alumno : *alumnos)
        if (alumno->getCodigo() == codigo)
            return false;
    return true;
}

Universidad::~Universidad()
{
    // Liberar a los objetos alumnos
    for (const auto alumno : *alumnos)
        delete alumno;
    // Liberar la coleccion
    delete alumnos;
}
