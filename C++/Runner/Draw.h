#ifndef _DRAW_H_
#define _DRAW_H_

#include <iostream>
#include <list>

class Draw
{
    public:
        Draw();
        ~Draw();
        
        void clearScreen();
        void draw(std::list<int> &gameField);
};

#endif