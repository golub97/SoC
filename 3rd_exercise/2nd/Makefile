nuclear: main.cpp nuclear.cpp
	g++ -std=c++11 -I ${SYSTEMC}/include -L${SYSTEMC}/lib-linux64 -lsystemc -o nuclear nuclear.cpp main.cpp

.PHONY: clean
clean:
	rm nuclear
