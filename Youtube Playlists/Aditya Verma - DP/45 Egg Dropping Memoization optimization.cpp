// Aditya Verma - DP Playlist - 45 Egg Dropping Memoization optimization

/*
Flow
    A) Problem statement
    B) Optimization


A) Ques - 45 Egg Dropping Memoization optimization
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

B) Optimization
    In Earlier memoizationwe were just checking for each t[e][f] only in recursive calls before for loop
    What we could also do is while doing both recursive calls we can check if they are already solved
    So here we would just optimize the two Recursive solve functions 


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
        // Check if both recursive calls are already made
        int low, high;
        if(t[e-1][k-1] != -1)
            low = t[e-1][k-1];
        else
            low = solve(e-1, k-1);
        
        if(t[e][f-k] != -1)
            high = t[e][f-k];
        else
            high =  solve(e,f-k);

        int temp = 1 + max( low , high );
        mn = min(mn, temp);
    }
    return t[e][f] = mn;    // Setting finally in Matrix
}