#ifndef BASEBALL_H
#define BASEBALL_H
#include <string>

using namespace std;

struct batter
{
    int team;
    int number;
    int avg;
    int slg;
    int obp;
    int rbi;
    int runs;
    int b1;
    int b2;
    int b3;
    int b4;
    bool inthehole = false;
    batter *next;
};
class Baseball
{
    public:
        Baseball();
        ~Baseball();
        void scorecard();
    protected:
    private:
        void teamA();
        void teamB();
        batter *leadoffA;
        batter *leadoffB;
};

#endif // BASEBALL_H
