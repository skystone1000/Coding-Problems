// 
#include<iostream>
#include <bits/stdc++.h> 

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int profit=0;

        /*
        for(int i=n-1;i>=0;i--){
            cout<<arr[i]<<" ";
        }*/
        
        for(int i=n-1;i>=0;i--){
            if(arr[i]>0){
                arr[i] = arr[i] - (n-i-1);
            }
            profit += arr[i];
        }
        cout<<profit<<endl;
    }
    return 0;
}
