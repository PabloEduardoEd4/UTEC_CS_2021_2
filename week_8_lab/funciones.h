#ifndef LAB017_FUNCIONES_H
#define LAB017_FUNCIONES_H

int ingresarNumeroAlumnos();
float ingresarNotaInvididual(int numeroAlumno);
float *ingresarNotasAlumnos(int numeroAlumnos);
void calcularEstadisticos(float *pNotas, int numeroAlumnos, float &promedio, float &mayor, float &menor);
void mostrarEstadisticos(float promedio, float mayor, float menor);
void mostrarPromedioElimandoMenor(float *pNotas, int numeroAlumnos, float menor);

#endif //LAB017_FUNCIONES_H
