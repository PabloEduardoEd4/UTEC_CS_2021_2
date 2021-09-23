//For optimization look at
//https://en.wikibooks.org/wiki/Optimizing_C%2B%2B/Code_optimization/Faster_operations

#include <iostream>
#include <stdio.h>

#define M_LOG2E 1.44269504088896340736 // log2(e)

const long long FACTORIAL_LOOKUP[21] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800,
										479001600, 6227020800, 87178291200, 1307674368000, 20922789888000,
										355687428096000, 6402373705728000, 121645100408832000, 2432902008176640000};

template <typename T>
void print(T &a, char end = '\n')
{
	std::cout << a << end;
}

template <typename T>
char *input(T &a)
{
	char *temporary;
	std::cout << a;
	std::cin >> temporary;
	return temporary;
}

template <typename T, size_t N>
size_t ARRAYSIZE(T (&a)[N])
{
	return N;
}

double log2()
{
}

//A^B = LOG^-1 (LOG(A) * B)
//A^B = 1 << (LOG(A) * B)
double pow(double base, double power)
{

	return base;
}

//Quake III Arena Invers esqrt aprox
float Q_rsqrt(float number)
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y = number;
	i = *(long *)&y;		   // evil floating point bit level hacking
	i = 0x5f3759df - (i >> 1); // what the fuck?
	y = *(float *)&i;
	y = y * (threehalfs - (x2 * y * y)); // 1st iteration
	//	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed
	return y;
}

//factorial n * (1 * n-1)(2 * n-2)....(x * n-x)
long long fast_factorial(unsigned int value)
{
	long long factorial;
	unsigned int odd_even;

	value = value ? value : 1ll;				   // Comparison change
	odd_even = value & 1 ? 1 : value >> 1;		   // Even division or cancelation
	factorial = value * odd_even;				   // Pre-Loop multiplication
	for (unsigned int x = 1u; 2u * x < value; x++) // Shortened multiplication factortial
	{
		factorial *= x * (value - x); // (x * n-x)
	}
	return factorial;
}

// Return unsigned long long because any other type is
// too small for the the amount of bytes needed
long long factorial(unsigned int value)
{
	return FACTORIAL_LOOKUP[value]; //LOOKUP
}

bool IsPrime(int number)
{
	if (number == 2 || number == 3)
		return true; //Erases 2 and 3

	if (number <= 1 || !(number % 2) || !(number % 3))
		return false; //Erases Factors of 2 and 3

	// By doing past steps we erase
	// (6n, 6n+2, 6n+3, 6n+4)
	// So we only need (6n + 1, 6n - 1)
	for (int i = 5; i * i <= number; i += 6)
		if (!(number % i) || !(number % (2 + i)))
			return false;
	return true;
}

int main(int argc, char *argv[])
{
	for (int i = 0; i <= 1000000; i += 6)
	{
		if (IsPrime(i + 1))
			std::cout << (i + 1) << std::endl;
		if (IsPrime((i + 5)))
			std::cout << (i + 5) << std::endl;
	}
	return 0;
}