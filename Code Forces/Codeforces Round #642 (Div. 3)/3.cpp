// 
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int testCases,i;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        long long int n,sum = 0;
        cin>>n;
        for(i=1;i<=(n-1)/2;i++){
            sum +=(i) *(8*(i));
            //sum += (i)*(2*i+1);
        }
        cout<<sum<<endl;
    }
    return 0;
}