// Aditya Verma - DP Playlist 13 Unbounded Knapsack
/*
Knapsack Types
    1) Fractional Knapsack => Solve with greedy method
    2) 0/1 Knapsack
    3) Unbounded Knapsack
        a) Rod Cutting
        b) Coin Change 1
        c) Coin Chnage 2
        d) Maximum ribbon Cut

Differences between 0/1 knapsack and Unbounded knapsack
    - Multiple occurences of same item are allowed in unbounded which is not in 0/1 knapsack
        which is why we may come to an element again once traversed in unbounded but we do not
        consider the element again in 0/1 Knapsack
         
*/


#include<bits/stdc++.h>
using namespace std;

int t[102][1002];

int main(){
    memset(t, -1, sizeof(t));
}

// Top Down DP
int knapSack(int wt[], int val[], int W, int n){
    // Base Condition - here initialization
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
                //  val[i-1]+t[i-1][j-wt[i-1]],     // 0/1 Knapsack
                    val[i-1]+t[i][j-wt[i-1]],       // Unbounded Knapsack (As multiple occerences)
                    t[i-1][j]
                );
            else if(wt[i-1] > j)
                t[i][j] = t[i-1][j];
        }
    }
    
    return t[n+1][W+1];
}
