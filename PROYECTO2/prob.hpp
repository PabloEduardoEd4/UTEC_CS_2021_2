#ifndef PROB
#define PROB

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <algorithm>

// El core del programa mismo. Usando probabilidades y inputs del deepred_blue,
// puede calcular la mejor posicion, actualizando y recalculando con cada input.
// Hay partes deo

class ProbGrid
{
private:
    bool dep, _out, only_torp = false;
    float max;
    float grid[10][10];
    const float _prob[10] = {2.82, 4.07, 5.07, 5.63, 5.92, 5.92, 5.63, 5.07, 4.07, 2.82};

    std::vector<float> accumalated_prob;

    void print(int range_x = 10, int range_y = 10)
    {
        std::cout << std::endl;
        for (int i = 0; i < range_y; i++)
        {
            for (int j = 0; j < range_x; j++)
                std::cout << std::fixed << std::setprecision(2) << grid[i][j] << '\t';
            std::cout << std::endl;
        }
    }

    void update_accumalted_prob()
    {
        accumalated_prob.clear();
        accumalated_prob.push_back(grid[0][0]);
        for (int i = 1; i < 100; ++i)
            accumalated_prob.push_back(accumalated_prob.at(i - 1) + grid[i / 10][i % 10]);
        max = accumalated_prob.at(99);
    }

    void fill(int x_1, int x_2, int y_1, int y_2, float factor = .1)
    {
        for (int i = x_1; i <= x_2; i++)
            for (int j = y_1; j <= y_2; j++)
            {
                if (grid[i][j] != 0 && grid[i][j] > _prob[i] * _prob[j])
                    grid[i][j] = _prob[i] * _prob[j];
                grid[i][j] *= factor;
            }
        if (_out)
        {
            std::cout << "Fill" << std::endl;
            print();
        }
    }

    int *dest_range(int x, int y)
    {
        static int dest[4];
        dest[0] = x;
        dest[1] = y;
        dest[2] = x;
        dest[3] = y;
        while (dest[0] != 0 && grid[dest[0] - 1][y] == 0 && grid[dest[0] - 1][y] < 5)
            dest[0] -= 1;
        while (dest[2] != 9 && grid[dest[2] + 1][y] == 0 && grid[dest[2] + 1][y] < 5)
            dest[2] += 1;
        while (dest[1] != 0 && grid[x][dest[1] - 1] == 0 && grid[x][dest[1] - 1] < 5)
            dest[1] -= 1;
        while (dest[3] != 9 && grid[x][dest[3] + 1] == 0 && grid[x][dest[3] - 1] < 5)
            dest[3] += 1;
        if (dest[0] != 0)
            dest[0] -= 1;
        if (dest[2] != 9)
            dest[2] += 1;
        if (dest[1] != 0)
            dest[1] -= 1;
        if (dest[3] != 9)
            dest[3] += 1;
        return dest;
    }

    void reset(bool ignore = false)
    {
        if (!only_torp)
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (grid[i][j] != 0 && (ignore || grid[i][j] < 100))
                        grid[i][j] = dep ? (_prob[i] * _prob[j]) : .1;
                    dep = !dep;
                }
                dep = !dep;
            }
        else
            for (int i = 0; i < 10; i++)
                for (int j = 0; j < 10; j++)
                    if (grid[i][j] != 0)
                        grid[i][j] = 1;
    }

    void intialize()
    {
        srand(time(nullptr));
        dep = (rand() % 2);
        reset(true);
        update_accumalted_prob();
        if (_out)
            print();
    }

    void set_zero(int x, int y)
    {
        grid[x][y] = 0;
    }

    void increase(int x, int y, float add = 0, float increase = 100000)
    {
        if (grid[x][y] != 0)
        {
            if (grid[x][y] < 50)
                grid[x][y] = _prob[x] * _prob[y];
            grid[x][y] = grid[x][y] * increase + add;
        }
    }
    void decrease(int x, int y, float decr = 0.9)
    {
        grid[x][y] *= decr;
    }

    void range_decrease(int x, int y, float decr = 0.9)
    {
        for (int i = 0; i < 10; i++)
            grid[x][i] *= decr;
        for (int i = 0; i < 10; i++)
            grid[i][y] *= decr;
    }

    void comulative_print()
    {
        for (auto i : accumalated_prob)
            std::cout << i << ' ';
        std::cout << std::endl;
    }

    void _hit(int x, int y)
    {
        if (x != 0)
            increase(x - 1, y, grid[x][y]);
        if (x != 9)
            increase(x + 1, y, grid[x][y]);
        if (y != 0)
            increase(x, y - 1, grid[x][y]);
        if (y != 9)
            increase(x, y + 1, grid[x][y]);
        /*
        if (x < 9 && y < 9)
            decrease(x + 1, y + 1, 0.01);
        if (0 < x && y < 9)
            decrease(x - 1, y + 1, 0.01);
        if (x < 9 && 0 < y)
            decrease(x + 1, y - 1, 0.01);
        if (0 < x && 0 < y)
            decrease(x - 1, y - 1, 0.01);
        */
    }

    void _miss(int x, int y)
    {
        if (x != 0)
            decrease(x - 1, y);
        if (x != 9)
            decrease(x + 1, y);
        if (y != 0)
            decrease(x, y - 1);
        if (y != 9)
            decrease(x, y + 1);
        /*
        if (x < 9 && y < 9)
            increase(x + 1, y + 1, 1.1);
        if (0 < x && y < 9)
            increase(x - 1, y + 1, 1.1);
        if (x < 9 && 0 < y)
            increase(x + 1, y - 1, 1.1);
        if (0 < x && 0 < y)
            increase(x - 1, y - 1, 1.1);
        */
    }

