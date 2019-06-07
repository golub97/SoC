#include "nuclear.hpp"
#include <stdio.h>
#include <ctime>

int sc_main(int argc, char* argv[])
{
	srand(time(NULL));	

	sc_core::sc_event s1;	

	nuc *array[1000];

	char name[9];

	for(int i = 0; i < 1000; ++i)
	{
		sprintf(name, "name%i", i);
		array[i] = new nuc(name, &s1);
	}

	array[0]->setState(active);
	
	sc_start(100, sc_core::SC_NS);

	std::cout << array[0]->counter << std::endl;

	return 0;
}
