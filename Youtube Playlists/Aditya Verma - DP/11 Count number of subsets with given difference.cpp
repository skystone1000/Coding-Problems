// Aditya Verma - DP Playlist 11 Count Number of Subsets with given difference

/*
Ques - Count Number of Subsets with given difference
    Given an Input array "arr" with +ve integers and a variable difference "Diff".  We need to divide this array into 2 partitions(S1, S2)
    such that difference of sum of two partitions is "Diff". => Abs(S1 - S2) = Diff
    Return the number subsets whose difference is "Diff"

IP
    arr[]: 1, 1, 2, 3
    Diff: 1

OP
    3

Explanation
    We have 3 subsets from given array such that their difference is 1
    and they are => 
    {1+3} {1+2}
    {1+3} {1+2} -> we have 2 ones in arr
    {1+1+2} {3}

Approach
    Array => Abs(S1 - S2) = Diff

    Sum(S1) - Sum(S2) = Diff
    Sum(S1) + Sum(S2) = Sum(Arr) 
    ----------------------------
    2 * Sum(S1)       = Diff + Sum(Arr)

    => Sum(S1) =  ( Diff + Sum(Arr) ) / 2
    => Sum(S1) =  ( 1   + (1+1+2+3) ) / 2 = 4
    => Sum(S2) =  Sum(Arr) - Sum(S1)      = 3

    SO now the problem becomes count the number of subsets whose sum is equal to 4 i.e Sum(S1) 
    which is the 09 countSubsetSum problem 

*/



#include<bits/stdc++.h>

using namespace std;

int countSubsetsWithDiff(vector<int> arr, int diff){
    int arrSum = 0;
    for(int i=0;i<arr.size();i++){
        arrSum += arr[i];
    }
    int sumS1 = (arrSum+diff)/2;

    return subsetSum(arr, sumS1);
}

int subsetSum(vector<int> &nums, int total){
    int n = nums.size();
    int w = total;
    int t[n+1][w+1];    // Diff from subsetSum (Earlier bool)
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(i==0) t[i][j] = 0; // Earlier false
            if(j==0) t[i][j] = 1; // Earlier True
        }
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(nums[i-1] <= j)
                t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j]; // Diff from subsetSum ( Earlier max(a,b) )
            else if(nums[i-1] > j)
                t[i][j] = t[i-1][j];
        }
    }
    
    return t[n][w];
}