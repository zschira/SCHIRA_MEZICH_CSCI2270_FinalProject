#include "Baseball.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

Baseball::Baseball()
{
    headA = NULL;
    headB = NULL;//ctor
}

Baseball::~Baseball()
{
    //dtor
}

int Baseball::mainMenu()
{   int option = 0;
    cout << "Main Menu" << endl;
    cout << "1: Start new scorecard" << endl;
    cout << "2: Simulate Game" << endl;
    cout << "3: Quit" << endl;
    cin >> option;
    return option;
}

void Baseball::buildLineups(bool sim)
{
    cout << "New Score Card" << endl;
    teamA(sim);
    batter *tmpA = headA;
    cout << "Line up for team A:" << endl;
    int i = 1;
    while(tmpA->next != NULL)
    {
        tmpA = tmpA->next;
        cout << "Batter " << i << ": #";
        cout << tmpA->number << " Average: " << tmpA->avg<<endl;
        i++;
    }
    teamB(sim);
    batter *tmpB = headB;
    cout << "Line up for team B:" << endl;
    int j = 1;
    while(tmpB->next != NULL)
    {
        tmpB = tmpB->next;
        cout << "Batter " << j << ": #";
        cout << tmpB->number << " Average: " << tmpB->avg<< endl;
        j++;
    }
}

void Baseball::teamA(bool sim)
{
    int num = 0;
    headA = new batter;
    batter *current = headA;
    cout << "Please enter line up for team A (player numbers)" << endl;
    for(int i = 0; i < 9; ++i)
    {
        bool valid = false;
        int j = i;
        cout << "Batter " << j+1 << endl;
        while(!valid)
        {
            valid = true;
            cout << "enter player number: ";
            cin >> num;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "Please enter an Integer only." << endl;
                valid = false;
            }
        }
        batter *tmp = new batter;
        tmp->number = num;
        if(!sim)
        {
            tmp->avg=0;
            tmp->hits = 0;
            tmp->atbats = 0;
        }
        else
        {
            tmp->atbats=99;
            tmp->hits=rand()%40+20;
            calcAvg(tmp,0);
        }
        current->next = tmp;
        current = tmp;

    }
}

void Baseball::teamB(bool sim)
{
    int num = 0;
    headB = new batter;
    batter *current = headB;
    cout << "Please enter line up for team B (player numbers)" << endl;
    for(int i = 0; i < 9; ++i)
    {
        bool valid = false;
        int j = i;
        cout << "Batter " << j+1 << endl;
        while(!valid)
        {
            valid = true;
            cout << "enter player number: ";
            cin >> num;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "Please enter an Integer only." << endl;
                valid = false;
            }
        }
        batter *tmp = new batter;
        tmp->number = num;
        tmp->avg = 0;
        tmp->atbats = 0;
        if(!sim)
        {
            tmp->avg=0;
            tmp->hits = 0;
            tmp->atbats = 0;
        }
        else
        {
            tmp->atbats=99;
            tmp->hits=rand()%40+20;
            calcAvg(tmp,0);
        }
        current->next = tmp;
        current = tmp;
    }
}

void Baseball::scorecard(bool sim)
{
    cout << "PLAY BALL!" << endl;
    bool top;
    int inning = 1;
    int scoreA = 0;
    int scoreB = 0;
    batter *leadoffA = headA->next;
    batter *leadoffB = headB->next;
    while(inning <= 9)
    {
        //team A at bat first
        top = true;
        inningAnnouncement(inning, top);
        batter *currentA = leadoffA;
        scoreA = keepScore(scoreA,currentA,top,sim);

        //team B at bat second
        if((scoreB>scoreA)&&(inning==9))
        {
            break;
        }
        top = false;
        inningAnnouncement(inning, top);
        batter *currentB = leadoffB;
        scoreB = keepScore(scoreB,currentB, top,sim);

        inning++;
    }
    while(scoreA==scoreB)
    {
        top = true;
        inningAnnouncement(inning, top);
        batter *currentA = leadoffA;
        scoreA = keepScore(scoreA,currentA,top,sim);

        //team B at bat second
        top = false;
        inningAnnouncement(inning, top);
        batter *currentB = leadoffB;
        scoreB = keepScore(scoreB,currentB, top,sim);

        inning++;
    }
    cout << "Game Over" << endl;
    cout << "Final Score: " << endl;
    cout << "Team A - " << scoreA << endl;
    cout << "Averages: " << endl;
    batter *tmpA = headA;
    cout << "Line up for team A:" << endl;
    int i = 1;
    while(tmpA->next != NULL)
    {
        tmpA = tmpA->next;
        cout << "Batter " << i << ": #";
        cout << tmpA->number << " Average: " << tmpA->avg << endl;
        i++;
    }
    cout << "Team B - " << scoreB << endl;
    cout << "Averages: " << endl;
    batter *tmpB = headB;
    cout << "Line up for team B:" << endl;
    int j = 1;
    while(tmpB->next != NULL)
    {
        tmpB = tmpB->next;
        cout << "Batter " << j << ": #";
        cout << tmpB->number << " Average: " << tmpB->avg<<endl;
        j++;
    }
}

