/*
 * Describe game field class behavior
 */

#include "GameField.h"

#include <thread>
#include <chrono>
#include <random>

using namespace std;

GameField::GameField()
{
	for (auto i = 0; i < 20; ++i)
	{
		gameField_.push_back(OBJECT_TYPE_UNKNOWN);
	}
}

GameField::~GameField() {}
        
std::list<int> &GameField::getGameField()
{
	return gameField_;
}

int GameField::generateObject()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);

	std::uniform_int_distribution<int> distribution(0, 2);

	return distribution(generator);
}

void GameField::run()
{
	while(1) {
		gameField_.pop_front();

		auto objectType = this->generateObject();

		gameField_.push_back(objectType);
		drawer_.draw(getGameField());

		this_thread::sleep_for(1s);
	}
}

void GameField::setNewObject(int type)
{

}