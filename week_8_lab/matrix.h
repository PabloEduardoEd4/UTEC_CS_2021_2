#ifndef matrix
#define matrix

int ingresarDimensionArreglo();
int *crearArregloDinamico(int cantidadElementos);
void imprimirArregloDinamico(int *pArreglo, int cantidadElementos);
void generarArregloMultiplos(int *pArregloOriginal, int cantidadElementos, int numero, int *&pArregloMultiplo, int &numeroMultiplos);

#endif