void Baseball::inningAnnouncement(int inning,bool top)
{
    string half = "Top";
    string team = "A";
    if(!top)
    {
        half = "Bottom";
        team = "B";
    }
    if((inning==10)&&(top))
    {
        cout<<"Extra innings!"<<endl;
    }
    cout << "Team " << team << " at bat" << endl;
    if(inning == 1)
    {
        cout << half << " of the " << inning << "st inning" << endl;
    }
    else if(inning == 2)
    {
        cout << half << " of the " << inning << "nd inning" << endl;
    }
    else if(inning == 3)
    {
        cout << half << " of the " << inning << "rd inning" << endl;
    }
    else
    {
        cout << half << " of the " << inning << "th inning" << endl;
    }
}

int Baseball::keepScore(int score,batter *current, bool top, bool sim)
{
    int outs = 0;
    int first = 0;
    int second = 0;
    int third = 0;
    int atBat;

    cout << "Please enter the results of each at bat: " << endl;

    while(outs != 3)
    {
        double hit = 0;
        if(!sim)
        {
            cout << "Batter #" << current->number << ":" << endl;
            cout << "0: out" << endl;
            cout << "1: single" << endl;
            cout << "2: double" << endl;
            cout << "3: triple" << endl;
            cout << "4: home run" << endl;
            cin >> atBat;
        }
        else
        {
            float ishit;
            ishit=floor(static_cast <float> (rand()) / static_cast <float> (RAND_MAX)+current->avg);
            if(ishit==0)
            {
                atBat=0;
            }
            else
            {
                atBat=1;
            }
            atBat=atBat*(rand()%4+1);
        }
        //int hit = 0;

        //hit = current->avg+static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        //atBat = atBat * (rand()%4 +1);
        /*for(int i = 0; i < 9; i ++)
        {
            bases[i] = 0;
        }
        bases[9] = 1;
        bases[10] = 1;
        bases[11] = 1;
        bases[12] = 2;
        bases[13] = 3;
        bases[14] = 4;
        int index = rand%15;
        atBat = bases[index];*/
        if(atBat != 0)
        {
            hit = 1;
        }
        calcAvg(current,hit);
        if(atBat == 0)
        {
            cout << "Batter #" << current->number << " is out" << endl;
            outs++;
            cout << outs << " out(s)" << endl;
        }
        if(atBat == 1)
        {
            cout << "Batter #" << current->number << " singled" << endl;
            if(third == 1)
            {
                score++;
                third = 0;
            }
            if(second == 1)
            {
                third = 1;
                second = 0;
            }
            if(first == 1)
            {
                second = 1;
            }
            first = 1;
        }
        else if(atBat == 2)
        {
            cout << "Batter #" << current->number << " doubled" << endl;
            if(third == 1)
            {
                score++;
                third = 0;
            }
            if(second == 1)
            {
                score++;
                second = 0;
            }
            if(first == 1)
            {
                third = 1;
            }
            second = 1;
            first = 0;
        }
        else if(atBat == 3)
        {
            cout << "Batter #" << current->number << " tripled" << endl;
            if(third == 1)
            {
                score++;
                third = 0;
            }
            if(second == 1)
            {
                score++;
                second = 0;
            }
            if(first == 1)
            {
                score++;
                first = 0;
            }
            first = 0;
            second = 0;
            third = 1;
        }
        else if(atBat == 4)
        {
            score++;
            cout << "Batter #" << current->number << " homered" << endl;
            if(third == 1)
            {
                score++;
                third = 0;
            }
            if(second == 1)
            {
                score++;
                second = 0;
            }
            if(first == 1)
            {
                score++;
                first = 0;
            }
            first = 0;
            second = 0;
            third = 0;
        }
        if(current->next == NULL)
        {
            if(top)
            {
                current = headA->next;
            }
            else
            {
                current = headB->next;
            }

        }
        else
        {
            current = current->next;
        }
    }
    return score;
}

void Baseball::calcAvg(batter *player, double hit)
{
    player->hits = player->hits+ hit;
    player-> atbats = player->atbats + 1;
    player -> avg = (player->hits)/(player->atbats);
}
