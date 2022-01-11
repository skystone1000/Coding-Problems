#include <bits/stdc++.h>
using namespace std;
set<int> pr;
set<int> check;

void SieveOfEratosthenes(int n=1000){
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++){
        if (prime[p] == true){
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    for (int p = 2; p <= n; p++)
        if (prime[p]){
            pr.insert(p);
            // cout << p << " ";
        }
}

void primeFactors(int n)
{
    while (n%2 == 0){
        check.insert(2);
        n = n/2;
    }
 
    for (int i = 3; i <= sqrt(n); i = i+2){
        while (n%i == 0){
            check.insert(i);
            n = n/i;
        }
    }
 
    if (n > 2){
        // printf ("%d ", n);
        check.insert(n);
    }
}


int main(){
    int n;
    cin>>n;
    SieveOfEratosthenes();

    if(pr.find(n) != pr.end()){
        cout<<"Strange"<<endl;
        return 0;
    }
    
    primeFactors(n);

    int max_element;
    if (!check.empty())
        max_element = *(check.rbegin());
    if(sqrt(n) < max_element){
        cout<<"Strange"<<endl;
    }else{
        cout<<"Not Strange"<<endl;
    }

}