public:
    ProbGrid(bool out = false) : _out(false)
    {
        intialize();
    }
    void hit(int x, int y)
    {
        _hit(x, y);
        set_zero(x, y);
        update_accumalted_prob();
    }
    void miss(int x, int y)
    {
        set_zero(x, y);
        //_miss(x, y);
        range_decrease(x, y);
        update_accumalted_prob();
    }
    void destroyed(int x, int y)
    {
        set_zero(x, y);
        const int *t = dest_range(x, y);
        reset();
        fill(t[0], t[2], t[1], t[3]);
        update_accumalted_prob();
    }
    int *smart_select()
    {
        if (_out)
        {
            std::cout << "SMARTMODE" << std::endl;
            print();
            comulative_print();
        }
        static int dirt[2];
        float r = (rand() % int(max * 100 + 1) + 1) / 100.0;
        update_accumalted_prob();
        auto const it = std::lower_bound(accumalated_prob.begin(), accumalated_prob.end(), r);
        int index = std::distance(accumalated_prob.begin(), it);
        dirt[0] = index / 10;
        dirt[1] = index % 10;
        return dirt;
    }

    int *dumb_select()
    {
        if (_out)
        {
            std::cout << "DUMBMODE" << std::endl;
        }
        int x, y;
        static int dirt[2];
        do
        {
            x = rand() % 10;
            y = rand() % 10;
        } while (grid[x][y] == 0);
        dirt[0] = x;
        dirt[1] = y;
        return dirt;
    }
    void only_torpedo()
    {
        only_torp = true;
        reset();
    }
};

/*

void print(int array[][10], int range_x = 10, int range_y = 10)
{
    std::cout << std::endl;
    for (int i = 0; i < range_y; i++)
    {
        for (int j = 0; j < range_x; j++)

            std::cout << std::setw(2) << std::setfill('0') << array[i][j] / 10 << '.' << array[i][j] % 10 << ' ';
        std::cout << std::endl;
    }
}

void decrease(int prob[10][10], int ratio)
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            prob[i][j] = (prob[i][j] * ratio) / 1000;
}

void failed(int prob[10][10], char hits[10][10], int x, int y, int event)
{
    int skip;
    //DECRESE PROB OF ROW AND COLUM
}

void damaged(int prob[10][10], int x, int y, int event)
{
    prob[y + 1][x] = prob[y + 1][x] == 1 ? 207 : (prob[y + 1][x] * 207) / 1000;
    prob[y - 1][x] = prob[y - 1][x] == 1 ? 207 : (prob[y - 1][x] * 207) / 1000;
    prob[y][x + 1] = prob[y][x + 1] == 1 ? 207 : (prob[y][x + 1] * 207) / 1000;
    prob[y][x - 1] = prob[y][x + 1] == 1 ? 207 : (prob[y][x - 1] * 207) / 1000;
}

void destroyed(int prob[10][10], char hits[10][10], int x, int y, int event)
{
    int dep = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            if (prob[i][j] != 0)
                prob[i][j] = dep ? (_prob[i] * _prob[j]) / 1000 : 1, dep = !dep;
        dep = !dep;
    }
}

//3 types of events 0 FAILED; 1 DAMAGED; 2 DESTROYED;

void update(int prob[10][10], int x, int y, int event = 0, char hits[10][10] = {})
{
    prob[y][x] = 0;
    switch (event)
    {
    case 0:
        failed(prob, hits, x, y, event);
        break;
    case 1:
        damaged(prob, x, y, event);
        break;
    case 3:
        destroyed(prob, hits, x, y, event);
        break;
    default:
        break;
    }
}

void test(int prob)
{
    int x;
    int c;
    srand(time(nullptr));
    do
    {
        x = (rand()) % 1000 + 1;
        c++;
    } while (x > prob);
    std::cout << c << std::endl;
}

void probability_chart(int array[10][10])
{
    int dep = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            array[i][j] = dep ? (_prob[i] * _prob[j]) / 1000 : 1, dep = !dep;
        dep = !dep;
    }
    print(array);
    update(array, 5, 5, 1);
    print(array);
    update(array, 6, 5, 1);
    print(array);
    update(array, 7, 7, 2);
    print(array);
}
*/
#endif