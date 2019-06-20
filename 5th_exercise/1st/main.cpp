#include "dpp.hpp"


int sc_main(int argc, char* argv[])
{
	srand(time(NULL));

	sc_mutex mtx1, mtx2, mtx3, mtx4, mtx5;
	
	Phil p1("Voltaire", &mtx5, &mtx1);
	Phil p2("Socrates", &mtx1, &mtx2);
	Phil p3("Confucius", &mtx2, &mtx3);
	Phil p4("Plato", &mtx3, &mtx4);
	Phil p5("Descartes", &mtx4, &mtx5);

	sc_start(100000, SC_SEC);

	return 0;
}
