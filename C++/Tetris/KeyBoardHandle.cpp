#include "KeyBoardHandle.h"

#include <iostream> 
#include <stdio.h>
#include <thread>

#include <stdio.h>
#include <termios.h>
#include <unistd.h>

KeyBoardHandle::KeyBoardHandle() : key_(NOTHING) {}
KeyBoardHandle::~KeyBoardHandle() {}

int KeyBoardHandle::keyBoardHit()
{
    struct timeval tv;
    fd_set fds;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds); //STDIN_FILENO is 0
    select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &fds);
}

void KeyBoardHandle::nonBlock(int state)
{
    struct termios ttystate;
 
    //get the terminal state
    tcgetattr(STDIN_FILENO, &ttystate);
 
    if (state == NB_ENABLE) {
        //turn off canonical mode
        ttystate.c_lflag &= ~ICANON;
        //minimum of number input read.
        ttystate.c_cc[VMIN] = 1;
    } else if (state == NB_DISABLE) {
        //turn on canonical mode
        ttystate.c_lflag |= ICANON;
    }
    //set the terminal attributes.
    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
}

void KeyBoardHandle::run()
{
    nonBlock(NB_ENABLE);
    
    if (keyBoardHit() != 0)
    {
        switch(fgetc(stdin))
        {
            case 'a':
                key_ = LEFT;
                break;
                    
            case 'd':
                key_ = RIGHT;
                break;

            case 'w':
                key_ = ROTATE;
                break;

            case 's':
                key_ = BOOST;
                break;

            case 'q':
                key_ = QUIT;
                break;

            default:
                key_ = NOTHING;
                break;
        }
    } else {
        key_ = NOTHING;
    }
    nonBlock(NB_DISABLE);
}

int KeyBoardHandle::getKey()
{
    return key_;
}