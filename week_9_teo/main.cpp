#include <iostream>
#include <vector>

class test
{
private:
	int number = 0;

public:
	test(int _number) : number(_number) {}
	void printNumber()
	{
		std::cout << number << std::endl;
	}
};

int main(int argc, char *argv[])
{
	std::vector<test> a;
	test A(1);
	test B(2);
	test C(3);
	a.push_back(A);
	a.push_back(B);
	a.push_back(C);
	for (auto i = a.begin(); i < a.end(); ++i)
	{
		i->printNumber();
		(*i).printNumber();
	}
	std::cout << std::endl;
	for (auto i : a)
	{
		i.printNumber();
	}
}