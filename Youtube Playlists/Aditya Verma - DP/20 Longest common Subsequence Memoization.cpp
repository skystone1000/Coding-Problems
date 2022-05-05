// Aditya Verma - DP Playlist - 20 Longest common Subsequence Memoization / Bottom Up

/*
Ques - Longest common Subsequence Memoization (LCS)
You are given two strings X,Y. You need to find the Longest common subsequence(LCS)
of these two strings and print the length of this LCS

IP
X: a b c d g h
Y: a b e d f h r

OP
4

Explanation
Longest common Subsequence = a b d h => Length is 4 (O/P)

FLOW
    1) Why do we need momoization?
        - To reuse same sub-problems in recursion which is already solved
        - Subproblems with ("AXYT" , "AYZX")
    2) Size of the matrix
        - Matrix is formed for the variables which change (n,m)
        - Size (m+1,n+1)
    3) Memoization approach and how does it work
        - Save the value of recursive call in matrix
        - So when again same call is made we return already calculated value
    4) Code Variation

*/

#include<bits/stdc++.h>
using namespace std;

// int t[m+1][n+1];
int static t[10001][10001]; // Check for constraints of m,n

int main(){
    string X,Y;
    cin>>X>>Y;
    memset(t,-1,sizeof(t));
    LCS(X,Y,X.size(),Y.size());
}

int LCS(string X, string Y, int m, int n){
    if(n==0 || m==0)
        return 0;

    // Added for memoization
    if(t[m][n] != -1)
        return t[m][n];

    if(X[m-1] == Y[n-1])
        return t[m][n] = 1+LCS(X, Y, m-1, n-1); // Stored value in matrix
    else
        return t[m][n] = max( LCS(X,Y,m,n-1) , LCS(X,Y,m-1,n)); // Stored value in matrix
}