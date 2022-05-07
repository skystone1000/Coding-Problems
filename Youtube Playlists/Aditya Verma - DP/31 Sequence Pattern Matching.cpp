// Aditya Verma - DP Playlist - 31 Sequence Pattern Matching

/*
Ques - Sequence Pattern Matching (LCS)
You are given two strings "a","b". You need to check 
if string "a" is subsequence of string "b" return True/False

IP
a: AXY
B: ADXCPY

OP
True

Explanation
Order should be same and the string "a" should be present in "b"

So here we are given 2 strings, Question is about subsequences so could be possible by LCS
SO if we find LCS of above example LCS of(a,b) => AXY which is the string "a"
and this is happening only when "a" is present as subsequence in "b"

SO just need to find lenght of LCS == a.length then we return true else false

*/

#include<bits/stdc++.h>
using namespace std;

// int t[m+1][n+1];
int static t[10001][10001]; // Check for constraints of m,n

int main(){
    string a,b;
    cin>>a>>b;
    memset(t,-1,sizeof(t));
    int lcsLength = LCS(a,b,a.size(),b.size());
    if(lcsLength == a.size())
        cout<<"true";
    else 
        cout<<"false";
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