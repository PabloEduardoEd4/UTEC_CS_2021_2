//
// Created by estan on 12/3/2021.
//

#ifndef LAB035_UNIVERSIDAD_H
#define LAB035_UNIVERSIDAD_H
#include "Alumno.h"
#include <vector>
class Universidad
{
private:
    vector<Alumno *> *alumnos;

public:
    // constructor
    Universidad();
    // acceso
    vector<Alumno *> *getAlumnos() const;
    void setAlumnos(vector<Alumno *> *alumnos);
    // comportamiento
    void matricularAlumnoPreGrado(const string &codigo, const string &nombre, const string &apellidoPaterno,
                                  const string &apellidoMaterno, const string &apoderado);
    void matricularAlumnoPostGrado(const string &codigo, const string &nombre, const string &apellidoPaterno,
                                   const string &apellidoMaterno, const string &empresaTrabajo);
    bool codigoValido(std::string codigo);
    void emitirListadoAlumnosMatriculados();
    // destructor
    virtual ~Universidad();
};

#endif // LAB035_UNIVERSIDAD_H
