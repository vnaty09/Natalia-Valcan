#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int  n,randomNumber,attempt=10,attemptUser=0;
    
    srand(time(0));
    randomNumber=rand()%101;
    cout<<"Welcome to Guess the number!"<<endl;
    cout<<"Enter a  number: "<<endl;
    while(true)
    {cout<<"what's your guess"<<endl;
    cin>>n;
    attemptUser++;
        if(randomNumber<attempt){
            cout<<"Too high.Try again"<<endl;
            attempt--;
        }
        
        if(randomNumber>attemptUser){
            cout<<"Too low"<<endl;
            attempt--;
        }
        
        if(randomNumber==attemptUser){
            cout<<"Well done!That is the number!"<<endl;
            attempt--;break;} 

        if(attempt==0){
            cout<<"No more attempts"<<endl;
            return 0;
        }
    }
   return 0;
}