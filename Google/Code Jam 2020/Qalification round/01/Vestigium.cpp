// 01 Vestigium
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
        int trace=0;
        int arr[n][n];
        int rows=0,columns=0;
        
        // Taking Input
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
                if(i==j){
                    trace +=arr[i][j];
                }  
            }
        }

        // Calculating repeated rows
        for(int i=0;i<n;i++){
            // cout<<i<<"================="<<endl;
            int flag=0;
            for(int j=0;j<n;j++){
                // cout<<"Flag = "<<flag<<endl;      
                if(flag == 0){
                    for(int k=j+1;k<n;k++){
                        // cout<<"arr[i][j]:"<<arr[i][j]<<"|| arr[i][k]:"<<arr[i][k]<<"|| i="<<i<<"|| j="<<j<<"|| k="<<k<<endl;
                        if(arr[i][j] == arr[i][k]){
                            flag = 1;
                            break;
                        }
                    }
                }
            }

            if(flag==1){
                rows++;
            }
        }


        // Calculating repeated cols
        for(int i=0;i<n;i++){
            // cout<<i<<"================="<<endl;
            int flag=0;
            for(int j=0;j<n;j++){
                // cout<<"Flag = "<<flag<<endl;      
                if(flag == 0){
                    for(int k=j+1;k<n;k++){
                        // cout<<"arr[i][j]:"<<arr[i][j]<<"|| arr[i][k]:"<<arr[i][k]<<"|| i="<<i<<"|| j="<<j<<"|| k="<<k<<endl;
                        if(arr[j][i] == arr[k][i]){
                            flag = 1;
                            break;
                        }
                    }
                }
            }

            if(flag==1){
                columns++;
            }
        }

        cout<<"Case #"<<t+1<<": "<<trace<<" "<<rows<<" "<<columns<<endl;

    }
    return 0;
}