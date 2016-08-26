#include "Game.h"

using namespace std;

Game::Game(int size)
{
    key_ = 'e';

    gameScore_ = 1;

    fieldSize_ = size;

    startY_ = (size);
    startX_ = (size / 2);

    std::vector<int> newRow(2 * size);
 
    for (auto i = 0; i < (2 * fieldSize_); ++i)
    {
        newRow[i] = 0;
    }

    for (auto i = 0; i < fieldSize_; ++i) {
        gameField_.push_back(newRow);
    }
}

Game::~Game() {}

void Game::draw()
{
    std::cout << "Game score: " << gameScore_ - 1 << std::endl;

    for (auto i = 0; i <= (2 * fieldSize_) + 1; ++i) {
        std::cout << "-";
    }
    std::cout << std::endl;

    for (auto &i: gameField_) {
        std::cout << "|";
        for (auto &j: i) {
            if (j == 0) {
                std::cout << ' ';
            } else if (j == -1) {
                std::cout << COLOR_RED;
                std::cout << 'H';
                std::cout << COLOR_OFF;
            } else {
                std::cout << COLOR_BLU;
                std::cout << 'x';
                std::cout << COLOR_OFF;
            }
        }
        std::cout << "|" << std::endl;
    }

    for (auto i = 0; i <= (2 * fieldSize_) + 1; ++i) {
        std::cout << "-";
    }
    std::cout << std::endl;
}

void Game::clearScreen()
{
    std::cout << "\033[2J\033[1;1H" << std::endl;
}

int Game::getX() { return startX_; }
int Game::getY() { return startY_; }

void Game::initSnake()
{
    gameField_[startX_][startY_] = gameScore_;
}

void Game::moveSnake()
{
    if (gameField_[startX_][startY_] == -1) {
        gameScore_ += 1;
    }
    gameField_[startX_][startY_] = gameScore_;
}

void Game::clearSnake()
{
    for (auto &i: gameField_) {
        for (auto &j: i) {
            if (j > 0) {
                j -= 1;
            }
        }
    }

}

void Game::setMoveDir(int dir)
{
    switch(dir)
    {
        case SNAKE_DIRECTION_UP:
        {  
            if ((startX_ - 1) == -1)
            {
                std::cout << "Game LOSE" << std::endl;
                exit(1);
            } else {
                startX_ -= 1;
            }
            break;
        }

        case SNAKE_DIRECTION_LEFT:
            if ((startY_ - 1) == -1)
            {
                std::cout << "Game LOSE" << std::endl;
                exit(1);
            } else {
                startY_ -= 1;
            }
            break;

        case SNAKE_DIRECTION_RIGHT:
            if ((startY_ + 1) == (2 * fieldSize_))
            {
                std::cout << "Game LOSE" << std::endl;
                exit(1);
            } else {
                startY_ += 1;
            }
            break;

        case SNAKE_DIRECTION_DOWN:
        {
            if ((startX_ + 1) == fieldSize_)
            {
                std::cout << "Game LOSE" << std::endl;
                exit(1);
            } else {
                startX_ += 1;
            }
            break;
        }

        default:
            break;
    }
}

void Game::runReadKey()
{
    do {
        system("/bin/stty raw");
        key_ = getchar();
        system("/bin/stty cooked");

        switch (key_)
        {
            case 'w':
                gameSnake_.setDir(SNAKE_DIRECTION_UP);
                break;

            case 's':
                gameSnake_.setDir(SNAKE_DIRECTION_DOWN);
                break;

            case 'a':
                gameSnake_.setDir(SNAKE_DIRECTION_LEFT);
                break;

            case 'd':
                gameSnake_.setDir(SNAKE_DIRECTION_RIGHT);
                break;

            default:
                break;
        }

    } while(key_ != 'q');

    return;
}


void Game::runGame()
{
    thread reader(&Game::runReadKey, this);

    this->initSnake();

    this->initScore();

    do {
        if (this->getScore() == 0) {
            this->initScore();
        }

        system("/bin/stty cooked");
        
        this->clearScreen();

        this->clearSnake();
        this->setMoveDir(gameSnake_.getDir());
        this->moveSnake();

        this->draw();
        
        system("/bin/stty raw");

        std::this_thread::sleep_for(1s);

        this->lifeScore();

    } while (key_ != 'q');

    system("/bin/stty cooked");

    reader.join();
}

void Game::initScore()
{
    // generation coord
    gameScoreObject_.setPlace(1, 1);

    gameField_[9][9] = -1;

    gameScoreObject_.setLife(20);
}

void Game::lifeScore()
{
    // decrement life_sycle
    gameScoreObject_.lifeScore();
}

int Game::getScore()
{
    if (gameScoreObject_.getLife() == 0) {
        return 0; // create new score
    } else {
        return 1;
    }
}