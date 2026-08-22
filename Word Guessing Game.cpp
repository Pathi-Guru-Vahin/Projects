
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std ;

struct guessed {
    int no ;
    char let ;
    bool st ;
} ;


void Word_Guessing_Game() {

    string arr[] = { "delhi" , "mumbai" , "banglore" , "chennai" } ;
    int l1 = sizeof(arr) / sizeof(arr[0]) ;
    srand(time(0)) ;
    int a = rand() % l1 + 1 ;
    string word = arr[a - 1] ;
    int n = 0 ;          // Correctly guessed positions
    int count = 0 ;      // Number of guesses stored
    int lives = 5 ;      // Lives remaining
    // Maximum possible guesses = 5 lives + word length
    struct guessed guesses[20] = {} ;
    bool won = false ;

    cout << "NOTE : enter lower case letters for guessing\n" ;
    cout << "You have 5 lives\n" ;
    cout << "...................................................\n" ;
    // Initial display
    for ( int i = 0 ; i < word.length() ; i ++ ) {
        cout << "_ " ;
    }
    cout << "\n" ;

    while ( lives > 0 ) {

        char guess ;
        int pos ;
        cout << "Enter the position where the letter should be placed : \n" ;
        cin >> pos ;
        // Check valid position
        if ( pos < 1 || pos > word.length() ) {
            cout << "Invalid position. Try again.\n" ;
            continue ;
        }

        cout << "Enter the letter for guessing : \n" ;
        cin >> guess ;
        bool isThere = false ;
        // Check whether this position was already correctly guessed
        for ( int i = 0 ; i < count ; i ++ ) {
            if ( guesses[i].no == pos && guesses[i].st == true ) {
                cout << "You have already guessed this position\n" ;
                isThere = true ;
                break ;
            }
        }

        if ( isThere ) {
            continue ;
        }

        // Store the new guess
        guesses[count].no = pos ;
        guesses[count].let = guess ;
        guesses[count].st = false ;

        // Check whether guess is correct
        if ( guess == word[pos - 1] ) {
            guesses[count].st = true ;
            n ++ ;
            cout << "Correct guess!\n" ;
        } else {
            lives -- ;
            cout << "Wrong guess!\n" ;
        }
        count ++ ;

        // Display current word
        for ( int i = 0 ; i < word.length() ; i ++ ) {
            bool found = false ;
            for ( int j = 0 ; j < count ; j ++ ) {
                if ( guesses[j].no == i + 1 && guesses[j].st == true ) {
                    cout << guesses[j].let ;
                    found = true ;
                    break ;
                }
            }
            if ( !found ) {
                cout << "_" ;
            }
            cout << " " ;
        }
        cout << "\n" ;
        // Check win
        if ( n == word.length() ) {
            cout << "CONGRATULATIONS! You have guessed the word\n" ;
            won = true ;
            break ;
        }
        cout << "You have " << lives << " lives left\n" ;
    }

    // Game lost
    if ( !won ) {
        cout << "\nYou have lost the game\n" ;
        cout << "The word was: " << word << "\n" ;
    }
}

int main () {

    Word_Guessing_Game () ;

    return 0 ;
}