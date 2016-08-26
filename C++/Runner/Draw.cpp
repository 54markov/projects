/*
 * Describe draw class behavior
 */

#include "Draw.h"

using namespace std;

Draw::Draw() {}
Draw::~Draw() {}

void Draw::clearScreen()
{
    cout << "\033[2J\033[1;1H" << endl;
}

void Draw::draw(std::list<int> &gameField)
{
    this->clearScreen();

    for (auto &i: gameField) {
        switch(i)
        {
            case 1:
                cout << " S ";
                break;

            case 2:
                cout << " B ";
                break;

            default:
                cout << " _ ";
                break;
        }
    }
    cout << endl;
}