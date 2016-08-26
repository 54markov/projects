#ifndef _SNAKE_H_
#define _SNAKE_H_

enum
{
    SNAKE_DIRECTION_UNKNOWN = 0,
    SNAKE_DIRECTION_UP      = 1,
    SNAKE_DIRECTION_LEFT    = 2,
    SNAKE_DIRECTION_RIGHT   = 3,
    SNAKE_DIRECTION_DOWN    = 4
};

class Snake
{
    int dir_;

    public:
        Snake();
        ~Snake();

        void setDir(int newDir);
        int getDir();
};

#endif