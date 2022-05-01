// Aditya Verma - DP Playlist - 13 Rod Cut

/*
Ques - Rod Cut
You are given an integer N, specifying the rod length.
Also given "Length" array and "Price" array where rod of length Length[i] has price Price[i]. 
Maximise money/profit that you can make by cutting the rod

IP
Length[]: 1, 2, 3, 4,  5,  6,  7
Price[] : 1, 5, 8, 9, 10, 17, 20
N: 8

OP


Explanation
Here Length[] is redundant as it would contain values from 1 to N, so we could
also be given just Price[] and N.

We have 3 subsets from given array such that their sum is 10
and they are => {2,8}, {5,2,3}, {10} so as there is at least one subset with given sum we return true
*/
