#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std ;

void print_arr( string arr , int n ) {
    for ( int i = 0 ; i < n ; i ++ ) {
        cout << arr[i] ;
        cout << " " ;
    }
}

void Hangman () {

    string arr[] = { "apple", "banana", "mango", "orange", "grape", "papaya", "pineapple", "watermelon", "strawberry", "kiwi", "guava", "cherry", "peach", "pear", "coconut" } ;
    int l1 = sizeof(arr) / sizeof(arr[0]) ;
    int a = rand() % l1 + 1 ;
    string word = arr[a - 1] ;
    string main(word.length(), '_') ;
    bool isDone = false , won = false ;
    int lives = 5 ;

    cout << "You have 5 lives.\n" ;
    cout << ".....................\n" ;
    print_arr ( main , word.length() ) ;
    cout << "\n" ;

    while ( !isDone ) {
        char guess ;
        cout << "Enter your guess : " ;
        cin >> guess ;
        guess = tolower(guess) ;

        bool isThere = false ;
        for ( int i = 0 ; i < word.length() ; i ++ ) {
            if ( word[i] == guess ) {
                isThere = true ;
                break ;
            } 
        }

        if ( !isThere ) {
            lives -- ;
            cout << "Your guess was wrong. You have " << lives << " lives remaining.\n" ;
        }

        if ( lives == 0 ) {
            won = false ;
            break ;
        }

        if ( isThere ) {
            for ( int j = 0 ; j < word.length() ; j ++ ) {
                if ( word[j] == guess && main[j] == '_' ) {
                    main[j] = guess ;
                }
            }
            print_arr ( main , word.length() ) ;
            cout << "\n" ;
        }

        isDone = true ;

        for ( int i = 0 ; i < word.length() ; i ++ ) {
            if ( main[i] == '_' ) {
                isDone = false ;
                break ;
            } 
        }
        if ( isDone ) {
            won = true ;
        }
    }

    if (won) {
        cout << "............CONGRATULATIONS.............\nYou have guessed the word correctly" ;
    } else {
        cout << "You lost the game\n" ;
        cout << "Your word was " << word ;
    }

}

int main () {
    
    srand(time(0)) ;
    Hangman () ;

    return 0 ;
}