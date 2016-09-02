#include "GameField.h"

using namespace std;

enum
{
    OBJECT_TYPE_ONE = 1,
    OBJECT_TYPE_TWO = 2,
    OBJECT_TYPE_THREE = 3,
    OBJECT_TYPE_FOUR = 4
};

class Object
{
    private:
        int type_;
        pair<int, int> one_;
        pair<int, int> two_;
        pair<int, int> three_;
        pair<int, int> four_;

    public:
        Object() 
        {
            one_    = make_pair(0, 10);
            two_    = make_pair(0, 11);
            three_  = make_pair(1, 10);
            four_   = make_pair(1, 11);
        }
        ~Object() {}

        void setType(int _type) { type_ = _type; }
        int getType() { return type_; }

        void setPairOne(int x, int y)
        {
            x = x + one_.first;
            y = y + one_.second;
            one_ = make_pair(x, y);
        }

        void setPairTwo(int x, int y)
        {
            x = x + two_.first;
            y = y + two_.second;
            two_ = make_pair(x, y);
        }
        
        void setPairThree(int x, int y)
        {
            x = x + three_.first;
            y = y + three_.second;
            three_ = make_pair(x, y);
        }

        void setPairFour(int x, int y)
        {
            x = x + four_.first;
            y = y + four_.second;
            four_ = make_pair(x, y);
        }

        pair<int, int> &getPairOne() { return one_; }
        pair<int, int> &getPairTwo() { return two_; }
        pair<int, int> &getPairThree() { return three_; }
        pair<int, int> &getPairFour() { return four_; }
};

class GameField
{
    private:
        bool createNewObject_;
        int rowSize_;
        int colSize_;
        int gameScore_;
        vector<vector<int>> gameField_;

        Object gameObject_;

        mutex gameMutex_;
    public:
        GameField(int x = 20, int y = 40) : rowSize_(x), colSize_(y) 
        {
            createNewObject_ = false;

            gameScore_ = 0;

            for (auto i = 0; i < rowSize_; ++i) {
                vector<int> newRow(colSize_);
                gameField_.push_back(newRow);
            }
        }

        ~GameField() {}

        void lockMutex() { this->gameMutex_.lock(); }
        void unlockMutex() { this->gameMutex_.unlock(); }
        vector<vector<int>> &getGameField() { return gameField_; }

        int checkEndClimbDown()
        {
            static int rowCnt = 0;

            if (rowCnt + 1 != rowSize_ - 1 ) {
                rowCnt++;
            }
            else {
                rowCnt = 0;
                return 1;
            }

            return 0;
        }

        void moveObjectLeft() 
        {
            updateField_();
            updateObject(0, -1);
        }

        void moveObjectRight()
        {
            updateField_();
            updateObject(0, 1);
        }

        void initField()
        {
            createNewObject_ = false;

            auto p1 = gameObject_.getPairOne();
            auto p2 = gameObject_.getPairTwo();
            auto p3 = gameObject_.getPairThree();
            auto p4 = gameObject_.getPairFour();

            gameField_[p1.first][p1.second] = 8;
            gameField_[p2.first][p2.second] = 8;
            gameField_[p3.first][p3.second] = 8;
            gameField_[p4.first][p4.second] = 8;
        }

        void updateObject(int x, int y)
        {
            gameObject_.setPairOne(x, y);
            gameObject_.setPairTwo(x, y);
            gameObject_.setPairThree(x, y);
            gameObject_.setPairFour(x, y);
        }

        void updateField()
        {
            auto p1 = gameObject_.getPairOne();
            auto p2 = gameObject_.getPairTwo();
            auto p3 = gameObject_.getPairThree();
            auto p4 = gameObject_.getPairFour();

            gameField_[p1.first][p1.second] = 8;
            gameField_[p2.first][p2.second] = 8;
            gameField_[p3.first][p3.second] = 8;
            gameField_[p4.first][p4.second] = 8;

        }

        void updateField_()
        {
            auto p1 = gameObject_.getPairOne();
            auto p2 = gameObject_.getPairTwo();
            auto p3 = gameObject_.getPairThree();
            auto p4 = gameObject_.getPairFour();

            gameField_[p1.first][p1.second] = 0;
            gameField_[p2.first][p2.second] = 0;
            gameField_[p3.first][p3.second] = 0;
            gameField_[p4.first][p4.second] = 0;
        }

        void moveObjectDown()
        {
            updateField_();

            if (checkEndClimbDown() == 0) {
                updateObject(1, 0);
            } else {
                createNewObject_ == true;
            }

            updateField();
        }

        void draw_()
        {
            for (auto &i: this->getGameField()) {
                for (auto &j: i) {
                    if (j != 0) {
                        cout << j;
                    } else {
                        cout << "_";
                    }
                }
                cout << endl;
            }
        }

        static void draw(GameField *ptr) 
        {  
            ptr->initField();

            while(1) {

                if (ptr->createNewObject_ == true) {
                    ptr->initField();   
                }

                ptr->lockMutex();
                ptr->moveObjectDown();
                ptr->unlockMutex();

                system("/bin/stty cooked");
                ptr->clearScreen();
                ptr->printInfo();
                ptr->printGameScore();
                ptr->draw_();
                system("/bin/stty raw");

                

                this_thread::sleep_for(1s);
            }
        }

        void runGame()
        {
            thread gameThread(draw, this);

            this->runReadKey();

            exit(1);

            gameThread.join();
        }

        void runReadKey() 
        {
            char key;

            do {
                system("/bin/stty raw");
                key = getchar();
                system("/bin/stty cooked");

                switch(key)
                {
                    case 'a':
                        this->gameMutex_.lock();
                        this->moveObjectLeft();
                        this->gameMutex_.unlock();
                        break;

                    case 'd':
                        this->gameMutex_.lock();
                        this->moveObjectRight();
                        this->gameMutex_.unlock();
                        break;

                    default:
                        break;
                }
            } while(key != 'q');
        }

        inline void clearScreen()
        {
            cout << "\033[2J\033[1;1H" << endl;
        }

        inline void printInfo()
        {
            cout << "* 'Q' - exit the game" << endl;
            cout << "* 'A' - move left" << endl;
            cout << "* 'D' - move right" << endl;
        }

        inline void printGameScore()
        {
            cout << "****************" << endl;
            cout << "* GAME SCORE: " << gameScore_ << endl;
            cout << "****************" << endl;
        }

        void genObject()
        {

        }


    
};

int main(int argc, char const *argv[])
{
    GameField gameFiled;

    gameFiled.runGame();
    return 0;
}