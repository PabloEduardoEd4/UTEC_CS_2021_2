#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

class Posulante
{
private:
	std::ofstream *file;

protected:
	char facultad;
	std::string dni;
	std::string nombreCompleto;
	int lectura;
	int redaccion;
	int matematica;
	std::string filename;

public:
	Posulante(char facultad, std::string dni, std::string nombreCompleto, int lectura,
			  int redaccion, int matematica)
		: facultad(facultad), dni(dni), nombreCompleto(nombreCompleto), lectura(lectura), redaccion(redaccion), matematica(matematica) {}

	virtual float calificacion() = 0;

	char getLetter() { return facultad; }

	std::string to_file()
	{
		return facultad + "," + dni + "," + nombreCompleto + ',' + std::to_string(calificacion()) + ",\n";
	}

	virtual ~Posulante()
	{
		facultad = 0;
		dni = "";
		nombreCompleto = "";
		lectura = 0;
		redaccion = 0;
		matematica = 0;
	}
};

class PostulanteCiecias : public Posulante
{
public:
	PostulanteCiecias(std::string dni, std::string nombreCompleto, int lectura,
					  int redaccion, int matematica)
		: Posulante('C', dni, nombreCompleto, lectura, redaccion, matematica)
	{
	}
	float calificacion() override
	{
		return 7.5 * (lectura + redaccion) + 10 * matematica;
	}
};

class PostulanteLetras : public Posulante
{
public:
	PostulanteLetras(std::string dni, std::string nombreCompleto, int lectura,
					 int redaccion, int matematica)
		: Posulante('L', dni, nombreCompleto, lectura, redaccion, matematica)
	{
	}
	float calificacion() override
	{
		return 10 * (lectura + redaccion) + 7.5 * matematica;
	}
};

class Examen
{
private:
	std::vector<Posulante *> *postulantes = new std::vector<Posulante *>;

	std::vector<std::string> csv_toclass(std::string nombreDeArchivo)
	{
		std::ifstream *in = new std::ifstream(nombreDeArchivo);
		std::string *line = new std::string;
		std::vector<std::string> v;

		if (in->is_open())
		{
			while (getline(*in, *line))
			{
				v.push_back(*line);
			}
		}
		delete in;
		delete line;
		return v;
	}

	std::vector<std::string> string_to_data(std::string a)
	{
		std::vector<std::string> temp;
		while (a.size() != 0)
		{
			temp.push_back(a.substr(0, a.find(',')));
			a.erase(0, a.find(',') + 1);
		}
		return temp;
	}

	void vect_to_class(std::vector<std::string> v)
	{
		std::vector<std::string> l;
		for (auto i : v)
		{
			l = string_to_data(i);
			if (l.at(1) == "DNI")
				continue;
			if (l.at(0) == "C")
			{
				postulantes->push_back(new PostulanteCiecias(l.at(1), l.at(2), std::stoi(l.at(3)), std::stoi(l.at(4)), std::stoi(l.at(5))));
			}
			else if (l.at(0) == "L")
			{
				postulantes->push_back(new PostulanteLetras(l.at(1), l.at(2), std::stoi(l.at(3)), std::stoi(l.at(4)), std::stoi(l.at(5))));
			}
			else
			{
			}
		}
	}
	bool notamayor(Posulante *a, Posulante *b) { return (a->calificacion() > b->calificacion()); }

public:
	Examen(std::string nombreDeArchivo = "postulantes.csv") { vect_to_class(csv_toclass(nombreDeArchivo)); }

	// void ordenar()
	//{
	//	std::sort(postulantes->begin(), postulantes->end(), notamayor);
	//}
	void listaIngresantesCiencias(std::string name = "ciencias.csv")
	{
		std::ofstream a;
		a.open(name, std::ios::app);
		a << "Facultad,DNI,ApellidosyNombres,Calificacion\n";
		for (auto i : *postulantes)
		{
			if (i->getLetter() == 'C' && i->calificacion() >= 750)
				a << (i->to_file());
		}
		a.close();
	}
	void listaIngresantesLetras(std::string name = "letras.csv")
	{
		std::ofstream a;
		a.open(name, std::ios::app);
		a << "Facultad,DNI,ApellidosyNombres,Calificacion\n";
		for (auto i : *postulantes)
		{
			if (i->getLetter() == 'L' && i->calificacion() >= 750)
				a << (i->to_file());
		}
		a.close();
	}
	~Examen()
	{
		for (auto i : *postulantes)
		{
			delete i;
		}
		delete postulantes;
	}
};

void print(std::vector<std::string> v)
{
	for (auto i : v)
	{
		std::cout << i << std::endl;
	}
}

int main(int argc, char *argv[])
{
	Examen *n = new Examen();
	n->listaIngresantesCiencias();
	n->listaIngresantesLetras();
}