#include "GameField.h"

#include <vector>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

GameField::GameField()
{
    for (auto i = 0; i < 20; ++i) {
        std::vector<int> newRow(20);
        gameField_.push_back(newRow);
    }
}

GameField::~GameField() {}

void GameField::run()
{
    do {
        this->clearScreen();

        this->keyBoardHandle_.run();

        this->logic();

        this->draw();

        std::this_thread::sleep_for(1s);
    } while(this->keyBoardHandle_.getKey() != QUIT);
}

void GameField::logic()
{
    static int x = -1;
    static int y = 9;

    if (x == 19) {
        gameField_[x][y] = 1;
        gameField_[x][y + 1] = 1;

        x = -1; 
        y = 9;
    }

    if ((gameField_[x + 1][y] == 1) || (gameField_[x + 1][y + 1] == 1)){
        gameField_[x][y] = 1;
        gameField_[x][y + 1] = 1;

        x = -1; 
        y = 9;
    }

    cout << "x:" << x << " y:" << y << endl; 

    switch(this->keyBoardHandle_.getKey())
    {
        case LEFT:
            if ((y - 1) > 1) {
                gameField_[x][y] = 0;
                gameField_[x][y + 1] = 0;

                gameField_[x][--y] = 1;
                gameField_[x][y + 1] = 1;
            }
            break;

        case RIGHT:
            if ((y + 1) < 19) {
                gameField_[x][y] = 0;
                gameField_[x][y + 1] = 0;

                gameField_[x][++y] = 1;
                gameField_[x][y + 1] = 1;
            }
            break;

        case NOTHING:
            if (x == -1) {
                gameField_[0][y] = 1;
                gameField_[0][y + 1] = 1;
                ++x;
            } else {
                gameField_[0][y] = 0;
                gameField_[0][y + 1] = 0;

                gameField_[x][y] = 0;
                gameField_[x][y + 1] = 0;

                gameField_[++x][y] = 1;
                gameField_[x][y + 1] = 1;
            }
        default:
            break;
    }

    //gameField_[++x][y] = 1;
}

void GameField::draw()
{
    for (auto &i : gameField_) {
        for (auto &j : i) {
            if (j == 1) {
                color_.fontRed("X");
                std::cout << " ";
            } else {
                std::cout << j << " ";
            }
        }
        std::cout << std::endl;
    }
}

void GameField::clearScreen()
{
    std::cout << "\033[2J\033[1;1H" << std::endl;
}