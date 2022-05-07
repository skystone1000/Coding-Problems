// Aditya Verma - DP Playlist - 28 Min # of delections to make palindrome

/*
Ques - 28 Min # of delections in a string to make it a palindrome
You are given a strings S. You need to find Minimum Number 
of delections to convert string S such that new string is palindrome
Print total number of deletions made

IP
S : agbcba
OP : 1
Solution : abcba

Explanation
Delete elements to get final string a plaindrome and find the minimum deletions that could be possible
Example 
agbcba  => -3 => bcb
agbcba  => -5 => c
agbcba  => -1 => abcba

Length of LPS is inversely proportional to Number of deletions
so minimum number of deletions means -> Longest palindromic Subsequence

Therefore => 
Min # of deletions  = S.length - LPS.length
Min # of deletions  = S.length - LCS(S, reverse(S)).length


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
    string revS = S;
    reverse(revS.begin(), revS.end());
    memset(t,-1,sizeof(t));
    int lpsLength = LCS(S, revS, S.size(), S.size());
    int minDeletions = S.size() - lpsLength;
}

// 21 LCS Top Down Code
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
