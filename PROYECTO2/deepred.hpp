#ifndef DEEPRED
#define DEEPRED

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <unistd.h>
#include "prob.hpp"

// Hace todo relacionado a los files
class Deep_red
{
protected:
    // in y out son relativos al program
    std::string name;
    std::vector<std::string> t_info;
    std::string info[2];

    // codigo de min official
    template <class T>
    const T &min(const T &a, const T &b)
    {
        return !(b < a) ? a : b; // or: return !comp(b,a)?a:b; for version (2)
    }
    template <class T>
    const T &max(const T &a, const T &b)
    {
        return (a < b) ? b : a; // or: return comp(a,b)?b:a; for version (2)
    }
    bool write(std::string filename, std::string _s, bool overwrite = false, bool silent = false)
    {
        std::ofstream *output = new std::ofstream;
        if (overwrite)
            output->open(filename);
        else
            output->open(filename, std::fstream::app);
        if (output->is_open())
        {
            if (!silent)
                std::cout << _s << std::endl;
            *output << _s << std::endl;
        }
        else
        {
            output->close();
            delete output;
            return false;
        }
        output->close();
        delete output;
        return true;
    }

    bool read(std::string filename, bool silent = false, bool del = true)
    {
        std::string *line = new std::string();
        t_info.clear();
        std::ifstream *input = new std::ifstream;
        input->open(filename);
        if (!(input->is_open()))
        {
            input->close();
            delete input;
            delete line;
            return false;
        }
        while (std::getline(*input, *line))
        {
            if (!silent)
                std::cout << *line << std::endl;
            t_info.push_back(*line);
        }
        input->close();
        if (del)
            remove(filename.c_str());
        delete input;
        delete line;
        return true;
    }

    bool get_info(std::string s, std::string div = "=")
    {
        info[0] = s.substr(0, s.find(div));
        info[1] = s.substr(s.find(div) + 1);
        return true;
    }

