#include <iostream>

bool IsPrime(int number)
{
	if (number == 2 || number == 3)
		return true;

	if (number <= 1 || !(number % 2) || !(number % 3))
		return false;

	for (int i = 5; i * i <= number; i += 1)
		if (!(number % i))
			return false;
	return true;
}

int main(int argc, char *argv[])
{
	int number, current;
	do
	{
		std::cout << "Input number [greater than 10]: " << std::endl;
		std::cin >> number;
	} while (number <= 10);

	current = number;

	std::cout << "Number is" << (IsPrime(current) ? " " : " not ") << "prime" << std::endl;
	do
	{
		current--;
	} while (!IsPrime(current));
	std::cout << "Prime below: " << current << std::endl;
	current = number;
	do
	{
		current++;
	} while (!IsPrime(current));
	std::cout << "Prime above: " << current << std::endl;
}