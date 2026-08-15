#include <iostream>
#include <cmath>
using namespace std ;

void Calculator () {

    string choice ;
    float a , b ;
    
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
}

int main () {
    Calculator () ;

    return 0 ;
}