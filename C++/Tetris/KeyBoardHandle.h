#ifndef _KEYBOARD_HANDLE_H_
#define _KEYBOARD_HANDLE_H_

#include <atomic>
#include <mutex>
#include <thread>
#include <chrono>


void lockMutex();
void unlockMutex();

enum
{
    NB_ENABLE  = 1,
    NB_DISABLE = 2
};

enum
{
    LEFT    = 1,
    RIGHT   = 2,
    ROTATE  = 3,
    BOOST   = 4,
    QUIT    = 5,
    NOTHING = 6
};

class KeyBoardHandle
{
    private:
        std::atomic_int key_;

        int keyBoardHit();
        void nonBlock(int state);

    public:
        KeyBoardHandle();
        ~KeyBoardHandle();

        void run();

        int getKey();
    
};

#endif /* _KEYBOARD_HANDLE_H_ */