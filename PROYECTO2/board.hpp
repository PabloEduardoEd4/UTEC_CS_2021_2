#ifndef BOARD
#define BOARD

class Board
{
private:
    char *array;
    int size_x;
    int size_y;

public:
    Board(int size_x, int size_y) : size_x(size_x), size_y(size_y), array(new char[size_x * size_y]) {}
    char at(int x, int y) { return array[x * size_y + y]; }
    char set(int x, int y, char val) { array[x * size_y + y] = val; }
    void fill(int x_1, int x_2, int y_1, int y_2, char val)
    {
        for (int i = x_1; i <= x_2; i++)
            for (int j = y_1; j <= y_2; j++)
                set(i, j, val);
    }
    ~Board()
    {
        delete array;
    }
};

#endif