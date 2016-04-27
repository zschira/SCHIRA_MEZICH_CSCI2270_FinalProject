#include <iostream>
#include "Baseball.h"
using namespace std;


int main()
{
    Baseball B;
    bool sim;
    int option = 0;
    while(option != 3)
    {
        option = B.mainMenu();
        switch(option)
        {
        case 1:
            {
                B.buildLineups();
                sim = false;
                B.scorecard(sim);
            }break;
        case 2:
            {
                B.buildLineups();
                sim = true;
                B.scorecard(sim);
            }break;
        }
    }
    if(option == 3)
    {
        cout << "Goodbye" << endl;
    }
    return 0;
}
