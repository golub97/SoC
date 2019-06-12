#include "nuclear.hpp"

using namespace sc_core;
using namespace std;

nuc::nuc(sc_core::sc_module_name name, sc_core::sc_event* s00) : sc_module(name), s0(s00)
{
	SC_THREAD(process);
	state = inactive;
}

int nuc::counter = 0;

void nuc::setState(State s)
{
	state = s;
}

void nuc::process()
{
	if(state == active)
	{
		state = explode;
		++counter;
		s0->notify(rand() % 10 + 1, SC_NS);
		return;
	}
	while(1)
	{
		wait(*s0);
	
		int n;
		n = rand() % 100;

		if(n < 1)
			state = active;

		if(state == active)
		{
			state = explode;
			++counter;
			s0->notify(rand() % 10 + 1, SC_NS);
			return;
		}
	}
}
