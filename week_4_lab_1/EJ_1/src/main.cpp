#include <iostream>

int *sec_fixed(int seconds = 0)
{
	int hours = seconds / 3600;
	seconds -= hours * 3600;
	int minutes = seconds / 60;
	seconds -= minutes * 60;
	static int out[] = {hours, minutes, seconds};
	return (int *)&out;
}

int main(int argc, char *argv[])
{
	int time_sec;
	std::cout << "Seconds: ";
	std::cin >> time_sec;
	const int *l = sec_fixed(time_sec);
	std::cout << l[0] << "h " << l[1] << "m " << l[2] << "s " << std::endl;
}