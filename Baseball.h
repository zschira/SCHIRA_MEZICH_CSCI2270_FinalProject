#ifndef BASEBALL_H
#define BASEBALL_H
#include <string>

using namespace std;

struct batter
{
    int number;
    double hits;
    double avg;
    int slg;
    int obp;
    int rbi;
    int runs;
    int b1;
    int b2;
    int b3;
    int b4;
    int bt;
    double atbats;
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
        void scorecard(bool sim);
        batter *halfInning(batter *current);
        void buildLineups(bool sim);
        void teamA(bool sim);
        void teamB(bool sim);
        void inningAnnouncement(int inning, bool top);
        int keepScore(int score,batter*current, bool top, bool sim);
        void calcAvg(batter *player, double hit);
        void calcOBP();
        void calcSLG();
    protected:
    private:
        batter *headA;
        batter *headB;
        batter *up;
        int bases[15];
};

#endif // BASEBALL_H
