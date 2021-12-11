#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char *argv[])
{
	std::string x, y, z;
	std::vector<std::string> v;

	std::ifstream *in = new std::ifstream();
	std::ofstream *out = new std::ofstream();

	in->open("in.txt", std::ios::in);
	out->open("out.txt", std::ios::out);
	//*in >> x >> y >> z;
	while (getline(*in, x, ','))
		v.push_back(x);
	for (auto i : v)
		std::cout << i << ' ';
	in->close();
	out->close();
	delete in;
	delete out;
	in = nullptr;
	out = nullptr;
}