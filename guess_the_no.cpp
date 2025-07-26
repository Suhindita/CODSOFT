#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    cout<<"\nGuess the number I've generated.\n"<<endl;
    int min_val = 1;
    int max_val = 100;
    int number = min_val + (rand() % (max_val - min_val + 1));
    // cout<<number<<endl;
    int guess;
    cout<<"Enter the number you guessed: "<<endl;
    cin>>guess;
    
    if(guess!=number){
        while(guess!=number){
            if(guess < number) {
            cout<<"Guessed number is lesser."<<endl;
            }
            else if(guess > number) {
            cout<<"Guessed number is greater."<<endl;
            }
           cout<<"Guess again: "<<endl;
           cin>>guess;
           if (cin.fail()) {
                throw runtime_error("Invalid input.");
            }
        }
        
        cout<<"Congratulations, you guessed correctly.\n"<<endl;

    }
    
   
    
    return 0;
}