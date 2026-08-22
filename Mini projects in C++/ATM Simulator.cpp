#include <iostream>
#include <cctype>
using namespace std ;

struct History {
    string action ;
    float amount ;
};

int main () {
    char opt2 = 'y' ;
    int n = 0 ;
    float balance = 0 ;
    History h[100] = {} ;
    while ( opt2 == 'y' ) {
        cout << "\n1. Depostit Money\n" ;
        cout << "2. Withdraw Money\n" ;
        cout << "3. Print Balance\n" ;
        cout << "4. Transaction History\n" ;
        cout << "5. Exit\n" ;
        int opt1 ;
        cout << "Enter your option  : " ;
        cin >> opt1 ;
        switch ( opt1 ) {
            case 1 : {
                int amt ;
                cout << "Enter the amount you want to deposit : " ;
                cin >> amt ;
                if ( amt <= 0 ) {
                    cout << "invalid amount" ;
                    continue ;
                }
                balance = balance + amt ;
                h[n].action = "Deposited" ;
                h[n].amount = amt ;
                n ++ ;
                break ;
            }
            case 2 : {
                int amt ;
                cout << "Enter the amount you want to withdraw : " ;
                cin >> amt ;
                if ( amt <= 0 ) {
                    cout << "invalid amount" ;
                    continue ;
                } 
                if ( amt > balance ) {
                    cout << "Inufficient Amount to Withdraw" ;
                    break ;
                } else {
                    balance = balance - amt ;
                    h[n].action = "Withdrawn" ;
                    h[n].amount = amt ;
                    n ++ ;
                }
                break ;
            }
            case 3 : {
                cout << "The balance in your account is " << balance ;
                break ;
            }
            case 4 : {
                for ( int i = 0 ; i < n ; i++ ) {
                    cout << h[i].action << " || " << h[i].amount << "\n" ;
                }
                break ;
            }
            case 5 : {
                cout << "You are exiting the program . None of the details is / are not going to be saved " ;
                return 0 ;
            }
            default: {
                cout << " Invalid Option. Please try again later " ;
                break;
            }
        }

        cout << "Do you want to do another operation" ;
        cin >> opt2 ;
        opt2 = tolower(opt2) ;
    }

    return 0 ;
}