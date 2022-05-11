// Aditya Verma - DP Playlist - 44 Egg Dropping Memoization

/*
Flow
    A) Problem statement
    B) Why we need memoization
    C) Table Dimensions
    D) Code variation


A) Ques - 44 Egg Dropping Memoization
You are given total number of eggs(e) and total number of floors(f) in a building.

Critical/threashold Floor (T) : this is the last floor from which if you drop an egg then it wont break
Above K floor if you drop an egg then it would break. (You will not be given T(critical floor))

You need to return(ans) minimum number of attemts(to drop an egg and check) you require 
to find Critical(Tth) floor, you would just have "e" number of eggs to drop and check from
all the f floors

Example 1:
IP=> e: "3"  f: "5"
OP=> 3

Explanation
    In work case, with best technique we need to calculate min number of attemts to drop an egg 
    and find the critical floor


C) Table Dimensions
    Just e,f are changing in recursive calls


*/

#include<bits/stdc++.h>
using namespace std;

// Check constraints and add max
int t[1001][1001];

int main(){
    int e,f;
    cin>>e>>f;
    memset(t, -1, sizeof(t));
    int minAttempts = solve(e,f);
    cout<<minAttempts;
}

int solve(int e, int f){
    // Base condition
    if(f == 0 || f == 1)
        return f;

    if(e == 1)
        return f;

    // Memoization code
    if(t[e][f] != -1)
        return t[e][f];
    
    // Hypothesis
    int mn = INT_MAX;
    for(int k=1;k<=f;k++){
        // max as we need to find attempts in worst case
        int temp = 1 + max(solve(e-1, k-1) , solve(e,f-k));
        // min as we need min number of attempts
        mn = min(mn, temp);
    }
    return t[e][f] = mn;    // Setting finally in Matrix
}