#include <iostream>
#include <vector>

#include "Ships.h"
#include "GameField.h"

using namespace std;

class GameSession
{
    private:
        GameField myGameField_;
        GameField enemyGameField_;

        vector<Ship> microShips_;
        vector<Ship> smallShips_;
        vector<Ship> mediumShips_;
        vector<Ship> largeShips_;
        
        int microShipsSize_;
        int smallShipsSize_;
        int mediumShipsSize_;
        int largeShipsSize_;

        int microShipsKill_;
        int smallShipsKill_;
        int mediumShipsKill_;
        int largeShipsKill_;
    
    public:
        GameSession() {
            microShipsSize_  = 4;
            smallShipsSize_  = 3;
            mediumShipsSize_ = 2;
            largeShipsSize_  = 1;

            microShipsKill_  = 0;
            smallShipsKill_  = 0;
            mediumShipsKill_ = 0;
            largeShipsKill_  = 0;

        }

        ~GameSession() {}

        void run() {

            this->placeShip();
/*
            while(1) {
                this->clearScreen();
                this->makeMove();

                this->showInfo();
                this->myGameField_.draw();
            }
*/
            //this->showInfo();
            //this->myGameField_.draw();
            //cout << endl;
            //this->enemyGameField_.draw();
        }

        void clearScreen() {
            cout << "\033[2J\033[1;1H";
        }

        void placeShip_(int shipType) {
            int x, y;
            char dir;

            cout << endl << "Ship type[" << shipType << "] Input x, y: ";
            cin >> x;
            cin >> y;
            cin >> dir;

            switch(shipType)
            {
                case SHIP_TYPE_MICRO:
                    this->myGameField_.create_and_place_micro_ship(x, y, dir);
                    break;

                case SHIP_TYPE_SMALL:
                    this->myGameField_.create_and_place_small_ship(x, y, dir);
                    break;

                case SHIP_TYPE_MEDIUM:
                    this->myGameField_.create_and_place_medium_ship(x, y, dir);
                    break;

                case SHIP_TYPE_LARGE:
                    this->myGameField_.create_and_place_large_ship(x, y, dir);
                    break;

                default:
                    break;
            }
        }

        void placeShip() {
            for (auto i = 0; i < microShipsSize_; ++i) {
                this->myGameField_.draw();
                this->placeShip_(SHIP_TYPE_MICRO);
                this->myGameField_.draw();
                this->clearScreen();
            }

            this->clearScreen();

            for (auto i = 0; i < smallShipsSize_; ++i) {
                this->myGameField_.draw();
                this->placeShip_(SHIP_TYPE_SMALL);
                this->myGameField_.draw(); 
                this->clearScreen();
            }

            this->clearScreen();

            for (auto i = 0; i < mediumShipsSize_; ++i) {
                this->myGameField_.draw();
                this->placeShip_(SHIP_TYPE_MEDIUM);
                this->myGameField_.draw();
                this->clearScreen();
            }

            this->clearScreen();

            for (auto i = 0; i < largeShipsSize_; ++i) {
                this->myGameField_.draw();
                this->placeShip_(SHIP_TYPE_LARGE);
                this->myGameField_.draw();
                this->clearScreen();
            }
        }

        void showInfo() {
            cout << "\tMy fleet \t|    Enemy Fleet" << endl;
            
            cout << "Ships []       = " << microShipsSize_;
            cout << "\t|\t" << microShipsKill_ << "/" << microShipsSize_ << endl;
            
            cout << "Ships [][]     = " << smallShipsSize_;
            cout << "\t|\t" << smallShipsKill_ << "/" << smallShipsSize_ << endl;

            cout << "Ships [][][]   = " << mediumShipsSize_;
            cout << "\t|\t" << mediumShipsKill_ << "/" << mediumShipsSize_ << endl;

            cout << "Ships [][][][] = " << largeShipsSize_;
            cout << "\t|\t" << largeShipsKill_ << "/" << largeShipsSize_ << endl;

            cout << endl;
        }
};


int main(int argc, char const *argv[])
{
    GameSession gameSession;

    gameSession.run();

    return 0;
}