#ifndef _COLOR_H_
#define _COLOR_H_

#include <string>

class Color
{
    private:
        std::string colorOff_;
    
        std::string fontRed_;
        std::string fontCyan_;
        std::string fontBlue_;
        std::string fontGreen_;
        std::string fontBlack_;
        std::string fontWhite_;
        std::string fontYellow_;
        std::string fontMagenta_;

        std::string backGroundRed_;
        std::string backGroundCyan_;
        std::string backGroundBlue_;
        std::string backGroundGreen_;
        std::string backGroundBlack_;
        std::string backGroundWhite_;
        std::string backGroundYellow_;
        std::string backGroundMagenta_;

    public:
        Color();
        ~Color();

        void fontRed(const std::string& str);
        void fontCyan(const std::string& str);
        void fontBlue(const std::string& str);
        void fontGreen(const std::string& str);
        void fontBlack(const std::string& str);
        void fontWhite(const std::string& str);
        void fontYellow(const std::string& str);
        void fontMagenta(const std::string& str);

        void backGroundRed(const std::string& str);
        void backGroundCyan(const std::string& str);
        void backGroundBlue(const std::string& str);
        void backGroundGreen(const std::string& str);
        void backGroundBlack(const std::string& str);
        void backGroundWhite(const std::string& str);
        void backGroundYellow(const std::string& str);
        void backGroundMagenta(const std::string& str);
};
#endif