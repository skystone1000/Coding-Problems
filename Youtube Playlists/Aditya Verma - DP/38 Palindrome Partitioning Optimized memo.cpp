// Aditya Verma - DP Playlist - 38 Palindrome Partitioning Optimized memo

// In this we are just chekcing again before the both recursive calls for left and right
// if it is already solved

#include<bits/stdc++.h>
using namespace std;

// int t[m+1][n+1];
int static t[10001][10001]; // Check for constraints of m,n

int main(){
    memset(t, -1, sizeof(t));
    string S = "nitin";
    int ans = solve(S, 0, S.size()-1);
}

int solve(string S, int i, int j){
    // Base condition
    if(i>=j)
        return 0;

    if(isPalindrome(S,i,j) == 0)
        return 0;

    // Added for memoization
    if(t[i][j] != -1)
        return t[i][j]; // Return if already present

    int mn = INT_MAX; 
    for(int k=i;k<=j-1;k++){
        int left,right;
        // Checking Left call
        if(t[i][k] != -1)
            left = t[i][k];
        else{
            left = solve(S,i,k);
            t[i][k] = left;
        }

        // Checking right call
        if(t[k+1][j] != -1)
            right = t[k+1][j];
        else{
            right = solve(S,i,k);
            t[k+1][j] = right;
        }

        int tempAns = left + right + 1;
        mn = min(mn,tempAns);
    }
    return t[i][j] = mn; // Add before returning

}

bool isPalindrome(string S,int i,int j){
    if(i==j)
        return true;

    if(i>j)
        return true;

    while(i<j){
        if(S[i] != S[j])
            return false;
        i++; j--;
    }
    return true;
}