// Aditya Verma - DP Playlist - 37 Palindrome Partitioning Memoization

/*
Ques - 36 Palindrome Partitioning Recursive
You are given a string. we need to partition the string such that all resulting strings 
should be palindrome. Return minmum number of such partitions

IP
S: nitin
S: nitik

OP
0
2

Explanation
Output minimum number of partitions that can be mate such that every partition string is palindrome
worst case we partition every char
n | i | t | i | n => 4 Partitions
n | iti | n       => 2 Partitions 
nitin             => 0 Partitions (Minimum so output)

Flow
    1) How to build a table
        Row and columns would be of vars which change
    2) Why is it needed?
        Dp -> Recursion + Cache
        To reuse subproblems which are already solved
    3) Changes

*/

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
        int tempAns = solve(S, i, k) + solve(S, k+1, j) + 1;
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