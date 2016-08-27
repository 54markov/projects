#ifndef SHIPS_H
#define SHIPS_H

#include <iostream>
#include <vector>

using namespace std;

/******************************************************************************/
/* Ships type enumeration                                                     */
/******************************************************************************/
enum
{
    SHIP_TYPE_MICRO = 1,
    SHIP_TYPE_SMALL = 2,
    SHIP_TYPE_MEDIUM = 3,
    SHIP_TYPE_LARGE = 4
};

enum
{
    SHIP_IS_DEAD = 0,
    SHIP_IS_ALIVE = 1
};

/******************************************************************************/
/* Ship is a Base Class                                                       */
/******************************************************************************/
class Ship
{
    private:
        int healthPoint_;
        int size_;

    public:
        Ship(int newSize);
        ~Ship();

        void showStatus();
        int damageShip();
};

#endif