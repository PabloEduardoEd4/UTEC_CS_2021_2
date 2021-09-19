#include <iostream>

//VERSION PARA NUEVA PARTE, mi penultima submition es la version anterior

/*
Escriba un código que permita ingresar un capital inicial y calcule el tiempo en años necesario para lograr un capital final (también dado como input). 
El interés anual es tambien un dato de entrada.
Por ejemplo: si el capital es de 1000 soles y el interes es del 1% anual, el primer año se tendrá 1000*1.01=1010, 
el segundo año se tendrá 1010x1.01=1020.1, etc.
Una formula general seria: capital_nuevo=capital_actual x (1+interes/100)
Al culminar, el código debe imprimir la cantidad de años necesaria para lograr el capital deseado
*/

int main(int argc, char *argv[])
{
	//Entry variables
	double capital_end, capital_start, capital_current, perctage_intrest, intrest;

	//Output variables
	unsigned int years = 0;

	std::cout << "Capital inicial" << std::endl;
	std::cin >> capital_start;
	capital_current = capital_start;
	std::cout << "Capital final" << std::endl;
	std::cin >> capital_end;
	std::cout << "Interes" << std::endl;
	std::cin >> intrest;
	perctage_intrest = (1 + (intrest / 100.0));
	while (capital_current < capital_end)
	{
		capital_current = capital_current * perctage_intrest;
		years++;
	}
	std::cout << "(Interes Anual) El Capital final se lograra en: " << years << " a~nos (tilde no funciona en mi teclado)" << std::endl;

	//Extra
	//Implemente el calculo del tiempo necesario para lograr el capital deseado con un interés semanal y mensual
	//Para el codigo asumire que hay 4 semanas en un mes
	double month_adjusted_intrest = 1, week_adjusted_intrest = 1;
	for (int x = 0; x < 12; x++)
		month_adjusted_intrest *= perctage_intrest;
	for (int x = 0; x < (12 * 4); x++)
		week_adjusted_intrest *= perctage_intrest;
	capital_current = capital_start;
	years = 0;
	while (capital_current < capital_end)
	{
		capital_current = capital_current * month_adjusted_intrest;
		years++;
	}
	std::cout << "(Interes Mensual) El Capital final se lograra en: " << years << " a~nos (tilde no funciona en mi teclado)" << std::endl;
	capital_current = capital_start;
	years = 0;
	while (capital_current < capital_end)
	{
		capital_current = capital_current * week_adjusted_intrest;
		years++;
	}
	std::cout << "(Interes semanal) El Capital final se lograra en: " << years << " a~nos (tilde no funciona en mi teclado)" << std::endl;
}
