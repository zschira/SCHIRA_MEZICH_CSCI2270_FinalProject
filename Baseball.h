#ifndef BASEBALL_H
#define BASEBALL_H
#include <string>

using namespace std;

struct batter
{
    int number;
    int hits;
    float avg;
    int slg;
    int obp;
    int rbi;
    int runs;
    int b1;
    int b2;
    int b3;
    int b4;
    int bt;
    int atbats;
    bool ondeck = false;
    batter *previous;
    batter *next;
};
class Baseball
{
    public:
        Baseball();
        ~Baseball();
        int mainMenu();
        void scorecard();
        batter *halfInning(batter *current);
        void buildLineups();
        void teamA();
        void teamB();
        void inningAnnouncement(int inning, bool top);
        int keepScore(int score,batter*current, bool top);
        void calcAvg(batter *player, int hit);
        void calcOBP();
        void calcSLG();
    protected:
    private:
        batter *headA;
        batter *headB;
        batter *up;
};

#endif // BASEBALL_H
