#include <iostream>
#include <typeinfo>

/*
El gerente de Starbucks, realizará un sondeo para determinar cuál de las siguientes bebidas, tiene mayor aceptación entre los turistas que visitan su local.
 
Las bebidas a considerar son:
 
<M> Mango Frappuccino
<F>  Fresa Creme Frappuccino
<V>  Vainilla Creme Frappuccino
 
Realice un programa, que permita leer como dato el número de personas a las cuales se aplicará la encuesta (N, un número que debe estar en el rango de 5 a 30 inclusive).  
Luego permita realizar la encuesta y muestre los resultados de las preferencias expresados en porcentajes.
 
Al realizar la encuesta su programa deberá controlar que el usuario ingrese su preferencia únicamente utilizando las letras : M, m, F, f, V, v.
*/

int main(int argc, char *argv[])
{
	//Variables de entrada
	unsigned short number_of_interviewed;
	unsigned short mango = 0, fresa = 0, vanilla = 0;
	char drink;

	//Variables de salida
	float mango_percentage, fresa_percentage, vanilla_percentage;

	//Algorithim
	std::cout << "Encuestas Starbucks" << std::endl;
	do
	{

		std::cout << "Cuantas Persona haran la encuesta (entre 5 a 30)" << std::endl;
		std::cin >> number_of_interviewed;

	} while (number_of_interviewed > 30 || number_of_interviewed < 5);

	for (unsigned short x = 0; x < number_of_interviewed; x++)
	{
		std::cout << "Que bebida prefiere?\n"
				  << "<M> Mango Frappuccino\n"
				  << "<F>  Fresa Creme Frappuccino\n"
				  << "<V>  Vainilla Creme Frappuccino"
				  << std::endl;
		std::cin >> drink;
		drink = toupper(drink);
		switch (drink)
		{
		case 'M':
			mango++;
			break;
		case 'F':
			fresa++;
			break;
		case 'V':
			vanilla++;
			break;
		default:
			std::cout << "Invalido" << std::endl;
			x--;
			break;
		}
	}
	mango_percentage = mango * 100.0 / (float)number_of_interviewed;
	fresa_percentage = fresa * 100.0 / (float)number_of_interviewed;
	vanilla_percentage = vanilla * 100.0 / (float)number_of_interviewed;
	std::cout << mango_percentage << "% prefieren mango\n"
			  << fresa_percentage << "% prefieren fresa\n"
			  << vanilla_percentage << "% prefieren vanilla\n"
			  << std::endl;
	return 0;
}