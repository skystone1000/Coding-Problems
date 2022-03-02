// Pepcoding - Prime Factorization Of A Number
// Ques - https://www.pepcoding.com/resources/online-java-foundation/getting-started/prime-factorization-official/ojquestion

// Method 1 - TLE
// No Need of finding prime number initially
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int main(int argc, char **argv){
    int n;
    cin >> n;

    for(int t=2;t<=n;t++){
        // Find Prime
        int isPrime = 0;
        for(int i=2;i<sqrt(t);i++){
            if(t%i == 0){
                isPrime = 1;
                break;
            }
        }

        // Go on Dividing by prime
        if(isPrime == 0){
            while(n % t == 0){
                cout<<t<<" ";
                n = n / t;
            }
        }
    }

}


// Method 2
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int main(int argc, char **argv){
    int n;
    cin >> n;

    // Go on Dividing till the number 
    for(int t=2;t<=n;t++){
        while(n % t == 0){
            cout<<t<<" ";
            n = n / t;
        }
    }
}

// Method 3
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int main(int argc, char **argv){
    int n;
    cin >> n;

    for(int t=2;t*t<=n;t++){
        while(n % t == 0){
            cout<<t<<" ";
            n = n / t;
        }
    }
    
    if(n != 1){
        cout<<n;
    }
}
