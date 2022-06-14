// Aditya Verma - DP Playlist 10 Minimum subset sum difference

/*
Ques - Minimum subset sum difference
Given an Input array "arr" with +ve integers. We need to divide this array into 2 partitions(S1, S2)
such that difference of sum of two partitions is minimum. => Abs(S1 - S2) = Minimum
Return the Minimum difference that is posible

Parition Meaning
(Partition 1 elements + Partition 2 elements) = All Array Elements 


IP=> arr[]: 1, 6, 11, 5
OP=> 1

Explanation
If we form following Paritions then subset sum difference is minimum
S1 = {a, b}   , S2 = {x, y, z} => Abs( S1 - S2 ) = minimum
S1 = {1, 6}   , S2 = {11, 5}   => Abs( 7  - 16 ) = 9, not minimum
S1 = {11, 6}  , S2 = {1, 5}    => Abs( 17 - 6  ) = 11, not minimum
S1 = {1, 6, 5}, S2 = {11}      => Abs( S1 - S2 ) = 1, minimumso we output 1

In "08 Equal sum partition" we had => S1 - S2 = 0
here in "10 Minimum subset sum difference" we need abs(S1-S2) = minimum

Range of S1, S2
Min Possible value of S1/S2 => {}         => 0
Max Possible value of S1/S2 => {1,6,11,5} => 23
Also Not all values from 0 to 23 are possible
Possible values for S1/S2 = {0, 1, 2, 3, 7, 8, 9, 10}
Here if we have a number then sum - S1 gives other set/number
i.e => Range(max possible value) is divided in {S1, Range - S1}

S2 - S1 => Minimize
(Range-S1) - S1 => Minimize
Range - 2*S1 => Minimize

so we can take in first half values of Possible range then (Range - 2*S1) would be absolute
Now for all possible values of S1 would be a "07 Subset Sum Problem" 
and in DP table for Subset sum Last row where it will give true will be possible values

*/


// Need to add the code
#include<bits/stdc++.h>
using namespace std;

int t[102][1002];

int minimumSubsetSumDifference(vector<int> arr){
    // Getting Range (here sum would be the range)
    int sum = 0;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];
    }
    
    // Getting Possible values of S1
    memset(t, -1, sizeof(t));
    subsetSum(arr, sum);
    vector<int> possible;
    for(int i=0;i<sum/2;i++){
        if(t[arr.size()-1][i] == true)
            possible.push_back(i);
    }

    // Finding Minimum subset sum diff
    int mn = INT_MAX;
    for(int i=0;i<possible.size();i++){
        mn = min(mn, sum - 2*possible[i]);
    }
    return mn;
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