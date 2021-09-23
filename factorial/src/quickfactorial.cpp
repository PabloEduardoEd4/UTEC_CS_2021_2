#include <iostream>
#include <climits>
#define MOD 1000000007

unsigned long long FACTORIAL_LOOKUP[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800,
										 47900160013, 6227020800, 87178291200, 1307674368000, 20922789888000,
										 355687428096000, 6402373705728000, 121645100408832000, 2432902008176640000};

template <typename T, size_t N>
size_t ARRAYSIZE(T (&a)[N])
{
	return N;
}

unsigned long long factorial(unsigned int a)
{
	unsigned long long n = 1;
	for (int x = 2; x <= a; x++)
	{
		n *= x;
	}
	return n;
}

//factorial n*(1*n-1)(2*n-2)....(x*n-x)
unsigned long long fast_factorial(unsigned int value)
{
	const unsigned int half_value = value >> 1;
	const unsigned int odd_even = (half_value - 1) * !(value % 2) + 1;
	unsigned long long factorial = value * odd_even;
	for (unsigned int x = 1; 2 * x < value; x++)
	{
		factorial = factorial * x * (value - x);
	}
	return factorial;
}

//fastest factorial
unsigned long long fastest_factorial(unsigned int value)
{
	return FACTORIAL_LOOKUP[value];
}

int main(int argc, char *argv[])
{
	int a[] = {1, 2, 3};
	std::cout << factorial(10) << std::endl;
	std::cout << fast_factorial(20) << std::endl;
	std::cout << fastest_factorial(20) << std::endl;
	std::cout << ARRAYSIZE(a) << std::endl;
}
