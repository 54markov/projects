#ifndef _GAME_FILED_H_
#define _GAME_FILED_H_

#include <iostream>
#include <vector>

#include <mutex>
#include <thread>
#include <chrono>

/* Clear screen */
#define CLR_SCR "\033[2J\033[1;1H"
/* Color off */
#define COL_OFF "\033[0m"
/* Background */
#define BG_BLC  "\033[0;40m"
#define BG_RED  "\033[0;41m"
#define BG_GRN  "\033[0;42m"
#define BG_YEL  "\033[0;43m"
#define BG_BLU  "\033[0;44m"
#define BG_MAG  "\033[0;45m"
#define BG_CYN  "\033[0;46m"
#define BG_WHT  "\033[0;47m"
/* Font color */
#define FC_BLC  "\033[0;30m"
#define FC_RED  "\033[0;31m"
#define FC_GRN  "\033[0;32m"
#define FC_YEL  "\033[0;33m"
#define FC_BLU  "\033[0;34m"
#define FC_MAG  "\033[0;35m"
#define FC_CYN  "\033[0;36m"
#define FC_WHT  "\033[0;37m"
/* Color text */
#define BLC_TEXT(string) FC_BLC string COL_OFF
#define RED_TEXT(string) FC_RED string COL_OFF
#define GRN_TEXT(string) FC_GRN string COL_OFF
#define YEL_TEXT(string) FC_YEL string COL_OFF
#define BLU_TEXT(string) FC_BLU string COL_OFF
#define MAG_TEXT(string) FC_MAG string COL_OFF
#define CYN_TEXT(string) FC_CYN string COL_OFF
#define WHT_TEXT(string) FC_WHT string COL_OFF




#endif