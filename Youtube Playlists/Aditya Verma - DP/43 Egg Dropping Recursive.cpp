// Aditya Verma - DP Playlist - 43 Egg Dropping Recursive

/*
Flow
    A) Problem statement
    B) MCM Pattern
    C) How to breakdown the problem
    D) Recursive Code


A) Ques - 43 Egg Dropping Recursive
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

B) MCM Pattern
    Our MCM pattern had a string or an array
    Here our array would be floors in the building as we need tocheck from all floors


Steps
    1) Find i and j value
        i=1, j=S.size() // as one based floors 
    2) Find right Base condition
        Smallest valid input would be 
        e = 0/1 => e being 0 is invalid so at least 1 egg
        f = 0/1 => 

        if( e <= 1 || f <= 1 ){
            return f;
        }

    3) Move k from i to j (Loop for k)
        The loop for K is to check form which floor so it would be within first and last floor
        for(int k=1;k<=f;k++){

        }

        Now for recursive call lets take a generalised case of kth position/floor
        so the recursive calls at kth floor would be
        kth Floor
            a) If egg breaks => solve(e-1, k-1);
            as egg has broken we just have e-1 eggs now and also the critical floor would be 
            below the kth floor so we just need to validate below i floors

            b) If egg does not break => solve(e, f-k);
            As the egg did not break we still have e eggs which first parameter would still be same
            And for the floors all the above of i follors need to be checked so f-i

        
    4) Calculate finalAns from tempAns   
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int e,f;
    cin>>e>>f;
    int minAttempts = solve(e,f);
    cout<<minAttempts;
}

int solve(int e, int f){
    // Base condition
    if(f == 0 || f == 1)
        return f;

    if(e == 1)
        return f;

    // Hypothesis
    int mn = INT_MAX;
    for(int k=1;k<=f;k++){
        // max as we need to find attempts in worst case
        int temp = 1 + max(solve(e-1, k-1) , solve(e,f-k));
        // min as we need min number of attempts
        mn = min(mn, temp);
    }
    return mn;
}