#ifndef DEEPRED
#define DEEPRED

#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <time.h>
#include <stdexcept>
// #include <unistd.h> INCOMPATIBLE WITH WINDOWS
#include <windows.h>
#include "prob.hpp"
#include "board.hpp"
// Hace todo relacionado a los files
class Deep_red
{

private:
    std::string *buffer = new std::string();
    std::string *line = new std::string();
    std::ifstream *input = new std::ifstream();
    std::ofstream *output = new std::ofstream();

protected:
    const std::string name;
    std::vector<std::string> t_info;
    std::string info[2];

    int max_p(int a, int b)
    {
        return (a < b) ? b : a;
    }

    int min_p(int a, int b)
    {
        return (a < b) ? a : b;
    }

    bool write(std::string filename, std::string _s, bool overwrite = false, bool silent = false)
    {
        if (overwrite)
            output->open(filename, std::ios::out);
        else
            output->open(filename, std::ios::app);
        bool open = output->is_open();
        if (open)
        {
            if (!silent)
                std::cout << _s << std::endl;
            *output << _s << std::endl;
        }
        output->close();
        return open;
    }

    bool read(std::string filename, bool silent = false, bool del = true)
    {
        t_info.clear();
        input->open(filename, std::ios::in);
        bool open = input->is_open();
        if (open)
            while (std::getline(*input, *line))
            {
                if (!silent)
                    std::cout << *line << std::endl;
                t_info.push_back(*line);
            }
        input->close();
        if (del)
            remove(filename.c_str());
        return open;
    }

    bool get_info(std::string s, std::string div = "=")
    {
        info[0] = s.substr(0, s.find(div)), info[1] = s.substr(s.find(div) + 1);
        return true;
    }

    void pause()
    {
        std::cout << "Press and key and [ENTER] to continue:";
        std::cin >> *buffer;
    }

public:
    Deep_red(std::string _name) : name(_name) {}
    std::string get_name() { return name; }
    ~Deep_red()
    {
        delete buffer;
        delete input;
        delete output;
        delete line;
        buffer = nullptr;
        input = nullptr;
        output = nullptr;
        line = nullptr;
    }
};

// Se encarga del jeugo mismo
class Deepred_blue : public Deep_red
{
private:
    bool hit, destroyed;

    int _hit = 0, _miss = 0;
    int _y, _x, index = 0;

    int *t;

    int left[4] = {1, 2, 3, 4};
    int ranges[10][2][2] = {{{0, 0}, {0, 0}}, {{9, 9}, {9, 9}}, {{0, 9}, {0, 9}}, {{9, 0}, {9, 0}}, {{9, 2}, {9, 3}}, {{0, 3}, {0, 4}}, {{0, 6}, {0, 7}}, {{2, 9}, {4, 9}}, {{9, 5}, {9, 7}}, {{2, 0}, {5, 0}}};
    // int ranges[10][2][2] = {{{1, 1}, {1, 1}}, {{9, 9}, {9, 9}}, {{0, 9}, {0, 9}}, {{9, 0}, {9, 0}}, {{7, 2}, {7, 3}}, {{1, 3}, {1, 4}}, {{2, 6}, {2, 7}}, {{2, 8}, {4, 8}}, {{8, 5}, {8, 7}}, {{3, 0}, {6, 0}}};
    //  ABST
    const char l[4] = {'T', 'S', 'B', 'A'};

    const std::string win = "NOTIFICATION=YOU WIN!";
    const std::string lose = "NOTIFICATION=YOU LOSE";

    // in y out son relativos al program
    const std::string out;
    const std::string in;
    const std::string ex;

    std::string record;
    std::string token;

    std::vector<std::string> attacked_buffer;

    ProbGrid *prob = new ProbGrid();
    Board<char> *fleet = new Board<char>(10, 10, '-');
    Board<char> *hits = new Board<char>(10, 10, '-');

