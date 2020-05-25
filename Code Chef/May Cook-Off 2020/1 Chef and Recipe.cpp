// 01 Chef and Recipe -- Problem Code: CHEFRECP
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
        long long int N;
        cin>>N;
        vector <long long int> arr;
        long long int temp;
        for(int i=0;i<N;i++){
            cin>>temp;
            arr.push_back(temp);
        }

        if(N == 1){
            cout<<"YES"<<endl;
            continue;
        }

        vector <int> ingr;
        vector <int> ingrC;
        int check = arr[0];
        ingr.push_back(arr[0]);
        int flag = 0;
        int count = 1;
        for(int i=1;i<N;i++){
            //cout<<"============="<<endl;
            // cout<<"i="<<i<<endl;
            if(arr[i] == check){
                count++;
                //cout<<"count="<<count<<endl;
                continue;
            }else{
                for(int j:ingr){
                    if(arr[i] == j){
                        flag = 1;
                        break;
                    }
                }
                for(int j:ingrC){
                    if(count == j){
                        flag = 1;
                        break;
                    }
                }
                ingrC.push_back(count);
                // cout<<"count = "<<count<<" in change"<<endl;
                count = 1;
                ingr.push_back(arr[i]);
                check = arr[i];
                // cout<<"check= "<<check<<endl;

            }
        }

        for(int j:ingrC){
            if(count == j){
                flag = 1;
                break;
            }
        }

        if(flag == 1){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }

        /*
        for(int x:ingrC){
            cout<<x<<endl;
        }*/

    }
    return 0;
}