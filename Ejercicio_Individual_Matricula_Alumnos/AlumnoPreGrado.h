//
// Created by estan on 12/2/2021.
//

#ifndef LAB035_ALUMNOPREGRADO_H
#define LAB035_ALUMNOPREGRADO_H
#include "Alumno.h"

class AlumnoPreGrado: public Alumno{
private:
    string apoderado;
public:
    AlumnoPreGrado(const string &codigo, const string &nombre, const string &apellidoPaterno,
                   const string &apellidoMaterno, const string &apoderado);

    const string &getApoderado() const;
    void setApoderado(const string &apoderado);

    void mostrar() override;

    ~AlumnoPreGrado() override;

};


#endif //LAB035_ALUMNOPREGRADO_H
