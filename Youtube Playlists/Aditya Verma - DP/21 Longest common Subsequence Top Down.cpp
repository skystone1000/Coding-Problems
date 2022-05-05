// Aditya Verma - DP Playlist - 21 Longest common Subsequence Top Down

/*
Ques - Longest common Subsequence Top Down (LCS)
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
    1) Why do we need Top Down?
        - To reuse same sub-problems in recursion which is already solved
        - and to remove the recursion completely and just use table
        - as recursion might cause stack overflow.
    2) Size of the matrix
        - Matrix is formed for the variables which change (n,m)
        - Size (m+1,n+1)
    3) Top down approach and how does it work
        - Blocks in matrix represent the subproblems 
        - with cols as m(X.size()) and rows as n(Y.size())
        - we get ans in last block of matrix t[m][n]
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
    // Initialization
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j==0)
                t[i][j] = 0;
        }
    }

    // Recursive call converts to loop and m->i, n->j
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(X[i-1] == Y[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[m][n] = max( t[i-1][j] , t[i][j-1] ); 
        }
    }

    return t[n][m];
}