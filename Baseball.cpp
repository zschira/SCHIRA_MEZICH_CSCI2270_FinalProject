#include "Baseball.h"
#include <string>
#include <iostream>

using namespace std;

Baseball::Baseball()
{
    //ctor
}

Baseball::~Baseball()
{
    //dtor
}

void Baseball::scorecard()
{
    cout << "New Score Card" << endl;
    teamA();
}

void Baseball::teamA()
{
    cout << "Please enter line up for team A (player numbers)" << endl;
    for(int i = 0; i < 9; i++)
    {
        int num = 0;
        batter *current = new batter;
        cout << "Batter " << i+1 << endl;
        cout << "enter player number: ";
        cin >> num;
        current->number = num;
        current->next = NULL;
    }
}
