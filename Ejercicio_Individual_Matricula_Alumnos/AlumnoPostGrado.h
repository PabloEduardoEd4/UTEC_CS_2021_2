//
// Created by estan on 12/2/2021.
//

#ifndef LAB035_ALUMNOPOSTGRADO_H
#define LAB035_ALUMNOPOSTGRADO_H
#include "Alumno.h"

class AlumnoPostGrado: public Alumno{
private:
    string empresaTrabajo;
public:
    AlumnoPostGrado(const string &codigo, const string &nombre, const string &apellidoPaterno,
                    const string &apellidoMaterno, const string &empresaTrabajo);

    const string &getEmpresaTrabajo() const;
    void setEmpresaTrabajo(const string &empresaTrabajo);

    void mostrar() override;

    ~AlumnoPostGrado() override;

};


#endif //LAB035_ALUMNOPOSTGRADO_H
