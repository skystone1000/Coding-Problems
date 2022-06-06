// Aditya Verma - DP Playlist 04 0-1 Knapsack Memoization

/*
Question
    Given
    Weights [] : 1    3    4    5
    Values  [] : 1    4    5    7
    Capacity (W) : 7 kg (Capacity of knapsack)
    Find max profit that we can get by adding elements in the bag?
*/

#include<bits/stdc++.h>
using namespace std;
int t[102][1002];
int main(){
    memset(t, -1, sizeof(t));
}

// Memoized
int knapSack(int wt[], int val[], int W, int n){
    // Base Condition
    if(n == 0 || W == 0){
        return 0;
    }

    // Getting from stored matrix
    if(t[n][W] != -1){
        return t[n][W];
    }

    // Choice Diagram
    if( wt[n-1] <= W )
        return t[n][W] = max( val[n-1] + knapSack(wt, val, W-wt[n-1], n-1), knapSack(wt, val, W, n-1));
    else if( wt[n-1] > W)
        return t[n][W] = knapSack(wt, val, W, n-1);
}