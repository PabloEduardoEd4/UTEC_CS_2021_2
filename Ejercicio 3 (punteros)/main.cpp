#include <iostream>

/*
Ejercicio base: 3 pts (entrega al final de la clase): subir el código a GRADESCOPE

Desarrolle un código en C++ que simule la colisión de dos estrellas de acuerdo a las siguientes instrucciones:

Luego de la colisión, la estrella más pesada obtiene la suma de los pesos de las estrellas que colisionan, 
y su diámetro se duplica. Los pesos están en unidades de masas solares.

Primera colisión: estrella A  (1 masa solar, diámetro 0.5), y estrella B (2 masas solares, diámetro 1).

Segunda colisión: estrella C (10 masas solares, diámetro 5) y estrella D (3 masas solares, diámetro 1.5).

Tercera colisión: estrellas sobrevivientes de las dos primeras colisiones.

Calcule peso y volumen finales de las estrellas que sobreviven a la colisión.

El volumen de la estrella puede aproximarse al volumen de una esfera de radio r: 4/3 pi r^3

El código debe usar punteros, y el main debe contener solo la declaración de variables y llamada a funciones.
*/

void colision(float masa_estrella_1, float diametro_estrella_1, float masa_estrella_2, float diametro_estrella_2, float &masa_resultado, float &diametro_resultado)
{
	masa_resultado = masa_estrella_1 + masa_estrella_2;
	if (masa_estrella_1 > masa_estrella_2)
	{
		diametro_resultado = diametro_estrella_1 * 2;
	}
	else
	{
		diametro_resultado = diametro_estrella_2 * 2;
	}
}

float volume(float &radius)
{
	return (4 / 3) * 3.1415 * radius * radius * radius;
}

void print(float masa_estrella_3, float diametro_estrella_3)
{
	std::cout << "Peso: " << masa_estrella_3 << '\n'
			  << "Volumen: " << volume(diametro_estrella_3) << std::endl;
}

int main(int argc, char *argv[])
{
	//DECLARACION
	float estrella_A[] = {1.0, .5};
	float estrella_B[] = {2, 1};
	float estrella_C[] = {10, 5};
	float estrella_D[] = {3, 1.5};
	float masa_estrella_1;
	float diametro_estrella_1;
	float masa_estrella_2;
	float diametro_estrella_2;
	float masa_estrella_3;
	float diametro_estrella_3;
	colision(estrella_A[0], estrella_A[1], estrella_B[0], estrella_B[1], masa_estrella_1, diametro_estrella_1);
	colision(estrella_C[0], estrella_C[1], estrella_D[0], estrella_D[1], masa_estrella_2, diametro_estrella_2);
	colision(masa_estrella_1, diametro_estrella_1, masa_estrella_2, diametro_estrella_2, masa_estrella_3, diametro_estrella_3);
	print(masa_estrella_3, diametro_estrella_3);
}