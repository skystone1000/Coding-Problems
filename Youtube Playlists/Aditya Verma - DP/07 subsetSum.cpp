// Aditya Verma - DP Playlist 07 Subset Sum

#include<bits/stdc++.h>

using namespace std;

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