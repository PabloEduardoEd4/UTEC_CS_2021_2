#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>

class Cliente
{
private:
	std::string ruc;
	std::string nombre;
	std::string dirrecion;

public:
	Cliente(std::string ruc, std::string nombre, std::string dirrecion) : ruc(ruc), nombre(nombre), dirrecion(dirrecion) {}
	void print()
	{
		std::cout << " RUC: " << ruc << " Nombre: " << nombre << " Dirrecion: " << dirrecion << std::endl;
	}
};

class Producto
{
private:
	std::string codigo;
	std::string description;
	float precio;
	int stock;

public:
	Producto(std::string codigo, std::string description, float precio, int stock) : codigo(codigo), description(description), precio(precio), stock(stock) {}
	void print()
	{
		std::cout << "Codigo: " << codigo << " Description: " << description << " Precio ($): " << precio << " Stock: " << stock << std::endl;
	}
};

class ItemFactura
{
private:
	int cantidad;
	Producto *producto;

public:
	ItemFactura(int cantidad, Producto *producto) : cantidad(cantidad), producto(producto) {}
	void print()
	{
		std::cout << " Cantidad: " << cantidad << ' ';
		producto->print();
	}
};

class Factura
{
private:
	std::string serie;
	std::string correlativo;
	Cliente *Clien;
	std::vector<ItemFactura *> item;

public:
	Factura(std::string serie, std::string correlativo, Cliente *Clien) : serie(serie), correlativo(correlativo), Clien(Clien) {}
	void registrar(ItemFactura *a) { item.push_back(a); }
	void print()
	{
		std::cout << "Serie: " << serie << " Correlativo: " << correlativo << '\n';
		for (auto i : item)
			i->print();
		Clien->print();
		std::cout << std::endl;
	}
};

template <typename T>
class Adm
{
private:
	std::vector<T *> lista;

public:
	void print()
	{
		int counter = 0;
		for (auto i : lista)
			std::cout << '[' << counter << ']', i->print(), counter++;
	}
	void registrar(T *item) { lista.push_back(item); }
	void eliminar(T *item) { lista.erase(std::find(item)); }
	int buscar(T *item) { std::distance(lista.begin(), std::find(item)); }
	int size() { return lista.size(); };
	T *buscar(int index)
	{
		return lista.at(index);
	}
};

class AdmClientes : public Adm<Cliente>
{
};

class AdmProductos : public Adm<Producto>
{
};

class AdmFacturas : public Adm<Factura>
{
};

class Sistema
{
private:
	AdmFacturas *_AdmFacturas = new AdmFacturas;
	AdmProductos *_AdmProductos = new AdmProductos;
	AdmClientes *_AdmClientes = new AdmClientes;

	template <typename T>
	void print(T *a)
	{
		a->print();
	}

	void adregarCliente()
	{
		std::string ruc, nombre, dirrecion;
		std::cout << "RUC: ";
		std::cin >> ruc;
		std::cout << "Nombre: ";
		std::cin >> nombre;
		std::cout << "Dirrecion: ";
		std::cin >> dirrecion;
		_AdmClientes->registrar(new Cliente(ruc, nombre, dirrecion));
	}

	void adregarProducto()
	{
		int stock;
		float precio;
		std::string codigo, descripcion;
		std::cout << "Codigo: ";
		std::cin >> codigo;
		std::cout << "Descripcion: ";
		std::cin >> descripcion;
		std::cout << "Precio: ";
		std::cin >> precio;
		std::cout << "Stock: ";
		std::cin >> stock;
		_AdmProductos->registrar(new Producto(codigo, descripcion, precio, stock));
	}

	void adregarFactura()
	{
		std::string serie, correlativo;
		std::cout << "Serie: ";
		std::cin >> serie;
		std::cout << "Correlativo: ";
		std::cin >> correlativo;
		Factura *h = new Factura(serie, correlativo, _AdmClientes->buscar(select(_AdmClientes)));
		int loops;
		std::cout << "Cuantos items Para factura? ";
		std::cin >> loops;
		for (int i = 0; i < loops; i++)
		{
			int cantidad = 0;
			int s = select(_AdmProductos);
			std::cout << "Cuantos De Producto";
			std::cin >> cantidad;
			h->registrar(new ItemFactura(cantidad, _AdmProductos->buscar(s)));
		}
		_AdmFacturas->registrar(h);
	}

	template <typename T>
	int select(Adm<T> *a)
	{
		int option = 0;
		do
		{
			a->print();
			std::cin >> option;
		} while (option < 0 || option > a->size());
		return option;
	};
	int option()
	{
		int option = 0;
		do
		{
			std::cout << "Menu:" << std::endl;
			std::cout << "[1] Imprimir Clientes" << std::endl;
			std::cout << "[2] Imprimir Productos" << std::endl;
			std::cout << "[3] Imprimir Facturas" << std::endl;
			std::cout << "[4] Adregar Cliente" << std::endl;
			std::cout << "[5] Adregar Producto" << std::endl;
			std::cout << "[6] Adregar Factura" << std::endl;
			std::cout << "[7] Exit" << std::endl;
			std::cout << ">>";
			std::cin >> option;
		} while (option < 0 || option > 8);
		return option;
	}

public:
	void mostrarMenu()
	{
		while (true)
		{
			int select = option();
			switch (select)
			{
			case 1:
				std::cout << "Clientes: " << std::endl;
				print(_AdmClientes);
				break;
			case 2:
				std::cout << "Productos: " << std::endl;
				print(_AdmProductos);
				break;
			case 3:
				std::cout << "Facturas: " << std::endl;
				print(_AdmFacturas);
				break;
			case 4:
				adregarCliente();
				break;
			case 5:
				adregarProducto();
				break;
			case 6:
				adregarFactura();
				break;
			case 7:
				return;
				break;
			default:
				break;
			}
		}
	}
	void registrarFactura(Factura *item) { _AdmFacturas->registrar(item); }
	void registrarProducto(Producto *item) { _AdmProductos->registrar(item); }
	void registrarCliente(Cliente *item) { _AdmClientes->registrar(item); }

	~Sistema() { delete _AdmFacturas, _AdmProductos, _AdmClientes; }
};

int main(int argc, char *argv[])
{
	std::string name[] = {"Paolo", "Pedro", "Javier", "Samantha", "Lorenzo"};
	Sistema *sis = new Sistema();
	sis->registrarProducto(new Producto("AKSDK", "Manzana", 1.20, 123));
	sis->registrarProducto(new Producto("VVV", "Naranja", 0.98, 20));
	sis->registrarProducto(new Producto("KK", "Naranja", 1.70, 30));
	for (int i = 0; i < 5; i++)
	{
		sis->registrarCliente(new Cliente("A", name[i], "Ksja 12 12019"));
	}

	sis->mostrarMenu();

	delete sis;

	sis = nullptr;
}