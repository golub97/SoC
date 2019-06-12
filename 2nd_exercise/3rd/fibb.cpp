#include "fibb.hpp"
#include <cstdlib>
#include <ctime>
 
using namespace sc_core;
using namespace std;
 
fibb::fibb(sc_core::sc_module_name name) : sc_module(name)
{
	SC_THREAD(generate_number);
	SC_THREAD(print_number); 
}

void fibb::generate_number()
{
	while(1)
    	{
        	if((a.size() % 65 == 0))
        	{
         		a.push_back(0);
        	}
        	else if((a.size() % 65 == 1))
        	{
            		a.push_back(1);
        	}
        	else
        	{
            		a.push_back(a[a.size()-1] + a[a.size()-2]);
       		}
        	wait(rand() % 91 + 10, SC_NS);
    	}
}
void fibb::print_number()
{
	while(1)
	{
		wait(1, SC_SEC);
		cout<<"Fibonacci numbers: "<<a.size()<<endl;
		a.clear();
	}
}
