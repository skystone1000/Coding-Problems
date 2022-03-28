// Aditya Verma - DP Playlist 05 0-1 Top Down DP

#include<bits/stdc++.h>
using namespace std;

int t[102][1002];

int main(){
    memset(t, -1, sizeof(t));
}

// Top Down DP
int knapSack(int wt[], int val[], int W, int n){
    // Base Condition
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i==0 || j==0){
                t[i][j] = 0;
            }
        }
    }
    // Choice Diagram
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if( wt[i-1] <= j )
                t[i][j] = max(
                    val[i-1]+t[i-1][j-wt[i-1]],
                    t[i-1][j]
                );
            else if(wt[i-1] > j)
                t[i][j] = t[i-1][j];
        }
    }
    
    return t[n+1][W+1];
}