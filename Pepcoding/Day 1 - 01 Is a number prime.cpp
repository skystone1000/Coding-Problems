// Pepcoding
// Ques - https://pepcoding.com/resources/online-java-foundation/getting-started/is-number-prime-official/ojquestion
// Soln - https://www.pepcoding.com/resources/online-java-foundation/getting-started/is_a_number_prime/topic

#include<bits/stdc++.h>
using namespace std;
int main(int argc, char **argv){
    int testcases;
    cin >> testcases;
    for(int t=0;t<testcases;t++){
        int n;
        cin>>n;
        int isPrime = 0;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i == 0){
                isPrime = 1;
                break;
            }
        }
        if(isPrime == 1){
            cout<<"not prime"<<endl;
        } else{
            cout<<"prime"<<endl;
        }
    }
}