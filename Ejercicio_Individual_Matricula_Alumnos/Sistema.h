//
// Created by estan on 12/3/2021.
//

#ifndef LAB035_SISTEMA_H
#define LAB035_SISTEMA_H
#include "Universidad.h"

class Sistema
{
private:
    Universidad *universidad;
    int pre = 0;
    int post = 0;
    int seleccionarMenu();

public:
    // constructor
    Sistema();
    // acceso
    Universidad *getUniversidad() const;
    void setUniversidad(Universidad *universidad);
    void matricularAlumnoPreGrado();
    void matricularAlumnoPostGrado();
    void emitirListadoMatricula();
    // comportamiento
    void ejecutar();
    // destructor
    virtual ~Sistema();
};

#endif // LAB035_SISTEMA_H
