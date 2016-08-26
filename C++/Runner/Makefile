all: simple_runner

simple_runner: Main.h Main.cpp GameField.o Draw.o
	g++ -g -O3 -o simple_runner Main.cpp GameField.o Draw.o -std=c++14

GameField.o: GameField.cpp GameField.h
	g++ -g -O3 -c GameField.cpp -std=c++14

Draw.o: Draw.cpp Draw.h
	g++ -g -O3 -c Draw.cpp -std=c++14

clean:
	rm -f *.o simple_runner