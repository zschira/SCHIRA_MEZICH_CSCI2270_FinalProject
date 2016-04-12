#include<iostream>
#include <string>
#include <cstdlib>
#include<iomanip>

using namespace std;

int main()
{
	char rerun = 'Y';
	
    while ( rerun == 'Y' || rerun == 'y'  )
    {
        int input;
		int isprime;
		int modulus;
        
        cout << "Please enter a positive integer you would like to evalutate: ";
		cin >> input;
		
		for ( int i = 2; i < input; i++ )
		{
			modulus = input % i;
			
			if ( modulus == 0 )
			{
				isprime = 1;
				break;
			}
			else
			{
				isprime = 0;
			}
		}
		
		if ( isprime == 1 )
		{
			cout << input << " is not a prime number." << endl;
		}
		else
		{
				cout << input << " is a prime number." << endl;
		}
		
		cout << "Would you like to check another integer? (Y/N) ";
		cin >> rerun;
		
		system("clear");
    }  
    
    return 0;
}
