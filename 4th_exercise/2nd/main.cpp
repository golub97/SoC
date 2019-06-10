#include "door.hpp"
#include <ctime>

int sc_main(int argc, char* argv[])
{
	srand(time(NULL));

	Door qqq("qqq");

	sc_start(30, SC_SEC);

	return 0;
}
