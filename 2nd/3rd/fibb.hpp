#ifndef FIBB_HPP
#define FIBB_HPP

#include <systemc>
#include <vector>

typedef sc_dt::sc_int<45> num;
typedef std::vector<num> array;

SC_MODULE(fibb)
{
public:
	SC_HAS_PROCESS(fibb);

	fibb(sc_core::sc_module_name name);

	void generate_number();
	void print_number();
protected:
	array a;
};

#endif
