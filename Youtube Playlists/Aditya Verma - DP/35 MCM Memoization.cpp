// Aditya Verma - DP Playlist - 35 MCM Memoization

/*
Ques - MCM Memoization - Bottom up
You are given array[]. 
We technically have multiple Matrices A1,A2,A3 an we need to find the paranthesize these matrices 
such that the cost of multiplying these matrices is minimum. the dimension of each matrix is given in array. 
SO we need to find Minimum cost for matrix chan multiplication for all these matrics and print it(cost).

Cost of matrix Multiplication
A(30x5) x B(5x60) => AB(30x60)
Cost = 30*5*60

IP
arr: 40, 20, 30, 10, 30
We are given n-1 Matrices where where n is size of array, Matrices dimensions are as follows
Ai = arr[i-1] x arr[i]
A1 = (40x20)
A2 = (20x30)
A3 = (30x10)
A4 = (10x30)

OP
4500

Explanation
Output minimum cost multiplying these matrices

Now t solve this we need to take k at every point and put brackets these and 
find min cost(temp ans) for that part and then procced further with other k

Flow
    1) MCM Recursive
    2) How to build a table
        Row and columns would be of vars which change
    3) Why is it needed?
        Dp -> Recursion + Cache
        To reuse subproblems which are already solved
    4) Changes

*/

#include<bits/stdc++.h>
using namespace std;

// int t[m+1][n+1];
int static t[10001][10001]; // Check for constraints of m,n

int main(){
    int arr[] = {40, 20, 30, 10, 30};
    int n=5;
    int i=1, j=n-1;
    memset(t, -1, sizeof(t));
    int ans = solve(arr, i, j);
}

int solve(int arr[], int i, int j){
    // Base condition
    if(i > j)   // i==j is not allowed as we need at lest two matrices, so 1 element array is invalid
        return 0;

    // Added for memoization
    if(t[i][j] == -1)
        return t[i][j];

    int mn = INT_MAX; 
    for(int k=i;k<=j-1;k++){
        int tempAns = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
        
        if(tempAns < mn){
            mn = tempAns;
        }
    }
    return t[i][j] = mn;

}