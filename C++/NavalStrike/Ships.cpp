/*
 * Desciption
 */

#include "Ships.h"

#include <iostream>
#include <vector>

/******************************************************************************/
/* Ship is a Base Class                                                       */
/******************************************************************************/
Ship::Ship(int newSize) : size_(newSize), healthPoint_(newSize) {} 
Ship::~Ship() {}

void Ship::showStatus() 
{
    cout << endl;
    cout << "Ship [HP]: " << healthPoint_ << endl;
    cout << "Ship size: " << size_ << endl;
    cout << endl;
}

int Ship::damageShip()
{
    if ((this->healthPoint_ - 1) == 0) {
        return SHIP_IS_DEAD;
    } else {
        this->healthPoint_ -= 1;
    }
    return SHIP_IS_ALIVE;
}