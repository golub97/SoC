#include "door.hpp"

using namespace std;

Door::Door(sc_module_name)
{
	SC_METHOD(door);
	 sensitive << s1;

	SC_METHOD(send_event_s1);
	 dont_initialize();
	 sensitive << s0;

	state = A;
}

void Door::print(const char *str)
{
	cout << "The man is in front of the door " << str << " (" << sc_time_stamp() << ")" << endl;
}

void Door::send_event_s1()
{
	sc_time d(((double)(rand() % 41 + 30))/10, SC_SEC); // 3 to 7, with step 0.1
	sc_time e(5, SC_SEC); 

	cout << d << endl;

	if( d < e )
	{
		switch(state)
		{
		case A:
			state = B;
			s1.notify(d);
			break;
		case B:
			state = C;
			s1.notify(d);
			break;
		case C:
			state = END;
			s1.notify(d);
			break;		
		default:
			assert(false);
		}
	}
	else
	{
		state = A;
		s1.notify(d);
	}
}

void Door::door()
{
	switch(state)
	{
	case A:
		print("A");
		s0.notify();
		break;
	case B:
		print("B");
		s0.notify();
		break;
	case C:
		print("C");
		s0.notify();
		break;
	case END:
		cout << "END" <<endl;
		break;
	default:
		assert(false);
	}
}
