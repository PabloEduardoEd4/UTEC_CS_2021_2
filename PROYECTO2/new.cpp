#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <vector>

/*
int main()
{
    std::vector<std::string> DataArray;
    std::ifstream qfile("test.txt");
    std::copy(std::istream_iterator<std::string>(qfile),
              std::istream_iterator<std::string>(),
              std::back_inserter(DataArray));
    std::cout << DataArray.size() << std::endl;
    for (auto i : DataArray)
        std::cout << i << std::endl;
}
*/