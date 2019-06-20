dpp: main.cpp dpp.cpp
	g++ -std=c++11 -I ${SYSTEMC}/include -L${SYSTEMC}/lib-linux64 -lsystemc -o dpp dpp.cpp main.cpp

.PHONY: clean
clean:
	rm dpp