    template <size_t A>
    void print(char array[][A], std::string extra = "No Name", int rows = 10)
    {

        std::cout << std::endl;
        std::cout << extra << std::endl;
        std::cout << "   ";
        for (int j = 0; j < rows; j++)
            std::cout << char(j + 'A') << ' ';
        std::cout << std::endl;
        for (int i = 0; i < rows; i++)
        {
            std::cout << std::setw(2) << std::setfill(' ') << (i + 1) << ' ';
            for (int j = 0; j < A; j++)
                std::cout << array[i][j] << ' ';
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void pause()
    {
        std::string *buffer = new std::string();
        std::cout << "Press and key and [ENTER] to continue:";
        std::cin >> *buffer;
        delete buffer;
    }

public:
    Deep_red(std::string _name) : name(_name) {}
    std::string get_name() { return name; }
    ~Deep_red() {}
};

class Deepred_blue : public Deep_red
{
private:
    int _hit = 0, _miss = 0;
    int y, x, index = 0;
    int left[4] = {1, 2, 3, 4};
    int ranges[10][2][2] = {{{0, 0}, {0, 0}}, {{9, 9}, {9, 9}}, {{0, 9}, {0, 9}}, {{9, 0}, {9, 0}}, {{9, 2}, {9, 3}}, {{0, 3}, {0, 4}}, {{0, 6}, {0, 7}}, {{2, 9}, {4, 9}}, {{9, 5}, {9, 7}}, {{2, 0}, {5, 0}}};
    // ABST
    const char l[4] = {'T', 'S', 'B', 'A'};
    char fleet[10][10];
    char hits[10][10];
    std::string out;
    std::string in;
    std::string ex;
    std::string token;
    std::vector<std::string> attacked_buffer;

    ProbGrid *prob = new ProbGrid();

    void _fill(int x_1, int x_2, int y_1, int y_2, char val)
    {
        for (int i = x_1; i <= x_2; i++)
            for (int j = y_1; j <= y_2; j++)
                fleet[i][j] = val;
    }
    void __fill(int x_1, int x_2, int y_1, int y_2, char val)
    {
        for (int i = x_1; i <= x_2; i++)
            for (int j = y_1; j <= y_2; j++)
                hits[i][j] = val;
    }

    void attack(int x, int y)
    {
        write(out, "TOKEN=" + token, true);
        write(out, "ATTACK=" + coor_to_string(x, y));
    }

    void attacked(std::string val, std::string state = "NULL")
    {
        bool hit, destroyed;
        std::cout << "Attacked: " << val << std::endl;
        hit = (state != "-FAILED");
        destroyed = (state == "-DESTROYED");
        y = val[0] - 'A';
        if (val.size() == 3 && val[3] == '0')
            x = 9;
        else
            x = val[1] - '0' - 1;
        std::cout << x << ' ' << y << ' ' << hit << std::endl;
        if (hit)
        {
            std::cout << "HIT" << std::endl;
            fleet[x][y] = 'Y';
        }
        else
        {
            std::cout << "MISS" << std::endl;
            fleet[x][y] = 'L';
        }
        if (destroyed)
        {
            int *t = dest_range(x, y);
            std::cout << t[0] << t[1] << t[2] << t[3] << std::endl;
            __fill(t[0], t[2], t[1], t[3], 'X');
        }
        // print(fleet, "Your Board");
    }

    char ship_type(int x_1, int x_2, int y_1, int y_2)
    {
        int x = abs(x_1 - x_2);
        int y = abs(y_1 - y_2);
        return l[max(x, y)];
    }

    std::string coor_to_string(int x, int y)
    {
        std::string p1;
        if ((x + 1) == 10)
            p1 = {char(y + 'A'), '1', '0'};
        else
            p1 = {char(y + 'A'), char((x + 1 + '0'))};
        return p1;
    }
    std::string voh(int x_1, int x_2, int y_1, int y_2)
    {
        int x = abs(x_1 - x_2);
        int y = abs(y_1 - y_2);
        return (x > y) ? "V" : "H";
    }

    void fill(int ships = 0)
    {
        char add;
        for (int s = 0; s < ships; s++)
        {
            add = ship_type(ranges[s][0][0], ranges[s][1][0], ranges[s][0][1], ranges[s][1][1]);
            _fill(ranges[s][0][0], ranges[s][1][0], ranges[s][0][1], ranges[s][1][1], add);
        }
    }

    void send_coords()
    {
        int x_1, x_2, y_1, y_2;
        write(out, "TOKEN=" + token, true);
        for (int i = 0; i < 10; i++)
        {
            x_1 = ranges[i][0][0];
            x_2 = ranges[i][1][0];
            y_1 = ranges[i][0][1];
            y_2 = ranges[i][1][1];
            std::string s = "PLACE_FLEET=" + std::string({ship_type(x_1, x_2, y_1, y_2)}) + "-" + coor_to_string(ranges[i][0][0], ranges[i][0][1]) + "-" + std::string({voh(ranges[i][0][0], ranges[i][1][0], ranges[i][0][1], ranges[i][1][1])});
            write(out, s);
        }
    }

    void handshake()
    {
        write(out, "HANDSHAKE=" + name);
        standby(in);
        get_info(t_info.at(0));
        if (info[1] != "ACCEPTED")
            throw std::invalid_argument("Handshake denied");
        get_info(t_info[1]);
        token = info[1];
        std::cout << "Hand Shake Complete" << std::endl;
        // std::cout << token;
    }

    void standby(std::string filename, bool silent = false)
    {

        do
        {
            read(in, true, false);
            if (t_info.size() != 0 && get_info(t_info.at(1)) && (info[1] == "YOU WIN!" || info[1] == "YOU LOSE"))
            {
                std::cout << t_info.at(1) << std::endl;
                break;
            }
            sleep(1);
            read(filename, silent);
        } while (t_info.size() == 0);
        return;
    }

    int *dest_range(int x, int y)
    {
        static int dest[4];
        dest[0] = x;
        dest[1] = y;
        dest[2] = x;
        dest[3] = y;
        while (dest[0] != 0 && hits[dest[0] - 1][y] == 'Y')
            dest[0] -= 1;
        while (dest[2] != 9 && hits[dest[2] + 1][y] == 'Y')
            dest[2] += 1;
        while (dest[1] != 0 && hits[x][dest[1] - 1] == 'Y')
            dest[1] -= 1;
        while (dest[3] != 9 && hits[x][dest[3] + 1] == 'Y')
            dest[3] += 1;
        return dest;
    }
    void remove_ship(char a)
    {
        int i;
        switch (a)
        {
        case 'A':
            i = 0;
            break;
        case 'B':
            i = 1;
            break;
        case 'S':
            i = 2;
            break;
        case 'T':
            i = 3;
            break;
        default:
            i = 0;
            break;
        }
        left[i] = left[i] - 1;
    }

    bool combat()
    {

        if (left[0] + left[1] + left[2] == 0)
            prob->only_torpedo();
        int *select = prob->smart_select();
        std::cout << "A: " << left[0] << " B: " << left[1] << " S: " << left[2] << " T: " << left[3] << std::endl;
        int x = select[0];
        int y = select[1];
        attack(x, y);
        standby(in);
        get_info(t_info.at(1));
        if (info[1] == "YOU WIN!")
            return true;
        if (info[1] == "FAILED")
        {
            hits[x][y] = 'L';
            prob->miss(x, y);
            _miss++;
        }
        else if (info[1] == "DAMAGED")
        {
            hits[x][y] = 'Y';
            prob->hit(x, y);
            _hit++;
        }
        else if (info[1] == "DESTROYED")
        {
            hits[x][y] = 'Y';
            int *t = dest_range(x, y);
            remove_ship(ship_type(t[0], t[2], t[1], t[3]));
            // std::cout << t[0] << t[1] << t[2] << t[3] << std::endl;
            __fill(t[0], t[2], t[1], t[3], 'X');
            prob->destroyed(x, y);
            _hit++;
        }
        // print(hits, "Enemies Board");
        return (info[1] == "DESTROYED" || info[1] == "DAMAGED");
    }

    int run()
    {
        int counter = 0;
        for (counter = 0; counter < 100; counter++)
        {
            read(in, true, false);
            if (t_info.size() != 0 && get_info(t_info.at(1)) && (info[1] == "YOU WIN!" || info[1] == "YOU LOSE"))
            {
                std::cout << info[1] << std::endl;
                break;
            }
            do
            {
                standby(ex, true);
                if (get_info(t_info.at(1)) && info[0] == "ATTACK")
                    attacked_buffer.push_back(info[1]);
                if (info[1] == "YOU WIN!" || info[1] == "YOU LOSE")
                    return counter;
            } while (!get_info(t_info.at(0)) || info[1] != token || !get_info(t_info.at(1)) || info[1] != "YOUR TURN");
            std::cout << "Shot  #" << counter << std::endl;
            for (auto i : attacked_buffer)
            {
                std::cout << i << std::endl;
                attacked(i.substr(0, i.find('-')), i.substr(i.find('-')));
            }
            attacked_buffer.clear();
            print(fleet, "Your Board");
            print(hits, "Enemy Board");
            combat();
            /*
            if (combat())
                counter -= 1;
            */
        }
        return counter;
        // NOTIFICATION=YOU WIN!
    }

    void intialize()
    {
        std::cout << "Infile: " << in << std::endl;
        remove(in.c_str());
        std::cout << "Outfile: " << out << std::endl;
        remove(out.c_str());
        std::cout << "Notfile: " << ex << std::endl;
        remove(ex.c_str());
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
            {
                fleet[i][j] = '-';
                hits[i][j] = '-';
            }
    }

public:
    Deepred_blue(std::string _name, std::string _in, std::string _out, std::string _ex) : Deep_red(_name), in(_in), out(_out), ex(_ex) { intialize(); }

    int start(bool ratio = false)
    {
        handshake();
        send_coords();
        fill(10);
        print(fleet, "Your Board");
        int turns = run();
        remove(in.c_str());
        remove(out.c_str());
        remove(ex.c_str());
        print(fleet, "Your Board");
        print(hits, "Enemy Board");
        if (ratio)
            std::cout << "H/M " << _hit << ':' << _miss << " ratio: " << float(_hit) / float(_miss + _hit) << std::endl;
        return turns;
    }

    ~Deepred_blue()
    {
        delete prob;
        prob = nullptr;
    }
};
#endif

/*
Aircfratf Carrier (A) → 4 casillas contiguas
Battlecrucier (B) → 3 casillas contiguas
Submarine (S) →  2 casillas contiguas
Torpedo boat (T) → 1 casilla
1 Aircfratf Carrier 4
2 Battlecruciers  6
3 Submarines  6
4 Torpedo boat 4
*/