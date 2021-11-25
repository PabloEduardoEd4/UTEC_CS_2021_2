#include <iostream>
#include <cmath>

class Triangulo
{
private:
	std::string color;

	//Sides
	double a, b, c;

	//Angles
	double A, B, C;

	double semi_perimetro, perimetro, area;

	//C = arccos ( (a * a + b * b − c * c) / 2 * a * b )

public:
	Triangulo(double side_a, double side_b, double side_c, std::string set_color = "blanco")
	{
		a = side_a;
		b = side_b;
		c = side_c;
		color = set_color;

		A = std::acos((b * b + c * c - a * a) / 2 * b * c);
		B = std::acos((a * a + c * c - b * b) / 2 * a * c);
		C = std::acos((a * a + b * b - c * c) / 2 * a * b);

		semi_perimetro = (a + b + c) / 2;
		perimetro = a + b + c;
		area = 0.5 * b * c * std::sin(A);
	}
	void set_color(std::string new_color)
	{
		color = new_color;
	}
	std::string get_color()
	{
		return color;
	}

	double get_C()
	{
		return C;
	}
	double perimertro()
	{
		return perimetro;
	}
};

int main(int argc, char *argv[])
{
	Triangulo t = Triangulo(3, 4, 5);
	std::cout << t.get_C() << std::endl;
	return 0;
}