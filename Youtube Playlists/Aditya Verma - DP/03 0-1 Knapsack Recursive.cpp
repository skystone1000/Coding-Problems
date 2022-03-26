// Aditya Verma - DP Playlist 03 0-1 Knapsack Recursive

#include<bits/stdc++.h>
using namespace std;

int t[102][1002];

int main(){
    memset(t, -1, sizeof(t));
    // knapSack();
}

int knapSack(int wt[], int val[], int W, int n){
    // Base Condition
    if(n == 0 || W == 0){
        return 0;
    }

    // Choice Diagram
    if(wt[n-1] <= W )
        return max( val[n-1] + knapSack(wt, val, W - wt[n-1], n-1), knapSack(wt, val, W, n-1));
    else if(wt[n-1] > W)
        return knapSack(wt, val, W, n-1);
}