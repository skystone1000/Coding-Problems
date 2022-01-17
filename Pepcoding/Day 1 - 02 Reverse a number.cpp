// Pepcoding
// Ques - https://www.pepcoding.com/resources/online-java-foundation/getting-started/reverse-a-number-official/ojquestion
// Soln - https://www.pepcoding.com/resources/online-java-foundation/getting-started/reverse_a_number/topic

#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;

    while(n>0){
        if(n<10){
            cout<<n%10;
            n = n/10;    
        }else {
            cout<<n%10<<endl;
            n = n/10;    
        }   
    }
}