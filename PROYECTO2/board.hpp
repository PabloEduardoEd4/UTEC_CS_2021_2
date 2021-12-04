#ifndef BOARD
#define BOARD

#include <iostream>
#include <string>
#include <iomanip>
#include <unistd.h>

template <typename T>
class Board
{
private:
    T *array;
    int size_x;
    int size_y;
    void initialize(T empty)
    {
        for (int i = 0; i < size_x * size_y; i++)
            array[i] = empty;
    }

public:
    Board(int size_x, int size_y, T empty) : size_x(size_x), size_y(size_y), array(new T[size_x * size_y]) { initialize(empty); }
    char at(int x, int y) { return array[x * size_y + y]; }
    char set(int x, int y, char val) { array[x * size_y + y] = val; }
    void fill(int x_1, int x_2, int y_1, int y_2, T val)
    {
        for (int i = x_1; i <= x_2; i++)
            for (int j = y_1; j <= y_2; j++)
                array[i * size_y + j] = val;
    }
    void print(std::string extra = "No Name")
    {
        std::cout << std::endl;
        std::cout << extra << std::endl;
        std::cout << "   ";
        for (int j = 0; j < size_y; j++)
            std::cout << char(j + 'A') << ' ';
        std::cout << std::endl;
        for (int i = 0; i < size_x; i++)
        {
            std::cout << std::setw(2) << std::setfill(' ') << (i + 1) << ' ';
            for (int j = 0; j < size_y; j++)
                std::cout << array[i * size_y + j] << ' ';
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    ~Board()
    {
        delete array;
        array = nullptr;
    }
    /*
    template <typename T>
    T *operator[](int b)
    {

    }
    */
};

#endif