#include <iostream>
#include <string>
#include <cstdlib>
#include "deepred.hpp"

int main(int argc, char *argv[])
{
	std::string player;
	if (argc == 2)
		player = argv[1];
	else
		player = "FirstPlayer";
	std::cout << '(' << argc << ')' << "Start: " << player << std::endl;
	Deepred_blue *n = new Deepred_blue("DEEPRED", player + ".out", player + ".in", player + ".not");
	std::cout << n->start(true) << " shots" << std::endl;
	std::system("pause");
	delete n;
	n = nullptr;
	//.shortcut-targets-by-id\\1_oUqTASj6Sw51J-MC2LGF-6mnozCbc2W\\Battleship\\
	//G:\\.shortcut-targets-by-id\\1_oUqTASj6Sw51J-MC2LGF-6mnozCbc2W\\Battleship
	// G:\\.shortcut-targets-by-id\\1_oUqTASj6Sw51J-MC2LGF-6mnozCbc2W\\Battleship
	// Player *n = new Player();
	// n->print_fleet();
	// n->print_hits();
	// VARTYPE for hits?
	// delete n;
}