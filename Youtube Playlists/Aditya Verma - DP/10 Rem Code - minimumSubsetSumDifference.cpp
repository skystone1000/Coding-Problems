// Aditya Verma - DP Playlist 10 Minimum subset sum difference

/*
Ques - Minimum subset sum difference
Given an Input array "arr" with +ve integers. We need to divide this array into 2 partitions(S1, S2)
such that difference of sum of two partitions is minimum. => Abs(S1 - S2) = Minimum
Return the Minimum difference that is posible


Parition Meaning
(Partition 1 elements + Partition 2 elements) = All Array Elements 


IP
arr[]: 1, 6, 11, 5

OP
1

Explanation
If we form following Paritions then subset sum difference is minimum
S1 = {1, 6, 5}, S2 = {11}
Abs( S1 - S2 ) = 1, so we output 1
*/


// Need to add the code
#include<bits/stdc++.h>

using namespace std;

int minimumSubsetSumDifference(vector<int> arr){
    int sum = 0;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];
    }
    

}




// Earlier Problem Q7 
bool subsetSum(vector<int> &nums, int total){
    int n = nums.size();
    int w = total;
    bool t[n+1][w+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(i==0) t[i][j] = false;
            if(j==0) t[i][j] = true;
        }
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(nums[i-1] <= j)
                t[i][j] = max(t[i-1][j-nums[i-1]] , t[i-1][j]);
            else if(nums[i-1] > j)
                t[i][j] = t[i-1][j];
        }
    }
    
    return t[n][w];
}