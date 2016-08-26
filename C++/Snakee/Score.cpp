#include "Score.h"

Score::Score() {}
Score::~Score() {}

void Score::setPlace(int x, int y)
{
	x_ = x;
	y_ = y;
}

void Score::setLife(int sycle)
{
	lifeSycle_ = sycle;
}

void Score::Score::lifeScore()
{
	lifeSycle_ -= 1;
}

int Score::getLife()
{
	return lifeSycle_;
}