#include <iostream>

template <typename T>
void print(T output = "", char end_line = '\n')
{
	std::cout << output << end_line;
}

template <typename U, typename V>
V input(U output = "")
{
	V temp;
	std::cout << output;
	std::cin >> temp;
	return temp;
}

int main(int argc, char *argv[])
{
	unsigned int velocity = 0;
	char zoneType, streetType, vehicle;
	const char div[] = "+++++++++++++++++++++";
	std::cout << "Control de velocidades" << std::endl;
	std::cout << div << std::endl;
	while ((char)zoneType != 'U' && (char)zoneType != 'C')
	{
		print("Zone [U-Urbana C-Carretera]", ' ');
		std::cin >> zoneType;
	}
	switch (zoneType)
	{
	case 'U':
		print("[R] Caminos Rurales");
		print("[E] Vías expresas");
		print("[D] Avenidas");
		print("[L] Calles");
		print("[Z] Zona Escolar");
		std::cin >> streetType;
		break;
	case 'C':
		print("[A] Auto");
		print("[C] Camiones");
		print("[M] Motos");
		print("[V] Vehiculos de carga");
		print("[S] vehículos de servicio público de transporte de pasajeros");
		std::cin >> vehicle;
		break;
	default:
		break;
	}

	/*
	Incomplete Version
	bool inlimit;
	if (streetType != 97)
	{
		inlimit = (streetType == 'R' && )
	}
	else
	{
		1 == 1;
	}
	*/
}