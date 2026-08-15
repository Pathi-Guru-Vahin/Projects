#include <iostream>
#include <cmath>
using namespace std ;

void Scientific_Calculator () {

    char opt ;

    do {
        int n ;
        cout << "How many values are you going to input ( 1 / 2 ) ? : " ;
        cin >> n ;
        if ( n == 2 ) {
            string choice ;
            double a , b ;
            
            cout << "Please enter the expression with spaces \n" ;
            cout << "Enter your expression : \n" ;
            cin >> a >> choice >> b ;

            if ( choice == "+" ) {
                cout << "=" << a + b ;
            } else if ( choice == "-" ){
                cout << "=" << a - b ;
            } else if ( choice == "*" ) {
                cout << "=" << a * b ;
            } else if ( choice == "/" ) {
                if ( b == 0 ) {
                    cout << "Zero division error" ;
                } else {
                    cout << "=" << a / b ;
                }
            } else if ( choice == "^" ) {
                cout << "=" << pow ( a , b ) ;
            } else {
                cout << "You have entered an invalid operator. Run the program again." ;
            }
        } else if ( n == 1 ) {
            cout << "1. Square Root of a number \n" ;
            cout << "2. Sine of a number \n" ;
            cout << "3. Cosine of a number \n" ;
            cout << "4. Tangent of a number \n" ;
            cout << "5. Logarithm of the function \n" ;
            cout << "NOTE : for sine , cosine and tangent use radians. \n" ;

            int ch ;
            double a ;
            cout << "Enter your choice : " ;
            cin >> ch ;
            cout << "Enter a number to use these operations : " ;
            cin >> a ;
            
            if ( ch == 1 ) {
                if ( a < 0 ) {
                    cout << "Square root of a negative number is undefined." ;
                } else {
                    cout << "=" << sqrt(a) ;
                }
            } else if ( ch == 2 ){
                cout << "=" << sin(a) ;
            } else if ( ch == 3 ) {
                cout << "=" << cos(a) ;
            } else if ( ch == 4 ) {
                cout << "=" << tan(a) ;
            } else if ( ch == 5 ) {
                if ( a <= 0 ) {
                    cout << "Logarithm is only defined for positive numbers." ;
                } else {
                    cout << "=" << log(a) ;
                }
            } else {
                cout << "You have entered the wrong choice" ;
            }
        } else {
            cout << "Please enter either 1 or 2.";
        }
        cout << "\nDo you want the program to run again ? ( y / n ) : " ;
        cin >> opt ;
    } while ( opt == 'y' || opt == 'Y' ) ;
}

int main () {
    Scientific_Calculator () ;

    return 0 ;
}