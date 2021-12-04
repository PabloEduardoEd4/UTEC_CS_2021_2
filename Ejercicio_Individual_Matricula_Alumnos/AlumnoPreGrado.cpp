//
// Created by estan on 12/2/2021.
//

#include "AlumnoPreGrado.h"

AlumnoPreGrado::AlumnoPreGrado(const string &codigo, const string &nombre, const string &apellidoPaterno,
                               const string &apellidoMaterno, const string &apoderado) : Alumno(codigo, nombre,
                                                                                                apellidoPaterno,
                                                                                                apellidoMaterno),
                                                                                         apoderado(apoderado) {}

const string &AlumnoPreGrado::getApoderado() const {
    return apoderado;
}

void AlumnoPreGrado::setApoderado(const string &apoderado) {
    AlumnoPreGrado::apoderado = apoderado;
}

void AlumnoPreGrado::mostrar() {
    Alumno::mostrar();
    cout <<apoderado<<endl;
}

AlumnoPreGrado::~AlumnoPreGrado() {
    apoderado="";
}
