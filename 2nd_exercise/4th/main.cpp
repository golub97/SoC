#include "lotto.hpp"
#include <ctime>

int sc_main(int argc, char* argv[])
{
	srand(time(NULL));	
	
	lotto qq("QQQ");

	sc_start(3.101, sc_core::SC_SEC);

	return 0;
}
