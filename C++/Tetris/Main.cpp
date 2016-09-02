#include "Main.h"

#include "Color.h"
#include "KeyBoardHandle.h"

#include <iostream>
#include <vector> 
#include <thread>

#include "GameField.h"

using namespace std;

int main(int argc, char const *argv[])
{
/*
    GameField tetris;

    tetris.init();
    
    tetris.run();
    
    tetris.clear();
*/

/*
    Color consoleColor;

    consoleColor.fontRed("red");
    consoleColor.fontCyan("cyan");
    consoleColor.fontBlue("blue");
    consoleColor.fontGreen("green");
    consoleColor.fontBlack("black");
    consoleColor.fontWhite("white");
    consoleColor.fontYellow("yellow");
    consoleColor.fontMagenta("magenta");

    consoleColor.backGroundRed("  ");
    consoleColor.backGroundCyan("  ");
    consoleColor.backGroundBlue("  ");
    consoleColor.backGroundGreen("  ");
    consoleColor.backGroundBlack("  ");
    consoleColor.backGroundWhite("  ");
    consoleColor.backGroundYellow("  ");
    consoleColor.backGroundMagenta("  ");

*/
    GameField tetris;

    tetris.run();
    return 0;
}