#include <iostream>
#include <vector>

std::vector<char *> combination;
std::vector<char *> people;

void go(int offset, int k)
{
	if (k == 0)
	{
		return;
	}
	for (int i = offset; i <= sizeof(people) / sizeof(people[0]) - k; ++i)
	{
		combination.push_back(people[i]);
		go(i + 1, k - 1);
		combination.pop_back();
	}
}

char *combinations(char *n, int k)
{
	go(0, k);
	std::cout << combination[0][0];
	//char* a = &combination[0];
	//return a;
}

/*
std::vector<double> v;
double* a = &v[0];
*/

int main()
{
	char assci[2] = {'0', '1'};
	/*
	char* da =,'2','3','4',
					'5','6','7','8','9'
	*/
	combinations(assci, 2);
	std::cout << "ofdofjwo" << std::endl;
	//std::cout << da[0];
}