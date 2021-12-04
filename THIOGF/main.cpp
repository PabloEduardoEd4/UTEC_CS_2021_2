#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
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
	std::string posicion;
	int sueldo;

public:
	Empleado(std::string _nombre, std::string posicion, float _sueldo) : nombre(_nombre), posicion(posicion), sueldo(_sueldo){};
	std::string get_Nombre() { return nombre; }
	std::string get_Posicion() { return posicion; }
	float Salario() { return sueldo * 8 * 20; }
};

class Consultor : public Empleado
{
private:
	bool renumerado;
	std::string tipo;

public:
	Consultor(std::string _nombre, std::string _tipo, bool _renumerado) : Empleado(_nombre, "Consultor", 10), tipo(_tipo), renumerado(_renumerado) {}
	std::string get_Tipo() { return tipo; }
	void renumera() { renumerado = true; }
};

class Administrativo : public Empleado
{
private:
	std::string nivel;

public:
	Administrativo(std::string _nombre, std::string nivel) : Empleado(_nombre, "Admin " + nivel, 10 + 10 * (nivel == "Senior")) {}
	std::string get_Tipo() { return nivel; }
	void senior()
	{
		nivel = "Senior";
	}
};

void ascenso(Empleado *d)
{
	Empleado *c;
	if (d->get_Posicion() == "Consultor")
		c = new Administrativo(d->get_Nombre(), "Junior");
	else
		c = new Administrativo(d->get_Nombre(), "Senior");
	delete d;
	d = c;
}

void print(std::vector<Empleado *> a)
{
	for (auto i : a)
	{
		std::cout << "Nombre:" << i->get_Nombre() << "\tTipo de Empleado:" << i->get_Posicion() << "\tSueldo (por mes): $" << i->Salario() << std::endl;
	}
}

int main(int argc, char *argv[])
{
	std::string name[] = {"Ba", "Bob", "Javier", "Alonso", "Pedro"};
	std::string tipo[] = {"A", "B", "J", "D", "L"};
	std::vector<Empleado *> a;
	for (int i = 0; i < 5; i++)
		a.push_back(new Consultor(name[i], tipo[i], (i < 3)));
	for (int i = 0; i < 10; i++)
	{
		std::string s = i < 6 ? "Junior" : "Senior";
		a.push_back(new Administrativo(name[i % 5], s));
	}
	print(a);
	return 0;
}