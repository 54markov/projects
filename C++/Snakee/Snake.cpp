#include "Snake.h"

#include <iostream>

Snake::Snake() : dir_(SNAKE_DIRECTION_UNKNOWN) {}

Snake::~Snake() {}

void Snake::setDir(int newDir)
{
    dir_ = newDir;
}

int Snake::getDir()
{
    return dir_;
}