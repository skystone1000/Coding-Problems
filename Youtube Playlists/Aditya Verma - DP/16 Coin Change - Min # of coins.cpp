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