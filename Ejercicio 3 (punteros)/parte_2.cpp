/*Ejercicio base: 3 pts (entrega al final de la clase): subir el código a GRADESCOPE

Desarrolle un código en C++ que simule la colisión de dos estrellas de acuerdo a las siguientes instrucciones:

Luego de la colisión, la estrella más pesada obtiene la suma de los pesos de las estrellas que colisionan, 
y su diámetro se duplica. Los pesos están en unidades de masas solares.

Primera colisión: estrella A  (1 masa solar, diámetro 0.5), y estrella B (2 masas solares, diámetro 1).

Segunda colisión: estrella C (10 masas solares, diámetro 5) y estrella D (3 masas solares, diámetro 1.5).

Tercera colisión: estrellas sobrevivientes de las dos primeras colisiones.

Calcule peso y volumen finales de las estrellas que sobreviven a la colisión.

El volumen de la estrella puede aproximarse al volumen de una esfera de radio r: 4/3 pi r^3

El código debe usar punteros, y el main debe contener solo la declaración de variables y llamada a funciones.

Ejercicio extra: 1 punto (entrega hasta medianoche):

Implemente el código para un total de 10 pares de estrellas, utilizando arrays y 
punteros a arrays. Escoja los pesos iniciales de las estrellas, tal que no se repitan (puede ser random)

Las colisiones se dan aleatoriamente (random), pero con la condición de que una pese por lo menos el doble de la otra. 
Las estrellas sobrevivientes también pueden colisionar entre si. Calcule los pesos de las estrellas sobrevivientes, 
que ya no colisionan, así como sus volúmenes.

El  main debe contener solo la declaración de variables y llamada a funciones.
rand()
*/

#include <iostream>

float volume(float radius)
{
    return (4 / 3) * 3.1415 * radius * radius * radius;
}

bool can_colide(int *a, int *b)
{
    return a[0] > b[0];
}

void generate(int stars[][2], size_t size)
{
    //Indice 0: Peso, 1: diametro
    for (size_t i = 0; i < size; i++)
    {
        stars[i][0] = rand() % 10 + 1;
        stars[i][1] = rand() % 5 + 1;
    }
}

void cycle(int stars[][2], size_t size)
{
    srand(rand());
    size_t index_1 = rand() % size;
    size_t index_2 = rand() % size;
    if (index_1 == index_2)
        index_1++;
    if (stars[index_1][0] == 0 || stars[index_2][0] == 0)
        return;
    if (stars[index_1][0] >= 2 * stars[index_2][0])
    {
        stars[index_1][0] += stars[index_2][0];
        stars[index_1][1] <<= 1;
        stars[index_2][0] = 0;
        stars[index_2][1] = 0;
    }
    else if (stars[index_2][0] >= 2 * stars[index_1][0])
    {
        stars[index_2][0] += stars[index_1][0];
        stars[index_2][1] <<= 1;
        stars[index_1][0] = 0;
        stars[index_1][1] = 0;
    }
    return;
}

bool check(int stars[][2], size_t size)
{
    int max = 0;
    int min = 255;
    for (size_t i = 0; i < size; i++)
    {
        if (stars[i][0] == 0)
            ;
        else
        {
            if (stars[i][0] > max)
                max = stars[i][0];
            if (stars[i][0] < min)
                min = stars[i][0];
        }
    }
    return min <= (max / 2) && min != max;
}

void print(int stars[][2], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << stars[i][0] << ' ' << stars[i][1] << std::endl;
    }
    std::cout << std::endl;
}

void remaining(int stars[][2], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (stars[i][0] != 0)
            std::cout << "Star [" << i << "]:: Mass:" << stars[i][0] << "\tVolume:" << volume((float)stars[i][1] / 2) << std::endl;
    }
    std::cout << std::endl;
}

void loop(int stars[][2], size_t size)
{
    while (check(stars, size))
    {
        cycle(stars, size);
        print(stars, size);
    }
}

int main(int argc, char *argv[])
{
    int seed;
    size_t size;

    std::cout << "Seed number from 1 to 10: ";
    std::cin >> seed;

    //Nota: no es completamente random ya que depende de del seed de la creacicion
    srand(seed);

    size = rand() % 10 + 1;

    int stars[seed][2];

    generate(stars, size);
    print(stars, size);
    loop(stars, size);
    remaining(stars, size);
    return 0;
}