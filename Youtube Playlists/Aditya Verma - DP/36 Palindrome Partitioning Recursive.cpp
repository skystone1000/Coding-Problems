// Aditya Verma - DP Playlist - 36 Palindrome Partitioning Recursive

/*
Ques - 36 Palindrome Partitioning Recursive
You are given a string. we need to partition the string such that all resulting strings 
should be palindrome. Return minmum number of such partitions

IP
S: nitin
S: nitik

OP
0
2

Explanation
Output minimum number of partitions that can be mate such that every partition string is palindrome
worst case we partition every char
n | i | t | i | n => 4 Partitions
n | iti | n       => 2 Partitions 
nitin             => 0 Partitions (Minimum so output)

Flow 
    a) Problem statement
    b) Identify MCM
        left end i, right end j
        We do not know where to partition
        So k will start from i and go till k and go on partitioning
    c) Format rule
        Follow steps
    d) Further optimization


Steps
    1) Find i and j value
        i=0, j=S.size()-1
    2) Find right Base condition
        if(i>=j) (String with one/zero character)
            return 0;

        Now we also need to check for palindrome
        if(isPalindrome(S,i,j) == 0)
            return 0;
    3) Move k from i to j (Loop for k)
        Possible options 
        a) k=i, k=j-1   ==>     i to k, k+1 to j
        b) k=i+1, k=j   ==>     i to k-1, k to j
    4) Calculate finalAns from tempAns

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    string S = "nitin";
    int ans = solve(S, 0, S.size()-1);
}

int solve(string S, int i, int j){
    // Base condition
    if(i>=j) // String with one/zero character
        return 0;

    if(isPalindrome(S,i,j) == 0)
        return 0;

    int mn = INT_MAX; 
    for(int k=i;k<=j-1;k++){
        int tempAns = solve(S, i, k) + solve(S, k+1, j) + 1;
        mn = min(mn,tempAns);
    }
    return mn;

}

bool isPalindrome(string S,int i,int j){
    if(i==j)
        return true;

    if(i>j)
        return true;

    while(i<j){
        if(S[i] != S[j])
            return false;
        i++; j--;
    }
    return true;
}


// My code
bool isPalindrome(string S,int i,int j){
    string currStr = "";
    for(int k=i;k<j;k++){
        currStr += S[k];
    } 

    string str = currStr;
    reverse(currStr.begin(),currStr.end());
    if(str == currStr)
        return true;
    else
        return false;
}