#ifndef DPP_HPPg
#define DPP_HPP

#include <systemc>
#include <iostream>

using namespace sc_core;

enum State {thinking, take_left_fork, take_right_fork, eat};

SC_MODULE(Phil)
{
public:
	SC_HAS_PROCESS(Phil);
	
	Phil(sc_module_name, sc_mutex*, sc_mutex*);

	static int lef, rig;

	sc_event s0;
protected:
	State state;

	sc_mutex *left, *right;
	
	void proc();

	void print();

	void end();
};
#endif
