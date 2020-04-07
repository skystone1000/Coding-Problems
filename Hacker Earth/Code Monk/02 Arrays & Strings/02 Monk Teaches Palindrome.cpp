// 02 Monk Teaches Palindrome
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        string a;
        cin>>a;
        int len = a.length();
        string aR;
        for(int i=len-1;i>=0;i--){
            aR +=a[i];
        }
        if(aR == a){
            cout<<"YES ";
            if(len %2 == 0){
                cout<<"EVEN"<<endl;
            }else{
                cout<<"ODD"<<endl;
            }
        }else{
            cout<<"NO "<<endl;
        }


    }
    return 0;
}