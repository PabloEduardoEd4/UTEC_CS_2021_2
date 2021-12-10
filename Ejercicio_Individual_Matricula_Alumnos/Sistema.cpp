//
// Created by estan on 12/3/2021.
//

#include "Sistema.h"
#include <string>

Sistema::Sistema()
{
    universidad = new Universidad();
}

Universidad *Sistema::getUniversidad() const
{
    return universidad;
}

void Sistema::setUniversidad(Universidad *universidad)
{
    Sistema::universidad = universidad;
}

void Sistema::ejecutar()
{
    int opcion = 0;
    do
    {

        opcion = seleccionarMenu();
        switch (opcion)
        {
        case 1:
            matricularAlumnoPreGrado();
            pre++;
            break;
        case 2:
            matricularAlumnoPostGrado();
            post++;
            break;
        case 3:
            emitirListadoMatricula();
            break;
        // TODO: Hace las estadisticas (Cuantos alumnos de Pre y cuantos de Post)
        case 4:
            std::cout << "# de Pre-Grado: " << pre << std::endl;
            std::cout << "# de Post-Grado: " << post << std::endl;
            system("pause");
            break;
        }
    } while (opcion != 5);
}

int Sistema::seleccionarMenu()
{
    system("cls");
    int opcion = 0;
    do
    {
        cout << "UTEC - Sistema de Matricula de Alumnos\n"
             << endl;
        cout << "[1] Matricular Alumno Pre-Grado" << endl;
        cout << "[2] Matricular Alumno Post-Grado" << endl;
        cout << "[3] Emitir listado de Matricula" << endl;
        cout << "[4] Estadisticas " << endl;
        cout << "[5] Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
    } while (opcion < 0 || opcion > 6);
    return opcion;
}

void Sistema::matricularAlumnoPreGrado()
{
    // TODO: Validar duplicidad de codigo de alumno
    system("cls");
    cin.ignore();
    string codigo, nombre, apellidoPaterno, apellidoMaterno, apoderado;
    cout << "Matricula de Alumno Pre-Grado\n"
         << endl;
    do
    {
        cout << "Codigo: ";
        getline(cin, codigo);
    } while (!(universidad->codigoValido(codigo)));
    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Apellido Paterno: ";
    getline(cin, apellidoPaterno);
    cout << "Apellido Materno: ";
    getline(cin, apellidoMaterno);
    cout << "Apoderado: ";
    getline(cin, apoderado);
    universidad->matricularAlumnoPreGrado(codigo, nombre, apellidoPaterno, apellidoMaterno, apoderado);
}

void Sistema::matricularAlumnoPostGrado()
{
    // TODO: Validar duplicidad de codigo de alumno
    system("cls");
    cin.ignore();
    string codigo, nombre, apellidoPaterno, apellidoMaterno, empresa;
    cout << "Matricula de Alumno Pre-Grado\n"
         << endl;

    do
    {
        cout << "Codigo: ";
        getline(cin, codigo);
    } while (!(universidad->codigoValido(codigo)));
    cout
        << "Nombre: ";
    getline(cin, nombre);
    cout << "Apellido Paterno: ";
    getline(cin, apellidoPaterno);
    cout << "Apellido Materno: ";
    getline(cin, apellidoMaterno);
    cout << "Empresa actual de trabajo: ";
    getline(cin, empresa);
    universidad->matricularAlumnoPostGrado(codigo, nombre, apellidoPaterno, apellidoMaterno, empresa);
}

void Sistema::emitirListadoMatricula()
{
    system("cls");
    cout << "UTEC - Sistema de Matricula\n"
         << endl;
    cout << "Listado de Alumnos Matriculados\n"
         << endl;
    cout << "Codigo\tApellidos y Nombres\tApoderado/Trabajo" << endl;
    universidad->emitirListadoAlumnosMatriculados();
    system("pause");
}

Sistema::~Sistema()
{
    delete universidad;
}
