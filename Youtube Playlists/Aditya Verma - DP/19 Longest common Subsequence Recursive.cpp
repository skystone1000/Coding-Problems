// Aditya Verma - DP Playlist - 19 Longest common Subsequence Recursive

/*
FLOW
    Problem statement
    Recursive approach
        - base condition
        - choice diagram
    Code

Ques - Longest common Subsequence Recursive (LCS)
You are given two strings X,Y. You need to find the Longest common subsequence(LCS)
of these two strings and print the length of this LCS

IP
X: a b c d g h
Y: a b e d f h r

OP
4

Explanation
Longest common Subsequence = a b d h => Length is 4 (O/P)
Longest common substring = a b

Theory
    1. Reduce the input/ Make input smaller with each call
    2. Base Condition (Think of smallest valid input)
        if(n==0 || m==0) // If Any of string is zero
            return 0;
    3. Choice Diagram

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    string X,Y;
    cin>>X>>Y;
    LCS(X,Y,X.size(),Y.size());
}

// Initial n,m are size of X,Y respectively
int LCS(string X, string Y, int m, int n){
    // Base Condition
    if(n==0 || m==0)
        return 0;

    // Choice Diagram
    if(X[m-1] == Y[n-1])
        return 1+LCS(X, Y, m-1, n-1);
    else
        return max( LCS(X,Y,m,n-1) , LCS(X,Y,m-1,n));
}