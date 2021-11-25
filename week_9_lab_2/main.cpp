#include <iostream>
#include <vector>
#include <time.h>

std::vector<int> generate(int N)
{
	std::vector<int> out;
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		out.push_back(rand() % 100);
	}
	return out;
}

int sum(std::vector<int> V, int less_than = 100)
{
	int sum = 0;
	for (auto i : V)
	{
		if (i < less_than)
			sum += i;
	}
	return sum;
}

int average(std::vector<int> V)
{
	return (sum(V) / V.size());
}

std::vector<int> dif(std::vector<int> V)
{
	int avg = average(V);
	std::vector<int> out;
	for (auto i : V)
	{
		out.push_back(abs(i - avg));
	}
	return out;
}

int main(int argc, char *argv[])
{
	std::vector<int> a = generate(2);
	std::cout << a.at(0) << std::endl;
	std::cout << a.at(1) << std::endl;
	std::cout << sum(a, 2) << std::endl;
	std::cout << average(a) << std::endl;
	std::vector<int> b = dif(a);
	std::cout << b.at(0) << std::endl;
	std::cout << b.at(1) << std::endl;
}