    int *dest_range(int x, int y, Board<char> *a)
    {
        static int dest[4];
        dest[0] = x, dest[1] = y, dest[2] = x, dest[3] = y;
        while (dest[0] != 0 && a->at(dest[0] - 1, y) == 'Y')
            dest[0] -= 1;
        while (dest[2] != 9 && a->at(dest[2] + 1, y) == 'Y')
            dest[2] += 1;
        while (dest[1] != 0 && a->at(x, dest[1] - 1) == 'Y')
            dest[1] -= 1;
        while (dest[3] != 9 && a->at(x, dest[3] + 1) == 'Y')
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

    void attack(int x, int y)
    {
        write(out, "TOKEN=" + token, true, true);
        write(out, "ATTACK=" + coor_to_string(x, y));
        write(record, "ATTACK=" + coor_to_string(x, y), false, true);
    }

    void attacked(std::string val, std::string state)
    {

        hit = !(state == "FAILED");
        destroyed = (state == "DESTROYED");
        int y = val[0] - 'A', x;
        if (val.size() >= 3 && val.substr(1, 3) == "10")
            x = 9;
        else
            x = val[1] - '0' - 1;
        std::cout << "Attacked: " << val << std::endl;
        std::cout << "Result: " << state << std::endl;
        // std::cout << "Hit?: " << hit << ' ' << ", Destroyed?: " << destroyed << std::endl;
        if (hit)
            fleet->set(x, y, 'Y');
        else
            ;
        // fleet->set(x, y, '.');
        if (destroyed)
        {
            t = dest_range(x, y, fleet);
            fleet->fill(t[0], t[2], t[1], t[3], 'X');
        }
        return;
    }

    char ship_type(int x_1, int x_2, int y_1, int y_2)
    {
        return l[max_p(abs(x_1 - x_2), abs(y_1 - y_2))];
    }

    std::string coor_to_string(int x, int y)
    {
        if ((x + 1) == 10)
            return {char(y + 'A'), '1', '0'};
        else
            return {char(y + 'A'), char((x + 1 + '0'))};
    }

    std::string voh(int x_1, int x_2, int y_1, int y_2)
    {
        return (abs(x_1 - x_2) > abs(y_1 - y_2)) ? "V" : "H";
    }

    void fill_ships(int ships = 0)
    {
        char add;
        for (int s = 0; s < ships; s++)
        {
            add = ship_type(ranges[s][0][0], ranges[s][1][0], ranges[s][0][1], ranges[s][1][1]);
            fleet->fill(ranges[s][0][0], ranges[s][1][0], ranges[s][0][1], ranges[s][1][1], add);
        }
    }

    void send_coords()
    {
        int x_1, x_2, y_1, y_2;
        std::string s;
        write(out, "TOKEN=" + token, true);
        for (int i = 0; i < 10; i++)
        {
            x_1 = ranges[i][0][0];
            x_2 = ranges[i][1][0];
            y_1 = ranges[i][0][1];
            y_2 = ranges[i][1][1];
            s = "PLACE_FLEET=" + std::string({ship_type(x_1, x_2, y_1, y_2)}) + "-" + coor_to_string(ranges[i][0][0], ranges[i][0][1]) + "-" + std::string({voh(ranges[i][0][0], ranges[i][1][0], ranges[i][0][1], ranges[i][1][1])});
            write(out, s);
        }
    }

    bool standby(std::string filename, bool silent = false, bool count = false)
    {
        int counter = 0;
        do
        {
            read(in, true, false);
            if (t_info.size() != 0 && (t_info.at(1) == win || t_info.at(1) == lose))
                break;
            Sleep(900);
            read(filename, silent);
            if (count)
                counter++;
        } while (t_info.size() == 0 && counter <= 10);
        return (counter <= 10);
    }

    void handshake()
    {
        /*
        do
        {
            write(out, "HANDSHAKE=" + name);
        } while (standby(in, false, true));
        */
        write(out, "HANDSHAKE=" + name);
        standby(in, false);
        get_info(t_info.at(0));
        if (info[1] != "ACCEPTED")
            throw std::invalid_argument("Handshake denied");
        get_info(t_info.at(1));
        token = info[1];
        record = "Moves_Record_" + token;
        std::cout << "Hand Shake Complete" << std::endl;
        // std::cout << token;
    }

    bool combat()
    {

        if (left[0] + left[1] + left[2] == 0)
            prob->only_torpedo();
        int *select = prob->smart_select();
        std::cout << "A: " << left[0] << " B: " << left[1]
                  << " S: " << left[2] << " T: " << left[3] << std::endl;
        _x = select[0];
        _y = select[1];
        // std::cout << x << ' ' << y << std::endl;
        do
        {
            attack(_x, _y);
        } while (!standby(in, false, true));
        write(record, t_info.at(1), false, true);
        get_info(t_info.at(1));
        if (info[1] == "YOU WIN!")
        {
            hits->set(_x, _y, 'X');
            _hit++;
            return true;
        }
        if (info[1] == "FAILED")
        {
            hits->set(_x, _y, '.');
            prob->miss(_x, _y);
            _miss++;
        }
        else if (info[1] == "DAMAGED")
        {
            hits->set(_x, _y, 'Y');
            prob->hit(_x, _y);
            _hit++;
        }
        else if (info[1] == "DESTROYED")
        {
            hits->set(_x, _y, 'Y');
            t = dest_range(_x, _y, hits);
            remove_ship(ship_type(t[0], t[2], t[1], t[3]));
            hits->fill(t[0], t[2], t[1], t[3], 'X');
            prob->destroyed(_x, _y);
            _hit++;
        }
        // print(hits, "Enemies Board");
        return (info[1] == "DESTROYED" || info[1] == "DAMAGED");
    }

    int run()
    {
        int counter;
        int s, e;
        std::string a;
        for (counter = 0; counter < 101; counter++)
        {
            read(in, true, false);
            if (t_info.size() != 0 && get_info(t_info.at(1)) && (info[1] == "YOU WIN!" || info[1] == "YOU LOSE"))
            {
                std::cout << info[1] << std::endl;
                break;
            }
            do
            {
                if (standby(ex, true, true))
                    if (t_info.at(1).find("ATTACK") != std::string::npos)
                        attacked_buffer.push_back(t_info.at(1));
                    else
                        ;
                else
                    attack(_x, _y);
            } while (t_info.size() == 0 || (t_info.at(1) != "NOTIFICATION=YOUR TURN" && t_info.at(1) != "NOTIFICATION=YOU LOSE"));
            for (auto i : attacked_buffer)
            {
                s = i.find('=') + 1;
                e = i.find('-');
                attacked(i.substr(i.find('=') + 1, e - s), i.substr(i.find('-') + 1));
            }
            get_info(t_info.at(1));
            if (info[1] == "YOU WIN!" || info[1] == "YOU LOSE")
            {
                s = attacked_buffer.back().find('=') + 1;
                e = attacked_buffer.back().find('-');
                a = attacked_buffer.back().substr(attacked_buffer.back().find('=') + 1, e - s);
                int y = a[0] - 'A', x;
                if (a.size() >= 3 && a.substr(1, 3) == "10")
                    x = 9;
                else
                    x = a[1] - '0' - 1;
                t;
                fleet->set(x, y, 'X');
                std::cout
                    << info[1] << std::endl;
                return counter;
            }
            attacked_buffer.clear();
            std::cout << "Shot  #" << counter << std::endl;
            if (t_info.at(1) != "NOTIFICATION=WAIT FOR YOUR TURN")
                combat();
            else
            {
                counter -= 1;
                continue;
            }
            get_info(t_info.at(1));
            if (info[1] == "YOU WIN!" || info[1] == "YOU LOSE")
                return counter;
            fleet->print("Your Board");
            hits->print("Enemy Board");
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
    }

public:
    Deepred_blue(std::string _name, std::string _in, std::string _out, std::string _ex) : Deep_red(_name), in(_in), out(_out), ex(_ex) { intialize(); }

    int start(bool ratio = false)
    {
        handshake();
        send_coords();
        fill_ships(10);
        fleet->print("Your Board");
        hits->print("Enemy Board");
        int turns = run();
        remove(in.c_str());
        remove(out.c_str());
        remove(ex.c_str());
        if (ratio)
            std::cout << "H/M " << _hit << ':' << _miss
                      << " ratio: " << float(_hit) / float(_miss + _hit)
                      << std::endl;
        return turns;
    }

    ~Deepred_blue()
    {
        delete prob;
        delete fleet;
        delete hits;
        prob = nullptr;
        fleet = nullptr;
        hits = nullptr;
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