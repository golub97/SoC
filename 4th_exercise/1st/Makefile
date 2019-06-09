fsm: main.cpp fsm.cpp
	g++ -std=c++11 -I ${SYSTEMC}/include -L${SYSTEMC}/lib-linux64 -lsystemc -o fsm fsm.cpp main.cpp

.PHONY: clean
clean:
	rm fsm
