#include "fsm.hpp"

using namespace std;

Fsm::Fsm(sc_module_name name, State s) 
{
	SC_METHOD(fsm);	
	 sensitive << a << b;
	
	SC_METHOD(ab);
	 dont_initialize();
	 sensitive << s0;

	state = s;

}

void Fsm::print(const char *str)
{
	cout << "Current state: " << str << " (" << sc_time_stamp() << ")" <<endl;
}

void Fsm::ab()
{
	n = rand() % 2;

	if(!n)
	{
		a.notify(5, SC_NS);
		state = step2;		
	}
	else
	{
		b.notify(5, SC_NS);
		state = step3;				
	}
}

void Fsm::fsm()
{
	switch(state)
	{
	case idle:
		print("idle");
		next_trigger(5, SC_NS);
		state = step1;
		break;
	case step1:
		print("step1");
		next_trigger(a | b);
		s0.notify();
		break;
	case step2:
		print("step2");
		next_trigger(5, SC_NS);
		state = idle;
		break;
	case step3:
		print("step3");
		next_trigger(5, SC_NS);
		state = idle;
		break;
	default:
		assert(false);
	}
}
