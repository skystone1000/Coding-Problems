// Aditya Verma - DP Playlist - 15 Coin Change - Max # of ways 

/*
Coin Change 1 - Maximum number of ways
Coin Change 2 - Minimum number of coins

Ques - Coin Change 1
You are given an integer "Sum", specifying the total sum required.
Also given "Coin" array. And we need to find total number of ways in which we can take these 
coins and we would get a total to be "sum". 
Coins are unlimited.

IP
Coin[]: 1, 2, 3
Sum: 5

OP
5

Explanation
Options in which we can select coins
    1) 2+3
    2) 1+2+2
    3) 1+1+3
    4) 1+1+1+1+1
    5) 1+1+1+2

There fore the total number of ways in which we can get given sum is 5

Here we are just given one array so we ignore the Val[] 
and take given array to be Wt[] from standard knapsack
Matching
wt[]  -->   Coin[]
W     -->   Sum

Similar to Count Subset Sum
*/

#include<bits/stdc++.h>

using namespace std;

int subsetSum(vector<int> &Coin, int Sum){
    int n = Coin.size();
    int t[n+1][Sum+1];   
    for(int i=0;i<n+1;i++){
        for(int j=0;j<Sum+1;j++){
            if(i==0) t[i][j] = 0; 
            if(j==0) t[i][j] = 1; 
        }
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<Sum+1;j++){
            if(Coin[i-1] <= j)
            //  t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];  // 09 count subset sum
                t[i][j] = t[i][j-Coin[i-1]]   + t[i-1][j];  // We did not do i-1 bcz multiple occurences
            else if(Coin[i-1] > j)
                t[i][j] = t[i-1][j];
        }
    }
    
    return t[n][Sum];
}