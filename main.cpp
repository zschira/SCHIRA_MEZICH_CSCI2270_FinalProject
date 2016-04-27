#include <iostream>
#include "Baseball.h"
using namespace std;


int main()
{
    Baseball B;

    int option = 0;
    while(option != 3)
    {
        option = B.mainMenu();
        switch(option)
        {
        case 1:
            {
                B.buildLineups();
                B.scorecard();
            }break;
        case 2:
            {

            }break;
        }
    }
    if(option == 3)
    {
        cout << "Goodbye" << endl;
    }
    return 0;
}
