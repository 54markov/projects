#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#include "Ships.h"

#include <iostream>
#include <vector>

#define COLOR_YEL "\033[43m" // yellow
#define COLOR_OFF "\033[0m"	// reset

enum
{
	GAME_CELL_STATE_EMPTY = -1,
	GAME_CELL_STATE_TAKEN = 0,
	GAME_CELL_STATE_MISS = 1,
	GAME_CELL_STATE_HIT = 2
};

enum
{
	GAME_ACTION_MISS = 0,
	GAME_ACTION_HIT = 1
};

class GameCell
{
    private:
        int cellState_;
        Ship *shipPtr_;

    public:
        GameCell();
        ~GameCell();

        void draw();
        void draw_();
        void setShip(Ship *newShip);
        int makeAction();
};

class GameField
{
    private:
        vector<vector<GameCell>> gameField_;

    public:
        GameField(int x = 10, int y = 10);
        ~GameField();

        void draw();
        void draw_();
        void placeShip(int shipType);
        
        void create_and_place_micro_ship(int x, int y, char dir);
        void create_and_place_small_ship(int x, int y, char dir);
        void create_and_place_medium_ship(int x, int y, char dir);
        void create_and_place_large_ship(int x, int y, char dir);

        void create_and_place_large_ship();
        void create_and_place_small_ship(); 
        int makeAction(int x, int y);
};


#endif