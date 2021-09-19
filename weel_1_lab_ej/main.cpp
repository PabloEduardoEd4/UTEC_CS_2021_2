#include <iostream>
#include <string>

int main()
{
	// Realiza un programa que permita leer un número float
	// y el programa imprima en una línea la parte entera del
	// número y en la línea siguiente la parte fraccionaria del número.
	/*
	float input;
	std::cout << "Ingrese un float:\t";
	std::cin >> input;
	std::cout << std::endl;
	const float whole = int(input);
	std::cout << "Parte entera:\t" << int(input) << std::endl;
	std::cout << "Faccionaria:\t" << input -  whole << std::endl;
	*/

	/*
	Zona Urbana
	En zona escolar: 30 km/h
	En calles y jirones: 40 km/h
	En avenidas: 60 km/h
	En vías expresas: 80 km/h

	Carreteras
	En caminos rurales: 60 km/h
	Para vehículos de carga: 80 km/h
	Para vehículos de servicio público de transporte de pasajeros: 90 km/h
	Para automoviles, camionetas y motocicletas: 100 km/h
	*/

	std::string lugar;
	std::string veiculo;
	int velocidad;

	std::cout << "Lugar: ";
	std::getline(std::cin, lugar);
	std::cout << "Veiculo: ";
	std::getline(std::cin, veiculo);
	std::cout;
	std::cout << "Velocidad: ";
	std::cin >> velocidad;

	bool over = true;
	//std::cout << (lugar == "calles");

	if (lugar == "zona escolar")
	{
		over = velocidad > 30;
	}
	if (lugar == "calles" || lugar == "jirones")
	{
		over = velocidad > 40;
	}
	if (lugar == "avenidas")
	{
		over = velocidad > 60;
	}
	if (lugar == "vías expresas")
	{
		over = velocidad > 80;
	}
	if (lugar == "caminos rurales")
	{
		over = velocidad > 60;
	}
	if (lugar == "carreteras")
	{
		if (veiculo == "vehículos de carga")
		{
			over = velocidad > 80;
		}
		if (veiculo == "vehículos de servicio público de transporte de pasajeros")
		{
			over = velocidad > 90;
		}
		if (veiculo == "automoviles" || veiculo == "camionetas" || veiculo == "motocicletas")
		{
			over = velocidad > 100;
		}
	}
	std::cout << (over ? "Sobre Velocidad Maxima" : "Bien");
}