#include <iostream>
using namespace std;

class Persona
{
private:
    string nombre = " ";

protected:
    int edad = 0;

public:
    Persona() {}
    Persona(string n, int e) : nombre(n), edad(e) {}

    string get_nombre() { return nombre; }
    int get_edad() { return edad; }
    virtual ~Persona() { cout << "Persona borrada" << endl; }
};

class Cientifico : public Persona
{
private:
    string doctorado;

public:
    Cientifico() {}
    Cientifico(string n, int e, string d) : Persona(n, e), doctorado(d) {}

    string get_doctorado() { return doctorado; }

    virtual ~Cientifico() { cout << "Cientifico borrado" << endl; }
};

class Ingeniero : public Persona
{
private:
    string titulo = " ";

public:
    Ingeniero() {}
    Ingeniero(string n, int e, string t) : Persona(n, e), titulo(t) {}

    string get_titulo() { return titulo; }

    virtual ~Ingeniero() { cout << "Ingeniero borrado" << endl; }
};

int main()
{
    auto *Jose = new Persona("Jose", 30);
    cout << " Objeto Persona creado, de nombre " << Jose->get_nombre() << " y edad " << Jose->get_edad() << endl;
    auto *Sagan = new Cientifico("Carl Sagan", 50, "Astrofisico");
    cout << " Objeto Cientifico creado, de nombre " << Sagan->get_nombre() << ", edad " << Sagan->get_edad() << ", y doctorado como " << Sagan->get_doctorado() << endl;
    auto *Taylor = new Ingeniero("Frederick Taylor", 60, "Ingeniero Industrial");
    cout << " Objeto Ingeniero creado, de nombre " << Taylor->get_nombre() << ", edad " << Taylor->get_edad() << ", y titulo de " << Taylor->get_titulo() << endl;

    Persona *Carl = Sagan;

    delete Jose;
    delete Sagan;
    delete Taylor;

    cout << Carl->get_nombre() << std::endl;
    delete Carl;
}
