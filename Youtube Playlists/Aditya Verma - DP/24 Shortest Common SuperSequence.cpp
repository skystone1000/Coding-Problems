// Aditya Verma - DP Playlist - 24 Shortest Common SuperSequence

/*
Ques - Shortest Common SuperSequence
You are given two strings X,Y. You need to find the length of Shortest Common SuperSequence
of these two strings

IP
X: g e e k
Y: e k e
OP : 5
Solution : g e e k e

IP
X: a g g t a b
Y: g x t x a y b
OP: 9
Solution : a g g x t x a y b
For this repeating subsequence is g t a b => 6 + 7 - 4 = 9 

Explanation
After merging we should get both the strings as subsequence in the resulting supersequence

FLOW
    1) Problem statement
        Input format and question are same just earlier 
        we had to print length now we need to print subsequence
    2) LCS Working
        For the chars which are common and in sequence in both we can use them only once and rest chars would remain same
        So we could find such commans chars in sequence by Q21 Longest common Subsequence
        And final supersequence length would be => A.size() + B.size() - LCS.size()
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
    int lcsLength = LCS(X,Y,X.size(),Y.size());
    int superSequenceLength = X.size() + Y.size() - lcsLength; 
    // Just above line added for solution in this problem
    cout<<superSequenceLength;
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
