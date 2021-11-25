#include <iostream>

#include <vector>
#include <ctime>

class Estrella
{
private:
	int peso;
	float radio;

public:
	Estrella(int _peso, float _radio) : peso(_peso), radio(_radio){};
	float getPeso() { return peso; }
	void setPeso(int _peso) { peso = _peso; }
	float getRadio() { return radio; }
	void setRadio(float _radio) { radio = _radio; }
};

Estrella *collision(Estrella *A, Estrella *B)
{
	if (A->getPeso() > B->getPeso())
	{
		A->setPeso(A->getPeso() + B->getPeso());
		A->setRadio(A->getRadio() * 2);
		return A;
	}
	else
	{
		B->setPeso(A->getPeso() + B->getPeso());
		B->setRadio(B->getRadio() * 2);
		return B;
	}
}

/*
Estrella A, 1 M⊙ , 0.5 R⊙ 

Estrella B, 2 M⊙ , 1 R⊙ 

Estrella C, 10 M⊙ , 5 R⊙ 

Estrella D, 3 M⊙ , 1.5 R⊙ 
*/
float volume(Estrella *A)
{
	float r = A->getRadio();
	return (4 / 3) * 3.14159265359 * r * r * r;
}

void ej_1()
{
	Estrella A = Estrella(1, 0.5);
	Estrella B = Estrella(2, 1);
	Estrella C = Estrella(10, 5);
	Estrella D = Estrella(3, 1.5);
	Estrella *S1 = collision(&A, &B);
	Estrella *S2 = collision(&C, &D);
	Estrella *S3 = collision(S1, S2);
	std::cout << "Peso: " << S3->getPeso() << '\n'
			  << "Radio: " << S3->getRadio() << '\n'
			  << "Volumen: " << volume(S3) << std::endl;
}

void setup()
{
	srand(std::time(nullptr));
}

void generate(std::vector<Estrella> &grupo, int size = 10)
{
	for (int i = 0; i < size; i++)
	{
		grupo.push_back(Estrella(rand() % 10 + 1, rand() % 10 + 1));
	}
	return;
}

int randomSelect(std::vector<Estrella> &grupo)
{
	return rand() % grupo.size();
}

void del(std::vector<Estrella> &grupo, int index)
{
	if (index < grupo.size())
		grupo.erase(std::next(grupo.begin(), index));
}

void print(std::vector<Estrella> &grupo)
{
	for (auto i : grupo)
	{
		std::cout << "Peso: " << i.getPeso() << '\n'
				  << "Radio: " << i.getRadio() << '\n'
				  << "Volumen: " << volume(&i) << '\n'
				  << std::endl;
	}
}

bool check(std::vector<Estrella> &grupo_A, std::vector<Estrella> &grupo_B)
{
	int max_A = 0, min_A = 255, max_B = 0, min_B = 255;
	for (auto i : grupo_A)
	{
		if (i.getPeso() > max_A)
			max_A = i.getPeso();
		if (i.getPeso() < min_A)
			min_A = i.getPeso();
	}
	for (auto i : grupo_B)
	{
		if (i.getPeso() > max_B)
			max_B = i.getPeso();
		if (i.getPeso() < min_B)
			min_B = i.getPeso();
	}
	return min_A <= (max_B / 2) || min_B <= (max_A / 2);
}

void loop(std::vector<Estrella> &grupo_A, std::vector<Estrella> &grupo_B)
{
	int a, b;
	do
	{
		a = randomSelect(grupo_A);
		b = randomSelect(grupo_B);
		if (grupo_A.at(a).getPeso() >= 2 * grupo_B.at(b).getPeso() || grupo_B.at(b).getPeso() >= 2 * grupo_A.at(a).getPeso())
		{
			if (&grupo_A.at(a) == collision(&(grupo_A.at(a)), &(grupo_B.at(b))))
				del(grupo_B, b);
			else
				del(grupo_A, a);
		}
	} while (grupo_B.size() > 0 && grupo_A.size() > 0 && check(grupo_A, grupo_B));
}

void out(std::vector<Estrella> &grupo_A, std::vector<Estrella> &grupo_B)
{
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Grupo 1" << '\n'
			  << std::endl;
	print(grupo_A);
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Grupo 2" << '\n'
			  << std::endl;
	print(grupo_B);
}

int main(int argc, char *argv[])
{
	setup();
	std::vector<Estrella> grupo_A;
	std::vector<Estrella> grupo_B;
	generate(grupo_A);
	generate(grupo_B);
	loop(grupo_A, grupo_B);
	out(grupo_A, grupo_B);
	return 0;
}