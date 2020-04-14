// 05 indicium
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
        int mat[n][n];

        int diag = k/n;
        int lastDi = k-((n-1)*k/n);

        //cout<<"Diag = "<<diag<<endl;
        //cout<<"lastDi ="<<lastDi; 
        cout<<"Case #"<<t<<": ";
        for(int i=0;i<n;i++){
            int count = 1;
            for(int j=0;j<n;j++){
                if(i==j && j!=n){
                    mat[i][j] = diag;
                } else if(i==k && j==n){
                    mat[i][j] = lastDi;
                } else {
                    
                    if(count != diag && count !=lastDi){
                        mat[i][j] = count; 
                        count++;
                        if(count > n){
                            count%n;
                        }
                    } /*else{
                        while(count == diag || count == lastDi){
                            count++;
                            if(count > n){
                                cout<<"IMPOSSIBLE";
                                return 0;
                            }
                        }
                        mat[i][j] = count; 
                        count++;
                    }*/


                }
            }
        }

        cout<<"POSSIBLE"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }

    }
    return 0;
}