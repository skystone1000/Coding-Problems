// Aditya Verma - DP Playlist - 22 Longest common Substring

/*
Ques - Longest common Substring
You are given two strings X,Y. You need to find the Longest common Substring
of these two strings and print the length of it

IP
X: a b c d e
Y: a b f d e

OP
2

Explanation
Longest common Substrings = a b , c , e => ab Length is 2 (O/P)

FLOW
    1) problem statement
    2) Difference between Subsequence and substring
        - Just substring require continous which is not is subsequence
        - The Input and Output format is same.
    3) Code Variation

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
            //  t[m][n] = max( t[i-1][j] , t[i][j] );
                t[m][n] = 0; // Change in substring code

        }
    }

    return t[n][m];
}