#include <iostream>
#include <cctype>
using namespace std ;

struct quiz {
    string questions ;
    char answers ;
} ;

void Quiz () {

    int count = 0 ;
    quiz q[10] = {
        { "What is the capital of Australia?\nA) Sydney\nB) Melbourne\nC) Canberra\nD) Perth" , 'C' } ,
        
        { "Which is the largest planet in our Solar System?\nA) Earth\nB) Jupiter\nC) Saturn\nD) Neptune" , 'B' } ,
        
        { "Who is known as the Father of the Nation in India?\nA) Jawaharlal Nehru\nB) Sardar Patel\nC) Mahatma Gandhi\nD) B. R. Ambedkar" , 'C'} ,
        
        { "How many continents are there on Earth?\nA) 5\nB) 6\nC) 7\nD) 8" , 'C' } ,
        
        { "Which country is famous for the Great Wall?\nA) Japan\nB) China\nC) South Korea\nD) Thailand" , 'B' } ,
        
        { "Who wrote the Indian national anthem?\nA) Rabindranath Tagore\nB) Bankim Chandra Chattopadhyay\nC) Sarojini Naidu\nD) Subramania Bharati" , 'A' } ,
        
        { "Which is the smallest prime number?\nA) 0\nB) 1\nC) 2\nD) 3" , 'C'} ,
        
        { "Which ocean is the largest?\nA) Atlantic Ocean\nB) Indian Ocean\nC) Pacific Ocean\nD) Arctic Ocean" , 'C' } ,
        
        { "Which gas is most abundant in Earth's atmosphere?\nA) Oxygen\nB) Nitrogen\nC) Carbon dioxide\nD) Hydrogen" , 'B' } ,
        
        { "Which is the longest river in the world traditionally recognized in general-knowledge quizzes?\nA) Amazon\nB) Nile\nC) Yangtze\nD) Mississippi" , 'B' }
    } ; 

    for (int i = 0 ; i < 10 ; i ++ ) {
        char ans ;
        cout << q[i].questions ;
        cout << "\nEnter your answer (Option) : " ;
        cin >> ans ;
        ans = toupper(ans);
        if ( q[i].answers == ans ) {
            count ++ ;
            cout << "Right !!!\n\n" ;
        } else {
            cout << "Wrong !!!\n" ;
            cout << "The correct answer is " << q[i].answers << "\n\n" ;
        }
    }

    cout << "Your score out of 10 is " << count ;
}

int main () {
    Quiz () ;

    return 0 ;
}