all: snake_game

snake_game: snake game score Main.h Main.cpp
	g++ -g -O3 -o main Main.cpp Snake.o Game.o Score.o -std=c++14 -lpthread

game: Game.h Game.cpp
	g++ -g -O3 -c Game.cpp -std=c++14

snake: Snake.h Snake.cpp
	g++ -g -O3 -c Snake.cpp -std=c++14

score: Score.h Score.cpp
	g++ -g -O3 -c Score.cpp -std=c++14