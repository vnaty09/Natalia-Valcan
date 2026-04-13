#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int n,randomNumber,attempt=10,attemptUser=0;
    
    srand(time(0));
    randomNumber=rand()%101;
    cout<<"Welcome to Guess the number!"<<endl;
    cout<<"Enter a  number: "<<endl;
    while(attempt!=0)
    {cout<<"what's your guess"<<endl;
    cin>>n;
    attemptUser++;
        if(randomNumber<attemptUser){
            cout<<"Too high.Try again"<<endl;
            attempt--;
            cout<<"You still have "<<attempt<<" attempts"<<endl; 
        }
        
        if(randomNumber>attemptUser){
            cout<<"Too low.Try again"<<endl;
            attempt--;
            cout<<"You still have "<<attempt<<" attempts"<<endl;
        }
        
        if(randomNumber==attemptUser){
            cout<<"Well done!That's the number! You won the game!"<<endl;
            attempt--;
            cout<<"You guessed the number in "<<attempt<<" attempts"<<endl;
            break;}

        if(attempt==0){
            cout<<"No more attempts. You lost"<<endl;
            return 0;
        }
    }
   return 0;
}