// Aditya Verma - DP Playlist - 30 Longest repeating subsequence

/*
Ques - 30 Longest repeating subsequence
You are given a strings S. You need to find a longest subsequence which repeats  
in the given string
Print total number of deletions made

IP
Str : AABEBCDD
OP : 3
Solution : Subsequence - ABD

Explanation
If we take all subsequences then from that we need to filter those which repeats
(not including same characters/letters)
BD - 2x
ABD - 2x

Now from all these we need to print the size of the longest subsequence 
so it would be ABC hence output is 3 

Now in this if we look at the All possible subsequences 
then EC were the only two chars which did not come in any sub sequence as they were just once in the string

SO if we take LCS of this string with the same string but with one modification
that for every comparision  i != j so that would take into account the repeating condition


FLOW
    1) Problem statement 
    2) How to think if question is of LCS
    3) Code Variation

*/

#include<bits/stdc++.h>
using namespace std;

// int t[m+1][n+1];
int static t[10001][10001]; // Check for constraints of m,n

int main(){
    string S;
    cin>>S;
    memset(t,-1,sizeof(t));
    LCS(S,S,S.size(),S.size());
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
        //  if(X[i-1] == Y[j-1])                // LCS Code
            if(X[i-1] == Y[j-1] && i!=j )       // Added condition for index should not be same
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[m][n] = max( t[i-1][j] , t[i][j-1] ); 
        }
    }

    return t[n][m];
} 