#include "dpp.hpp"

using namespace std;

Phil::Phil(sc_module_name name, sc_mutex* left, sc_mutex* right) : sc_module(name), left(left), right(right)
{
	SC_THREAD(proc);
	SC_THREAD(print);
	SC_METHOD(end);
	 dont_initialize();
	 sensitive << s0;
	state = thinking;
}

int Phil::lef = 0;
int Phil::rig = 0;

void Phil::end()
{
	if(lef == 5)	
	{
		cout<< "All philosophers hold the fork in their left hand" <<endl;
	}
	else if(rig == 5)
	{
		cout<< "All philosophers hold the fork in their right hand" <<endl;
	}
}

void Phil::print()
{
	while(1)
	{
		if(rig == 5 || lef == 5)
			return;

		switch(state)
		{
		case thinking:
			cout<< "@ " << sc_time_stamp() << ": " << name() << " is thinking." <<endl;
			break;
		case take_left_fork:
			cout<< "@ " << sc_time_stamp() << ": " << name() << " is taking the left fork." <<endl;
			break;
		case take_right_fork:
			cout<< "@ " << sc_time_stamp() << ": " << name() << " is taking the right fork." <<endl;
			break;
		case eat:
			cout<< "@ " << sc_time_stamp() << ": " << name() << " is eating." <<endl;
			break;
		default:
			assert(false);
		}

		wait(1, SC_SEC);
	}
}

void Phil::proc()
{
	while(1)
	{
		int n;
		
		switch(state)
		{
		case thinking:
			
			//cout<< "@ " << sc_time_stamp() << ": " << name() << " is thinking." << endl;
			
			wait(rand() % 201 + 100, SC_MS);
			
			n = rand() % 2;
			
			if(!n)
			{
				if(left->trylock() != -1)
				{
					state = take_left_fork;	
					++lef;
				}
			}
			else
			{
				if(right->trylock() != -1)
				{
					state = take_right_fork;
					++rig;
				}
			}
			break;
		case take_left_fork:

			//cout<< "@ " << sc_time_stamp() << ": " << name() << " is taking the left fork." << endl;

			wait(rand() % 201 + 100, SC_MS);

			n = rand() % 2;

			if(n)
			{
				if(right->trylock() != -1)
				{
					state = eat;
				}
				else
				{
					state = thinking;
					left->unlock();
					--lef;
				//cout<< "@ " << sc_time_stamp() << ": " << name() << " is puting down left fork. " << endl;
				}
			}
		
			break;
		case take_right_fork:

			//cout<< "@ " << sc_time_stamp() << ": " << name() << " is taking the right fork." << endl;

			wait(rand() % 201 + 100, SC_MS);

			n = rand() % 2;

			if(n)
			{
				if(left->trylock() != -1)
					state = eat;
				else
				{
					state = thinking;
					right->unlock();
					--rig;
				//cout<< "@ " << sc_time_stamp() << ": " << name() << " is puting down right fork. " << endl;
				}
			}
		
			break;
		case eat:
		
			//cout<< "@ " << sc_time_stamp() << ": " << name() << " is eating." << endl;
		
			wait(rand() % 201 + 100, SC_MS);

			left->unlock();
			right->unlock();
			
			--lef;
			--rig;

			state = thinking;			
			break;
		default:
			assert(false);
		}

		if(rig == 5 || lef == 5)
		{
			s0.notify();
			return;
		}
	}
}
