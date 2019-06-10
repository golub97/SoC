door: main.cpp door.cpp
	g++ -std=c++11 -I ${SYSTEMC}/include -L${SYSTEMC}/lib-linux64 -lsystemc -o door door.cpp main.cpp

.PHONY: clean
clean:
	rm door
