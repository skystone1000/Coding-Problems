// Aditya Verma - DP Playlist - 23 Print Longest common Subsequence

/*
Ques - Print Longest common Subsequence (LCS)
You are given two strings X,Y. You need to find the Longest common subsequence(LCS)
of these two strings and print this LCS

IP
X: a b c c f
Y: a b c d a f

OP
abcf

Explanation
Longest common Subsequence = abcf

FLOW
    1) Problem statement
        Input format and question are same just earlier 
        we had to print length now we need to print subsequence
    2) LCS Working
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
    cout<< findString(X,Y,X.size(),Y.size());
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

// Creating the string by traversing backwards
string findString(string X,string Y,int m,int n){
    int  i = m, j = n;
    string s = "";
    while(i>0 && j>0){
        if(X[i-1] == X[j-1]){
            s.push_back(X[i-1]);
            i--; j--;
        }else {
            if(t[i][j-1] > t[i-1][j])
                j--;
            else
                i--;
        }
    }
    reverse(s.begin(),s.end());
    return s;
}