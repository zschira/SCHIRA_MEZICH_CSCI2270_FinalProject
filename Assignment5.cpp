#include "Queue.h"
using namespace std;
Queue::Queue(int qs)
{
    queueSize=qs;
    arrayQueue=new string[queueSize];
    queueHead=0;
    queueTail=0;
    queueCount=0;
}

Queue::~Queue()
{
    //dtor
}
void Queue::enqueue(string word)
{
    if(queueIsFull())
    {
        cout<<"Queue is full."<<endl;

    }
    else
    {
        if(queueTail==queueSize-1)
        {
            arrayQueue[queueTail]=word;
            queueTail=0;
            cout<<"E: "<<word<<endl;
            cout<<"H: "<<queueHead<<endl;
            cout<<"T: "<<queueTail<<endl;
        }
        else
        {
            arrayQueue[queueTail]=word;
            queueTail++;
            cout<<"E: "<<word<<endl;
            cout<<"H: "<<queueHead<<endl;
            cout<<"T: "<<queueTail<<endl;
        }
        queueCount++;
    }
}
string Queue::dequeue()
{
    string word=arrayQueue[queueHead];
    if(queueIsEmpty())
    {
        cout<<"Queue is empty."<<endl;
    }
    else
    {
        if(queueHead==queueSize-1)
        {
            queueHead=0;
        }
        else
        {
            queueHead++;
        }
        cout<<"H: "<<queueHead<<endl;
        cout<<"T: "<<queueTail<<endl;
        cout<<"word: "<<word<<endl;
        queueCount--;
    }
    return word;
}
void Queue::printQueue()
{
    if(queueIsEmpty())
    {
        cout<<"Empty"<<endl;
    }
    else
    {
        for(int i=queueHead;i<queueTail;i++)
        {
            cout<<i<<": "<<arrayQueue[i]<<endl;
        }
    }
}
bool Queue::queueIsFull()
{
    if(queueCount==queueSize)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Queue::queueIsEmpty()
{
    if(queueCount==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


#include <iostream>
#include <string>
#include "Queue.h"
#include <fstream>
#include <sstream>
#include<cstdlib>

using namespace std;


int main()
{
    Queue qu(10);
    int selec=1;
    while((selec<5)&&(selec>0))
    {
        cout<<"======Main Menu====="<<endl;
        cout<<"1. Enqueue word"<<endl;
        cout<<"2. Dequeue word"<<endl;
        cout<<"3. Print queue"<<endl;
        cout<<"4. Enqueue sentence"<<endl;
        cout<<"5. Quit"<<endl;
        cin>>selec;
        if(selec==1)
        {
            string word;
            cout<<"word: ";
            getline(cin,word);
            getline(cin,word);
            qu.enqueue(word);

        }
        if(selec==2)
        {
            qu.dequeue();
        }
        if(selec==3)
        {
            qu.printQueue();
        }
        if(selec==4)
        {
            string sentence;
            string word;
            cout<<"sentence: ";
            getline(cin,sentence);
            getline(cin,sentence);
            stringstream ss(sentence);
            while(ss>>word)
            {
                qu.enqueue(word);
            }
        }
    }
    cout<<"Goodbye!"<<endl;
    return 0;
}
