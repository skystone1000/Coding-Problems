// Aditya Verma - DP Playlist - 25 Min # of insertion and delection to convert a->b

/*
Ques - Min # of insertion and delection to convert a->b
You are given two strings X,Y. You need to find Minimum Number 
of insertion and delection to convert string X to string Y
Print total number of insertions and deletions made

IP
X: heap
Y: pea
OP : Insertion-1, deletion-2
Solution : heap -> eap -> ea -> pea

Explanation
Delete and insert elements to get final string

FLOW
    1) Problem statement 
    2) How to think if question is of LCS
        DP -> a) Choice b) asked for optimal (minimum))
        Array and capacity -> Knapsack
        Two strings and optimal -> LCS

        General format
        LCS
            I/P - Two Strings
            Questions - LCS
            O/P - Int

        So for converting X -> Y only that chars would remain same 
        which are present in both strings and in same sequence (whihc is LCS - Longest common subsequence)

        So we initially convert X  to LCS of(X,Y) and then to Y so
        X        -> LCS(X,Y)    Gives Deletions
        LCS(X,Y) -> Y           Gives Insertions

        Example 
        heap     ->  ea     (2 Deletions)
        ea       ->  pea    (1 Insertion)

        Therefore 
            Insertions = X.length - LCS.length
            Deletions  = Y.length - LCS.length

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
    int insertions = X.size() - lcsLength; 
    int deletions = Y.size() - lcsLength;
    // Just above two lines added for solution in this problem
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
