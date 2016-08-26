#ifndef _SCORE_H_
#define _SCORE_H_

class Score
{
private:
    int x_;
    int y_;
    int lifeSycle_;

public:
    Score();
    ~Score();

    void setPlace(int x, int y);
    void setLife(int sycle);
    void lifeScore();
    int getLife();
    
};

#endif