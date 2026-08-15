#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void num_guess_game() {
    cout << "\n..........YOU ARE PLAYING THE NUMBER GUESSING GAME CURRENTLY..........\n" ;
    int j ;
    cout << "Enter the number till which you want to guess from 0 to ";
    cin >> j ;
    int num = rand() % (j + 1) ;
    int inp = -1 , i = 0 ; 
    while ( num != inp ) { 
        cout << "Enter a number for guessing between 0 to "<< j <<": " ;
        cin >> inp ;
        if ( inp > num ) { 
            cout << "too HIGH \n" ; 
        } else if ( inp < num ){ 
            cout << "too LOW \n" ; 
        } else if ( inp > j) {
            cout << "Please enter a number in the range mentioned by you" ;
        }
        i ++ ;   
    }
    cout << "..............CONGRATULATIONS.............. \n" ; 
    cout << "you have guessed the number correctly after " << i << " turns" ; 
}

int main() {
    srand(time(0));
    num_guess_game() ;

    return 0;
}