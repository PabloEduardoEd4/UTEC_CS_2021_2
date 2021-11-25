//
// Created by estan on 10/21/2021.
//

#include "funciones.h"
#include <iostream>

using namespace std;

int ingresarNumeroAlumnos()
{
    int alumnos = 0;
    do
    {
        cout << "Ingrese numero de alumnos (>= 15): ";
        cin >> alumnos;
    } while (alumnos < 15);
    return alumnos;
}

float ingresarNotaInvididual(int numeroAlumno)
{
    float nota;
    do
    {
        cout << "Ingrese nota del alumno " << numeroAlumno << ": ";
        cin >> nota;
    } while (nota < 0 || nota > 20);
    return nota;
}

float *ingresarNotasAlumnos(int numeroAlumnos)
{
    float *pNotas = new float[numeroAlumnos]();
    for (int alumno = 0; alumno < numeroAlumnos; ++alumno)
        pNotas[alumno] = ingresarNotaInvididual(alumno + 1);
    return pNotas;
}

void calcularEstadisticos(float *pNotas, int numeroAlumnos, float &promedio, float &mayor, float &menor)
{
    promedio = 0.0;
    mayor = pNotas[0];
    menor = pNotas[1];
    for (int i = 0; i < numeroAlumnos; ++i)
    {
        promedio += pNotas[i];
        mayor = max(mayor, pNotas[i]);
        menor = min(menor, pNotas[i]);
    }
    promedio = promedio / numeroAlumnos;
}

void mostrarEstadisticos(float promedio, float mayor, float menor)
{
    cout << "Estadisticas de notas" << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Mayor: " << mayor << endl;
    cout << "Menor: " << menor << endl;
}

void mostrarPromedioElimandoMenor(float *pNotas, int numeroAlumnos, float menor)
{
    int total = 0;
    float promedio = 0.0;
    for (int i = 0; i < numeroAlumnos; ++i)
        if (pNotas[i] != menor)
        {
            promedio += pNotas[i];
            total++;
        }
    promedio = promedio / total;
    cout << "Promedio eliminando la nota menor: " << promedio << endl;
}
