// 01 Monk Takes a Walk 

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
        string a;
        cin>>a;
        int count=0;
        for(int i=0;i<a.length();i++){
            if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' 
                            || a[i] == 'o' || a[i] == 'u' || 
            a[i] == 'A' || a[i] == 'E' || a[i] == 'I' 
                            || a[i] == 'O' || a[i] == 'U'){
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}