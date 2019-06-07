#include <systemc>
#include "fibb.hpp"
#include <ctime>

int sc_main(int argc, char* argv[])
{
	srand(time(NULL));	
	
	fibb qq("QQQ");

	sc_start(1, sc_core::SC_US);

	return 0;
}
