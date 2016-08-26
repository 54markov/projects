#ifndef _GAME_FIELD_H_
#define _GAME_FIELD_H_

#include <list>

#include "Draw.h"

enum
{
    OBJECT_TYPE_UNKNOWN = 0,
    OBJECT_TYPE_SMALL   = 1,
    OBJECT_TYPE_BIG     = 2,
};

class GameField
{
    private:
        std::list<int> gameField_;
        Draw drawer_;

    public:
        GameField();
        ~GameField();
        
        std::list<int> &getGameField();

        void run();
        void setNewObject(int type);
        int generateObject();
};

#endif