#ifndef NUCLEAR_HPP
#define NUCLEAR_HPP

#include <systemc>

enum State {inactive, active, explode};

SC_MODULE(nuc)
{
public:
	SC_HAS_PROCESS(nuc);

	nuc(sc_core::sc_module_name name, sc_core::sc_event* );

	void setState(State );

	void process();

	static int counter;
protected:
	State state;

	sc_core::sc_event* s0;
};
#endif
