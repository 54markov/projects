#include "Color.h"

#include <iostream>
#include <string>

Color::Color() 
{
    colorOff_ = "\033[0m";
    
    fontRed_     = "\033[0;31m";
    fontCyan_    = "\033[0;36m";
    fontBlue_    = "\033[0;34m";
    fontGreen_   = "\033[0;32m";
    fontBlack_   = "\033[0;30m";
    fontWhite_   = "\033[0;37m";
    fontYellow_  = "\033[0;33m";
    fontMagenta_ = "\033[0;35m";

    backGroundRed_     = "\033[0;41m";
    backGroundCyan_    = "\033[0;46m";
    backGroundBlue_    = "\033[0;44m";
    backGroundGreen_   = "\033[0;42m";
    backGroundBlack_   = "\033[0;40m";
    backGroundWhite_   = "\033[0;47m";
    backGroundYellow_  = "\033[0;43m";
    backGroundMagenta_ = "\033[0;45m";
}

Color::~Color() {}

void Color::fontRed(const std::string& str)
{
    std::cout << fontRed_ << str << colorOff_;
}

void Color::fontCyan(const std::string& str)
{
    std::cout << fontCyan_ << str << colorOff_;
}

void Color::fontBlue(const std::string& str)
{
    std::cout << fontBlue_ << str << colorOff_;
}

void Color::fontGreen(const std::string& str)
{
    std::cout << fontGreen_ << str << colorOff_;
}

void Color::fontBlack(const std::string& str)
{
    std::cout << fontBlack_ << str << colorOff_;
}

void Color::fontWhite(const std::string& str)
{
    std::cout << fontWhite_ << str << colorOff_;
}

void Color::fontYellow(const std::string& str)
{
    std::cout << fontYellow_ << str << colorOff_;
}

void Color::fontMagenta(const std::string& str)
{
    std::cout << fontMagenta_ << str << colorOff_;
}


void Color::backGroundRed(const std::string& str)
{
    std::cout << backGroundRed_ << str << colorOff_ << std::endl;
}

void Color::backGroundCyan(const std::string& str)
{
    std::cout << backGroundCyan_ << str << colorOff_ << std::endl;
}

void Color::backGroundBlue(const std::string& str)
{
    std::cout << backGroundBlue_ << str << colorOff_ << std::endl;
}

void Color::backGroundGreen(const std::string& str)
{
    std::cout << backGroundGreen_ << str << colorOff_ << std::endl;
}

void Color::backGroundBlack(const std::string& str)
{
    std::cout << backGroundBlack_ << str << colorOff_ << std::endl;
}

void Color::backGroundWhite(const std::string& str)
{
    std::cout << backGroundWhite_ << str << colorOff_ << std::endl;
}

void Color::backGroundYellow(const std::string& str)
{
    std::cout << backGroundYellow_ << str << colorOff_ << std::endl;
}

void Color::backGroundMagenta(const std::string& str)
{
    std::cout << backGroundMagenta_ << str << colorOff_ << std::endl;
}