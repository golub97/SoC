#include "fsm.hpp"
#include <ctime>

int sc_main(int argc, char* argv[])
{
	srand(time(NULL));

	Fsm qqq("qqq", idle);

	sc_start(50, SC_NS);

	return 0;
}
