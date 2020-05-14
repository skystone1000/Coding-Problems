// 
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        long long int n,m;
        cin>>n>>m;
        if(n==1){
            cout<<"0"<<endl;
        }else if(n==2){
            cout<<m<<endl;
        }else if(n>2){
            cout<<2*m<<endl;
        }

    }
    return 0;
}