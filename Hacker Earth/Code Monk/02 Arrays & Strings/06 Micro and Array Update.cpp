// Micro and Array Update
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
        int n,k;
        cin>>n>>k;
        // int arr[n];
        int smallest = 99999; 
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            if(temp<smallest)
                smallest = temp;
        }

        if(smallest > k ){
            cout<<"0"<<endl;
        }else{
            cout<<k-smallest<<endl;
        }
    }
    return 0;
}