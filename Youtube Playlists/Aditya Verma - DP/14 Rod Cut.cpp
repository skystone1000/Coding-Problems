// Aditya Verma - DP Playlist - 14 Rod Cut

/*
Ques - Rod Cut
You are given an integer N, specifying the rod length.
Also given "Length" array and "Price" array where rod of length Length[i] has price Price[i]. 
Maximise money/profit that you can make by cutting the rod

IP
Length[]: 1, 2, 3, 4,  5,  6,  7
Price[] : 1, 5, 8, 9, 10, 17, 20
N: 8

OP
22

Explanation
Here Length[] is redundant as it would contain values from 1 to N, so we could
also be given just Price[] and N.

Options
8 = 3 + 3 + 2
8 = 5 + 3
8 = 6 + 2 -> profit = 5 + 17 = 22

COMPARING 
Unbounded Knapsack      with            0/1 Knapsack
    N            <----------------->         W
Price[]          <----------------->        Val[]
Lenght[]         <----------------->        Wt[]

Exact Unbounded knapsack just asked in different way (So all code same with change of names of array)
*/

#include<bits/stdc++.h>
using namespace std;

int t[102][1002];
// int t[N+1][N+1];

int main(){
    memset(t, -1, sizeof(t));
}

// Top Down DP
int knapSack(int Length[], int Price[], int N){
    // Base Condition - here initialization
    for(int i=0;i<N+1;i++){
        for(int j=0;j<N+1;j++){
            if(i==0 || j==0){
                t[i][j] = 0;
            }
        }
    }
    // Choice Diagram
    for(int i=1;i<N+1;i++){
        for(int j=1;j<N+1;j++){
            if( Length[i-1] <= j )
                t[i][j] = max(
                //  val[i-1]+t[i-1][j-wt[i-1]],     // 0/1 Knapsack
                    Price[i-1]+t[i][j-Length[i-1]],       // Unbounded Knapsack (As multiple occerences)
                    t[i-1][j]
                );
            else
                t[i][j] = t[i-1][j];
        }
    }
    
    return t[N+1][N+1];
}


// Variation -> sometimes we can cut the rod in only certain number of sizes 
// in that case we need to considersize of the Price[] or Length[] and Update in for loops