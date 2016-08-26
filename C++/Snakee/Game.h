#ifndef _GAME_H_
#define _GAME_H_

#define COLOR_RED "\033[31m"
#define COLOR_BLU "\033[34m"
#define COLOR_OFF "\033[0m"

#include "Snake.h"
#include "Score.h"

#include <iostream>
#include <vector>

#include <thread>
#include <chrono>

class Game
{
    private:
        char key_;
        int gameScore_;
        int fieldSize_;
        int startX_;
        int startY_;

        Score gameScoreObject_;
        Snake gameSnake_;

        std::vector<std::vector<int>> gameField_;

        void runReadKey();

    public:
        Game(int size = 20);
        ~Game();

        void draw();

        void clearScreen();

        void runGame();

        int getX();
        int getY();

        void initSnake();
        void moveSnake();
        void setMoveDir(int dir);

        void clearSnake();

        void initScore();
        void lifeScore();
        int getScore();

};

#endif