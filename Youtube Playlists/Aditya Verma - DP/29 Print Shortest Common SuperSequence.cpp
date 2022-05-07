// Aditya Verma - DP Playlist - 29 Print Shortest Common SuperSequence

/*
Ques - Print Shortest Common SuperSequence
You are given two strings X,Y. You need to merge these two strings and create Shortest Common SuperSequence
ie the generated super sequence would have both initial strings as subsequence. 
Print that shortest common supersequence

IP
X: acbcf
Y: abcaf
OP : acbcdaf
Solution : acbcdaf contains both strings X and Y as subsequences,earlier we had just printed the length 
Now we also need to print the super sequence

Explanation
After merging we should get both the strings as subsequence in the resulting supersequence

FLOW
    1) Problem statement
        From 24 Shortest Common SuperSequence the thing that is different in this is we need to print the string not just the length
    2) LCS Working
        For the chars which are common and in sequence in both we can use them only once and rest chars would remain same
        So we could find such commans chars in sequence by Q21 Longest common Subsequence
        And final supersequence length would be => A.size() + B.size() - LCS.size()

        After populating the DP table we just trverse backward to get the string
        While traversing backwards it would be slightly different than LCS as in LCS if two chars were different while comparision 
        we did not add that char to our final string where as in this we(SCS) need to add both chars which are different and
        add only once the char which is coming in both row and col.
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
            if(t[i][j-1] > t[i-1][j]){
                s.push_back(Y[j-1]);  // Added for SCS
                j--;

            } else {
                s.push_back(X[i-1]);  // Added for SCS
                i--;
            }
        }
    }

    // now check if one string is still non empty
    while(i>0){
        s.push_back(X[i-1]);
        i--;
    }
    while(j>0){
        s.push_back(Y[j-1]);
        j--;
    }


    reverse(s.begin(),s.end());
    return s;
}