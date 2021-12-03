#include <iostream>
#include <string>
#include <vector>
/*
Defina la clase Empleado con elementos nombre y salario por hora. Defina la clase derivada Consultor, con una variable lógica remunerado.
Si es remunerado, recibe un salario fijo mensual, de lo contrario recibe un salario por hora trabajada.

Asimismo, defina una función salario, que pregunte si el consultor es remunerado, o no, y calcule su sueldo mensual. El programa debe:

Generar 5 Empleados consultores (nombres ficticios), de los cuales 3 sean remunerados, y 2 sean no-remunerados. Defina el salario
por hora para cada uno de ellos. Asuma trabajo de 8 horas por día, y 20 días útiles por mes.
defina un método que cambie el estado de un consultor no remunerado en uno remunerado

imprima la lista de empleados con los datos: nombre, tipo de consultor, salario mensual
*/

class Empleado
{
protected:
	std::string nombre;
	int sueldo;

public:
	Empleado(std::string _nombre, float _sueldo) : nombre(_nombre), sueldo(_sueldo){};
	std::string get_Nombre() { return nombre; }
};

class Consultor : public Empleado
{
private:
	bool renumerado;
	std::string tipo;

public:
	Consultor(std::string _nombre, float _sueldo, std::string _tipo, bool _renumerado) : Empleado(_nombre, _sueldo), tipo(_tipo), renumerado(_renumerado) {}
	std::string get_Tipo() { return tipo; }
	float Salario()
	{
		return sueldo * 8 * 20;
	}
	void renumera()
	{
		renumerado = true;
	}
};

void print(std::vector<Consultor *> a)
{
	for (auto i : a)
	{
		std::cout << "Nombre:" << i->get_Nombre() << "\tTipo de consultor:" << i->get_Tipo() << "\tSueldo (por mes):" << i->Salario() << std::endl;
	}
}

int main(int argc, char *argv[])
{
	std::string name[] = {"Ba", "Bob", "Javier", "Alonso", "Pedro"};
	std::string tipo[] = {"A", "B", "J", "D", "L"};
	std::vector<Consultor *> a;
	for (int i = 0; i < 5; i++)
		a.push_back(new Consultor(name[i], (i + 1) * 10, tipo[i], (i < 3)));
	print(a);
}