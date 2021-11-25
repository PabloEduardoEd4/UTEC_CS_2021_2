#include <iostream>
#include <string>
#include <vector>
#include <ctime>

/*
EJERCICIO BASE (3 pts): entrega al final de la clase. Subir el código a GRADESCOPE

Una trattoria tiene Pizzas en el menú. Cada Pizza tiene un tipo (hawaiana, napolitana, margarita), y un tamaño (personal y familiar). 
Los Clientes registrados de la trattoria tienen un código de cliente , realizan pedidos y hacen el pago en línea. 

Genere un código que utilice relaciones entre clases, realice 3 pedidos, e imprima la informacion de cada pedido, con los datos:

codigo del cliente, cantidad de pizzas, tipo y tamaño de las pizzas

Utilice punteros a objetos de clase

EJERCICIO OPCIONAL (1 pt): entrega hasta medianoche

Ahora utilice un atributo para el precio de las pizzas (asigne valores a los 3 tipos de pizzas), y genere un total de 20 pedidos. Imprima los datos de los pedidos como en el ejercicio base 
y calcule finalmente el importe total de las ventas del día de la trattoria.

Utilice vectores de punteros a objetos 
*/

// Reorganize para PARTE 2
class Pizza
{
private:
	std::string tipo;
	std::string tamano;
	float precio;

public:
	Pizza(std::string _tipo, std::string _tamano, float _precio) : tipo(_tipo), tamano(_tamano), precio(_precio) {}
	std::string get_tipo() { return tipo; }
	std::string get_tamano() { return tamano; }
	float get_price() { return precio; }
};

class Pedido
{
private:
	std::vector<Pizza *> p;
	float costo;

	void up_costo()
	{
		costo = 0;
		for (auto i : p)
		{
			costo += i->get_price();
		}
	}

public:
	Pedido() {}
	void addPizza(Pizza *_p)
	{
		p.push_back(_p);
	}
	void print_order()
	{
		for (auto i : p)
		{
			std::cout << ", Size: " << i->get_tamano() << " Tamano: " << i->get_tipo() << ' ';
		}
	}
	void print_amount()
	{
		std::cout << "Pizzas: " << p.size();
	}
	void print_price()
	{
		up_costo();
		std::cout
			<< "Precio Total: $" << costo;
	}
	float get_price()
	{
		up_costo();
		return costo;
	}
	~Pedido() {}
};

class Cliente
{
private:
	float total = 0;
	std::string codigo;
	std::vector<Pedido *> p;

public:
	Cliente(std::string _codigo) : codigo(_codigo)
	{
	}
	void add_pedido(Pedido *_p)
	{
		p.push_back(_p);
		total += _p->get_price();
	}
	void printpedido()
	{
		std::cout << "Cliente Codigo: " << codigo << std::endl;
		for (auto i : p)
		{
			std::cout << '\t';
			i->print_amount();
			std::cout << ' ';
			i->print_order();
			std::cout << ' ';
			i->print_price();
			std::cout
				<< std::endl;
		}
	}
	float get_total()
	{
		total = 0;
		for (auto i : p)
		{
			total += (i->get_price());
		}
		return total;
	}
	~Cliente()
	{
		for (auto i : p)
			delete i;
	}
};

void total(std::vector<Cliente *> _p)
{
	float total = 0;
	for (auto i : _p)
	{
		total += i->get_total();
	}
	std::cout << "Total del dia: $" << total << std::endl;
}

void print(std::vector<Cliente *> _p)
{
	for (auto i : _p)
	{
		i->printpedido();
	}
	total(_p);
}

int main(int argc, char *argv[])
{
	srand(time(nullptr));
	Cliente *c = new Cliente("C");
	Cliente *d = new Cliente("D");
	Cliente *e = new Cliente("E");

	Pizza *ma = new Pizza("Margarita", "Familiar", 12);
	Pizza *pe = new Pizza("Hawaiana", "Familiar", 14);
	Pizza *na = new Pizza("Napolitana", "Persona", 7);
	std::vector<Pedido *> p;
	for (int i = 0; i < 20; i++)
	{
		p.push_back(new Pedido);
	}
	for (auto i : p)
	{
		switch (rand() % 3)
		{
		case 0:
			i->addPizza(ma);
			break;
		case 1:
			i->addPizza(pe);
			break;
		case 2:
			i->addPizza(na);
			break;
		default:
			break;
		}
		switch (rand() % 3)
		{
		case 0:
			c->add_pedido(i);
			break;
		case 1:
			d->add_pedido(i);
			break;
		case 2:
			e->add_pedido(i);
			break;
		default:
			break;
		}
	}
	std::vector<Cliente *> l = {c, d, e};
	print(l);
	for (auto i : l)
	{
		delete i;
	}
	for (auto i : p)
	{
		delete i;
	}

	delete ma;
	delete pe;
	delete na;

	return 0;
}