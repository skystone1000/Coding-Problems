// Harbour Space University
// Educational Codeforces Round 87 (Rated for Div. 2)
// A. Alarm Clock

#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        long long a,b,c,d;
        cin>>a>>b>>c>>d;

        long long remaining = a-b;
        if(remaining <= 0){
            cout<<b<<endl;
            continue;
        }

        //cout<<"Remaining = "<<remaining<<endl;
        long long sleepInEach = c-d;
        if(sleepInEach <= 0){
            cout<<"-1"<<endl;
            continue;
        }else{
            // cout<<"sleepInEach = "<<sleepInEach<<endl;
            long long slots;
            if(remaining % sleepInEach == 0){
                slots = (remaining / sleepInEach);
            }else{
                slots = (remaining / sleepInEach) + 1 ;
            }
            // cout<<"Slots = "<<slots<<endl;
            long long totaltime = b + slots * c;
            cout<<totaltime<<endl;
        }

        // cout<<"========================================="<<endl;
    }
    return 0;
}
