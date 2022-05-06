// Aditya Verma - DP Playlist - 26 Longest palindromic subsequence

/*
Ques - 26 Longest palindromic subsequence
You are given a strings S. You need to print length of the String which 
is longest palindromic subsequence


IP
S : agbcba
OP : 5
Solution : Following are the possible palindromic subsequences
aga, bcb, abcba, all single chars but longest is "abcba" so we output its length 5

Explanation
Get all subsequences of given string
Filter palindromic ones (Same forward and backwards)
Return the longest strins's length

FLOW
    1) Problem statement 
    2) How to think if question is of LCS
        General format
        LCS
            I/P - Two Strings
            Questions - LCS
            O/P - Int
            asked for optimal

        But in our case we just have one string (Possibly the other string is redundant)
        so can we generate some other string, which could help to solve our problem 
        (Hint user palindrome as a refrence)

        So if we use other string as Reverse of S
        then example => S = agbcba, Rev(s) = abcbga

        Now LCS of (S, Rev(S)) = abcba (which was our final longest palindromic subsequence)
        Therefor LPS(A) = LCS(a, reverse(a))       

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
    cout<<lpsLength;
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
