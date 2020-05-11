// 04 Chef and Bitwise Product - Problem Code: CHANDF
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned long long int testCases,i;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        long long int x,y,l,r,z,ans;
        cin>>x>>y>>l>>r;
        
        /*
        // Attempt 1 (TLE)
        vector <int> prods;
        for(i=l;i<r+1;i++){
            unsigned long long int initial,tempX = x,tempY = y; 
            initial = (tempX & i) * (tempY & i);
            prods.push_back(initial);
        }

        unsigned long long int index = 0, max = prods[0];

        //cout<<"Prods--"<<endl;
        for(i=0;i<prods.size();i++){
            //cout<<prods[i]<<"   ";
            if(max < prods[i]){
                index = i;
                max = prods[i];
            }
        }  

        //cout<<endl<<"Ans:";
        cout<<index+l<<endl;
        */


        // Attempt 2
        z = x | y;

        if( min(x,y) == 0 ){
            cout<<0<<endl;
        }else if( z <= r ){
            cout<<z<<endl;
        }else{
            ans = powl(2, int(log((max(x,y)))+1 ))-1;
            cout<<ans<<endl;
        }



    }
    return 0;
}