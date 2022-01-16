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