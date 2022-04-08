// Aditya Verma - DP Playlist 09 Count of Subsets Sum with a given sum

/*
Ques - Count of Subsets with given sum
Given an Input array "arr" with +ve integers and a variable "sum". Find total number of subsets in given array 
such that their sum equals to "sum" 

IP
arr[]: 2, 3, 5, 6, 8, 10
Sum: 10

OP
3

Explanation
We have 3 subsets from given array such that their sum is 10
and they are => {2,8}, {5,2,3}, {10}
*/



#include<bits/stdc++.h>

using namespace std;

int subsetSum(vector<int> &nums, int total){
    int n = nums.size();
    int w = total;
    int t[n+1][w+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(i==0) t[i][j] = 0;
            if(j==0) t[i][j] = 1;
        }
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(nums[i-1] <= j)
                t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];
            else if(nums[i-1] > j)
                t[i][j] = t[i-1][j];
        }
    }
    
    return t[n][w];
}