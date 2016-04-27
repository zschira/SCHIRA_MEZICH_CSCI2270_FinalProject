#include <iostream>
#include "Baseball.h"
using namespace std;


int main()
{
    Baseball B;
    bool sim;
    bool stats=false;
    int option = 0;
    while(option != 3)
    {
        option = B.mainMenu();
        switch(option)
        {
        case 1:
            {
                sim = false;
                B.buildLineups(sim);
                B.scorecard(sim);
                stats=true;
            }break;
        case 2:
            {
                sim = true;
                if(!stats)
                {
                    B.buildLineups(sim);
                    B.scorecard(sim);
                }
                else
                {
                    string ans;
                    cout<<"Use current lineup? (Y/N): ";
                    cin>>ans;
                    if(ans=="Y")
                    {
                        B.scorecard(sim);
                    }
                    else
                    {
                        B.buildLineups(sim);
                        B.scorecard(sim);
                    }
                }
                stats=true;
            }break;
        }
    }
    if(option == 3)
    {
        cout << "Goodbye" << endl;
    }
    return 0;
}
