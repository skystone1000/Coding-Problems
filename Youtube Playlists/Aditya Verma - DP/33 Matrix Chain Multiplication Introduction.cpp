/*

Aditya Verma - DP Playlist - 33 Matrix Chain Multiplication Introduction

Flow for general format
    - Recusive
    - Memoization
    - Top down approach

Variations
    1) Matrix Chain Multiplication
    2) Printing Matrix Chain Multiplication
    3) Evaluate Expression to true / Boolean Paranthesis
    4) Minimum/Maximum Value of an Expression
    5) Palindrome Partitioning
    6) Scramble Strings
    7) Egg Dropping Problem

Identification and Format of MCM
    Given -> String or Array

    Process ->
    0) for arr or str we have left index(i) and right index(j)
    1) For this string or array we divide this at every k 
    from i to j where i is at start and j is at end of arr/str
    and solve it recursively
    2) We get a "temp ans" for every K at every step 
    3) we apply a funtion(max min abs etc) on these temp ans 
    and find the final ans

    For Base condition
        - Think of smallest valid input
        - Think of invalid input 

    In MCM 2nd options works better to find base condition
*/

#include<bits/stdc++.h>
using namespace std;

// Template
int ans;
int solve(int arr[], int i, int j){
    // Base Condition
    if( i > j )     // Could be different according to question
        return 0;

    for(int k=i;k<j;k++){ // Small varaiations on bounds and increment according to ques
        // Find tempAns from recursive calls
        int tempAns = solve(arr,i,k) + solve(arr,k+1,j);
        ans = max(ans, tempAns); // COuld be any function according to question
    }

    return ans;
}