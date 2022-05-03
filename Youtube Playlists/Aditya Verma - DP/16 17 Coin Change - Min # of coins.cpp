// Aditya Verma - DP Playlist - 16 Coin Change - Min # of coins 

/*
Coin Change 1 - Maximum number of ways
Coin Change 2 - Minimum number of coins

Ques - Coin Change 2
You are given an integer "Sum", specifying the total sum required.
Also given "Coin" array. And we need to find total number of ways in which we can take these 
coins to get a total to be "sum". And from those we need to find 
the way which has minimum number of coins in it.
Coins are unlimited.

IP
Coin[]: 1, 2, 3
Sum: 5

OP
2

Explanation
Options in which we can select coins
    1) 2+3
    2) 1+2+2
    3) 1+1+3
    4) 1+1+1+1+1
    5) 1+1+1+2

Here number of ways in which we can get given sum is 5 and from these 5 ways
the first way {2+3} has minimum number of coins which is 2 which is the output

Here we are just given one array so we ignore the Val[] 
and take given array to be Wt[] from standard knapsack
Matching
wt[]  -->   Coin[]
W     -->   Sum

Initilization
t[n+1][w+1]  -->  t[n+1][Sum+1]  where n=size of coin


*/

#include<bits/stdc++.h>

using namespace std;

int subsetSum(vector<int> &Coin, int Sum){
    int n = Coin.size();
    int t[n+1][Sum+1];   

    // Col 0, Row 0 Initialization
    for(int i=0;i<n+1;i++){
        for(int j=0;j<Sum+1;j++){
            if(j==0) t[i][j] = 0;
            if(i==0) t[i][j] = INT_MAX - 1; 
            // Doing INT_MAX-1 as we would be adding 1 afterwards 
            // so that there is no overflow of int
        }
    }
    
    // Row 1 Initialization
    int j=0;
    for(int i=1; j < Sum+1 ;j++){
        if(j % Coin[0] == 0)
            t[i][j] = j/Coin[0];
        else
            t[i][j] = INT_MAX - 1;
    }

    for(int i=2;i<n+1;i++){
        for(int j=1;j<Sum+1;j++){
            if(Coin[i-1] <= j)
            //  t[i][j] = max( t[i-1][j-nums[i-1]] ,   t[i-1][j] );  // 07 subset sum
                t[i][j] = min( t[i][j-Coin[i-1]] + 1 , t[i-1][j] );  
                // We did not do i-1 bcz multiple occurences
                // +1 Bcz we have taken that coin and due to this we did INT_MAX -1 or would cause overflow
            else if(Coin[i-1] > j)
                t[i][j] = t[i-1][j];
        }
    }
    
    return t[n][Sum];
}