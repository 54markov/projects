all: main

main: main.cpp server logger
	g++ -g -Wall -o main main.cpp server.o logger.o -std=c++14

server: server/server.cpp server/server.hpp
	g++ -g -Wall -c server/server.cpp -std=c++14

logger: logger/logger.cpp logger/logger.hpp
	g++ -g -Wall -c logger/logger.cpp -std=c++14

clean:
	rm -f main *.o
