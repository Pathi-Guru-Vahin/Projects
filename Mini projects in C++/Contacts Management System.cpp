#include <iostream>
#include <string>
using namespace std;

struct Contact {
    string name;
    int phone;
    string email;
};

int main () {
    Contact contacts[100];
    int choice;
    int n = 0;

    while ( true ) {
        cout << "\n1. Add Contacts\n" ;
        cout << "2. Search Contact\n" ;
        cout << "3. Delete Contact\n" ;
        cout << "4. Display Contacts\n" ;
        cout << "5. Exit\n" ;

        cout << "Enter your choice (1-5): " ;
        cin >> choice ;

        switch ( choice ) {
            case 1: {                                                        /// Adding Contact
                cout << "You have selected 1\n" ;

                int no ;
                cout << "How many contacts do you want to add : \n" ;
                cin >> no ;

                cin.ignore() ;

                for ( int i = n ; i < n + no ; i++ ) {
                    cout << "Enter the name : \n";
                    getline( cin , contacts[i].name );

                    cout << "Enter the phone number : \n" ;
                    cin >> contacts[i].phone ;

                    cout << "Enter the email : \n" ;
                    cin >> contacts[i].email ;

                    cin.ignore() ;
                }

                n += no ;
                break ;
            }
            case 2: {                                                        /// Searching Contact
                cout << "You have selected 2\n" ;

                string name2 ;
                cout << "Enter the name of the contact : \n" ;

                cin.ignore() ;
                getline( cin , name2 ) ;

                bool found = false ;

                for ( int i = 0 ; i < n ; i++ ) {
                    if ( name2 == contacts[i].name ) {
                        cout << " | " << contacts[i].name
                             << " | " << contacts[i].phone
                             << " | " << contacts[i].email
                             << " |\n" ;

                        found = true ;
                    }
                }

                if ( !found ) {
                    cout << "Contact not found\n" ;
                }

                break ;
            }
            case 3: {                                                        /// Deleting Contact***
                cout << "You have selected 3\n" ;

                string name3 ;
                cout << "Enter the name of the contact to be deleted: " ;

                cin.ignore() ;
                getline( cin , name3 ) ;

                int index = -1 ;

                for ( int i = 0 ; i < n ; i++ ) {
                    if ( contacts[i].name == name3 ) {
                        index = i ;
                        break ;
                    }
                }

                if ( index != -1 ) {
                    for ( int i = index ; i < n - 1 ; i++ ) {
                        contacts[i] = contacts[i + 1] ;
                    }

                    n-- ;

                    cout << "Contact deleted successfully!\n" ;
                }
                else {
                    cout << "Contact not found\n" ;
                }

                break ;
            }
            case 4: {                                                        /// Display Contacts
                cout << "You have selected 4\n" ;

                if ( n == 0 ) {
                    cout << "No contacts available.\n" ;
                }

                for ( int i = 0 ; i < n ; i++ ) {
                    cout << " | " << contacts[i].name
                         << " | " << contacts[i].phone
                         << " | " << contacts[i].email
                         << " |\n" ;
                }

                break ;
            }
            case 5: {                                                        /// Exit
                cout << "Exiting program...\n" ;
                return 0;
            }
            default:
                cout << "Invalid choice!\n" ;
        }
    }
    return 0;
}