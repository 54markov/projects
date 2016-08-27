/*
 * Desciption game filed abstraction
 */

#include "GameField.h"

using namespace std;

GameCell::GameCell() : cellState_(GAME_CELL_STATE_EMPTY), shipPtr_(NULL) {}
GameCell::~GameCell() {}

void GameCell::draw() 
{
    switch(cellState_)
    {
        case GAME_CELL_STATE_EMPTY:
            cout << "  ";
            break;

        case GAME_CELL_STATE_TAKEN:
            cout << COLOR_YEL;
            cout << " ";
            cout << COLOR_OFF;
            cout << " ";
            break;

        default:
            cerr << "ERROR" << endl;
            break;
    }
}

void GameCell::draw_() 
{
    switch(cellState_)
    {
        case GAME_CELL_STATE_EMPTY:
            cout << "  ";
            break;

        case GAME_CELL_STATE_TAKEN:
            cout << "  ";
            break;

        case GAME_CELL_STATE_MISS:
            cout << "o ";
            break;

        case GAME_CELL_STATE_HIT:
            cout << "x ";
            break;


        default:
            cerr << "ERROR" << endl;
            break;
    }
}

void GameCell::setShip(Ship *newShip)
{
    this->shipPtr_ = newShip;
    this->cellState_ = GAME_CELL_STATE_TAKEN;
}

int GameCell::makeAction() 
{
    if (this->cellState_ != GAME_CELL_STATE_EMPTY) {
        this->cellState_ = GAME_CELL_STATE_HIT;
            shipPtr_->damageShip();
            return GAME_ACTION_HIT;
    } else {
        this->cellState_ = GAME_CELL_STATE_MISS;
        return GAME_ACTION_MISS;
    }
}


GameField::GameField(int x, int y)
{
    for (auto i = 0; i < y; ++i) {
        vector<GameCell> newRow(x);
        gameField_.push_back(newRow);
    }
}

GameField::~GameField() {}

void GameField::draw() 
{
    auto rowCounter = 0;

    cout << "  A|B|C|D|E|F|G|H|I|J" << endl;
    cout << "  _|_|_|_|_|_|_|_|_|_" << endl;
    for (auto &i: this->gameField_) {
        cout << rowCounter << "|";
        for (auto &j: i) {
            j.draw();
        }
        cout << "|" << rowCounter << endl;
        rowCounter++;
    }
    cout << "  -------------------" << endl;
    cout << "  A|B|C|D|E|F|G|H|I|J" << endl;
}

void GameField::draw_() 
{
    cout << endl;

    for (auto &i: this->gameField_) {
                
                for (auto &j: i) {
                    j.draw_();
                }
                cout << endl;
            }
            cout << endl;
}

void GameField::placeShip(int shipType)
{
    switch(shipType)
    {
        case SHIP_TYPE_MICRO:
            //create_and_place_micro_ship();
            break;

        case SHIP_TYPE_SMALL:
            create_and_place_small_ship();
            break;

        case SHIP_TYPE_MEDIUM:
            //create_and_place_medium_ship();
            break;

        case SHIP_TYPE_LARGE:
            create_and_place_large_ship();
            break;

        default:
            cerr << "ERROR" << endl;
            break;
    }
}

void GameField::create_and_place_micro_ship(int x, int y, char dir)
{
    Ship *newShip = new Ship(SHIP_TYPE_MICRO);

    if (dir == 'w') {
        for (auto i = 0; i < SHIP_TYPE_MICRO; ++i) {
            this->gameField_[x][y].setShip(newShip);
            x++;
        }
    } else if (dir == 'a') {
        for (auto i = 0; i < SHIP_TYPE_MICRO; ++i) {
            this->gameField_[x][y].setShip(newShip);
            y++;
        }
    }
}

void GameField::create_and_place_small_ship(int x, int y, char dir)
{
    Ship *newShip = new Ship(SHIP_TYPE_SMALL);

    if (dir == 'w') {
        for (auto i = 0; i < SHIP_TYPE_SMALL; ++i) {
            this->gameField_[x][y].setShip(newShip);
            x++;
        }
    } else if (dir == 'a') {
        for (auto i = 0; i < SHIP_TYPE_SMALL; ++i) {
            this->gameField_[x][y].setShip(newShip);
            y++;
        }
    }
}

void GameField::create_and_place_medium_ship(int x, int y, char dir)
{
    Ship *newShip = new Ship(SHIP_TYPE_MEDIUM);

    if (dir == 'w') {
        for (auto i = 0; i < SHIP_TYPE_MEDIUM; ++i) {
            this->gameField_[x][y].setShip(newShip);
            x++;
        }
    } else if (dir == 'a') {
        for (auto i = 0; i < SHIP_TYPE_MEDIUM; ++i) {
            this->gameField_[x][y].setShip(newShip);
            y++;
        }
    }
}

void GameField::create_and_place_large_ship(int x, int y, char dir)
{
    Ship *newShip = new Ship(SHIP_TYPE_LARGE);

    if (dir == 'w') {
        for (auto i = 0; i < SHIP_TYPE_LARGE; ++i) {
            this->gameField_[x][y].setShip(newShip);
            x++;
        }
    } else if (dir == 'a') {
        for (auto i = 0; i < SHIP_TYPE_LARGE; ++i) {
            this->gameField_[x][y].setShip(newShip);
            y++;
        }
    }
}

void GameField::create_and_place_large_ship()
{
    Ship *newShip = new Ship(SHIP_TYPE_LARGE);

    for (auto i = 0; i < SHIP_TYPE_LARGE; ++i) {
        this->gameField_[i][0].setShip(newShip);
    }
}

void GameField::create_and_place_small_ship()
{
    Ship *newShip = new Ship(SHIP_TYPE_SMALL);

    for (auto i = 0; i < SHIP_TYPE_SMALL; ++i) {
        this->gameField_[i][3].setShip(newShip);
    }
}
 
int GameField::makeAction(int x, int y) 
{
    return this->gameField_[x][y].makeAction();
}