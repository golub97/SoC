#ifndef DOOR_HPP
#define DOOR_HPP

#include <systemc>

using namespace sc_core;

enum State {A, B, C, END};

SC_MODULE(Door)
{
public:
	SC_HAS_PROCESS(Door);

	Door(sc_module_name);
	
	sc_event s0, s1;
protected:
	void print(const char *);

	State state;	

	void door();
	void send_event_s1();
};
#endif
