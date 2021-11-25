#include <iostream>
#include <string>

class TarjetaCredito
{
private:
	std::string _cvv = "000", _v = "01/01/2001";

public:
	TarjetaCredito() {}
	TarjetaCredito(std::string cvv, std::string v) : _cvv(cvv), _v(v) {}
	std::string getCVVtarjeta() { return _cvv; }
	std::string getVtarjeta() { return _v; }
};

class Persona
{
private:
	std::string _nombre = "";
	int _edad = 0;
	TarjetaCredito *_VISA;

public:
	Persona() {}
	Persona(std::string nombre, int edad) : _nombre(nombre), _edad(edad) {}
	std::string getNombre() { return _nombre; }
	std::string associar_tarjeta(TarjetaCredito *VISA)
	{
		_VISA = VISA;
	}
	std::string getCVVtarjeta() { return _VISA->getCVVtarjeta(); }
	std::string getVtarjeta() { return _VISA->getVtarjeta(); }

	~Persona() { std::cout << "Pesona Borrada" << std::endl; }
};

int main(int argc, char *argv[])
{
	TarjetaCredito *visa = new TarjetaCredito();
	Persona *a = new Persona();
	a->associar_tarjeta(visa);
	std::cout << a->getNombre() << std::endl;
	std::cout
		<< "Hello world!" << std::endl;
	delete visa;
	delete a;
}