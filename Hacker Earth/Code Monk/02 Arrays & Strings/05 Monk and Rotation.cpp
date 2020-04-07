    // 05 Monk and Rotation
    #include<iostream>
    #include <bits/stdc++.h>
     
    using namespace std;
     
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
     
        int testCases;
        cin>>testCases;
        for(int t=0;t<testCases;t++){
            int n,k;
            cin>>n>>k;
            int arr[n];
            for(int i=0;i<n;i++){
                cin>>arr[i];
            }
     
            /*
            // Taking array values to be shifted in temp
            int temp[k];
            int j=0;
            for(int i=n-k;i<n;i++){
                temp[j] = arr[i];
                j++;
            }
     
            // Shifting starting values 
            for(int i=n-k-1;i>=0;i--){
                arr[i+k] = arr[i];
            }
     
            // Adding temp values at start
            for(int i=0;i<k;i++){
                arr[i] = temp[i];
            }
     
            // Printing final array
            for(int i=0;i<n;i++){
                cout<<arr[i]<<" ";
            }
            **/
     
            for(int i=k+1;i<n;i++){
                cout<<arr[i]<<" ";
            }
            for(int i=0;i<k+1;i++){
                cout<<arr[i]<<" ";
            }
     
     
     
     
            cout<<endl;
        }
        return 0;
    }