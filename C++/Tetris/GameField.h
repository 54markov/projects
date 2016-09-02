#ifndef _GAME_FIELD_H_
#define _GAME_FIELD_H_

#include <vector>

#include "Color.h"
#include "KeyBoardHandle.h"

class GameField
{
    private:
        std::vector<std::vector<int>> gameField_;
        KeyBoardHandle                keyBoardHandle_;
        Color                         color_;

    public:
        GameField();
        ~GameField();

        void run();
        void logic();
        void draw();
        void clearScreen();
};

#endif /* _GAME_FIELD_H_ */