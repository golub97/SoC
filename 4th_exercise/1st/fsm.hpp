#ifndef FSM_HPP
#define FSM_HPP

#include <systemc>

using namespace sc_core;

enum State {idle, step1, step2, step3};

SC_MODULE(Fsm)
{
public:
	SC_HAS_PROCESS(Fsm);

	Fsm(sc_module_name, State );
protected:
	void print(const char *);

	State state;
	sc_event a, b, s0;

	int n;

	void ab();
	void fsm();	

};
#endif
