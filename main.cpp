#include <iostream>
#include "Baseball.h"
using namespace std;

int mainMenu()
{   int option = 0;
    cout << "Main Menu" << endl;
    cout << "1: Start new scorecard" << endl;
    cout << "2: Simulate Game" << endl;
    cout << "3: Quit" << endl;
    cin >> option;
    return option;
}
int main()
{
    Baseball B;

    int option = 0;
    while(option != 3)
    {
        option = mainMenu();
        switch(option)
        {
        case 1:
            {
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
