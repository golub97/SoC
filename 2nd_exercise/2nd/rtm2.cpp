#include <systemc>
#include <iostream>
#include <time.h>
 
int sc_main(int argc, char *argv[])
{
    srand(time(NULL));

    sc_core::sc_time t1((rand() % 10) + 1, sc_core::SC_NS);

    sc_core::sc_time t2((rand() % 10) + 1, sc_core::SC_NS);

    sc_core::sc_time t3 = t1 + t2;

    sc_start(t3);
 
    std::cout << "Random time 1: " << t1 << "\nRandom time 2: " << t2;
    std::cout << "\nCurrent time: " << sc_core::sc_time_stamp() << std::endl;
   
     return 0;
}
