// Aditya Verma - DP Playlist - 41 Scrambled String Recursive

/*
Flow
    A) Problem statement
    B) How to identify
    C) How to approach
    D) How to breakdown the problem
    E) Base condition
    F) Code variation


A) Ques - 41 Scrambled String Recursive
YOu are given 2 Strings and you need to output a boolean saying whether 
a,b are scrambled strings of each other or not 

Scrambled String
    1) Binary tree - You can make a binary tree out of the string(with 2 child)
    (your wish whatever and however you want to break the string)
    2) At any time Left and right Child should not be empty,i.e 
    if Left child is present then right child should also be present (and should be non empty) and vice versa
        great
            - gr (Left of great)
                - g (Left of gr)
                - r (Right of gr)

            - eat (Right of great)
                - e (Left of eat)
                - at (Right of eat)
                    - a (Left of at)
                    - t (Right of at)

    3) For Non-leaf nodes in Binary tree you can do (your wish whatever and however you want)
    0 or more number of swaps (with its left and right child)

    4) After swapping you can create a string again then the resulting string 
    and the orignal string are scambled strings of each other

Example 1:
IP=> a: "great"  b: "rgeat"
OP=> True

B,C) Explanation
    Refer video for explanation


D) Breaking the problem IN TWO CONDITIONS
    Function params
    substr(start,length)

    a) Case 1 (When swapping occurs)
        if( solve(a.substr(0,i), b.substr(n-i,i)) == true) && (solve(a.substr(i,n-i), b.substr(0,n-i)) == true )

    b) Case 2 (Swapping does not occur)
        if(solve(a.substr(0,i), b.substr(0,i)) == true &&
        solve(a.substr(i,n-i), b.substr(i,n-i)) == true) ) 


    If (Case I==true || Case II==true)
        return "Scrambled String"


E) Find right Base condition
    if(a.compare(b) == 0)  // if(a == b) 
        return true;

    if(a.size() != b.size() || a.size() <= 1)
        return false;
    
        
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    if(a.size() != b.size())
        cout<<false;
    solve(a,b);
}

bool solve(string a, string b){
    // Base condition
    if(a.compare(b) == 0)  // if(a == b) 
        return true;

    if(a.size() <= 1)
        return false;

    int n = a.size();
    bool flag = false;

    for(int i=1;i<=n-1;i++){
        if( // Condition 1
            (solve(a.substr(0,i), b.substr(n-i,i)) == true) && (solve(a.substr(i,n-i), b.substr(0,n-i)) == true) 
            ||
            // Condition 2
            (solve(a.substr(0,i), b.substr(0,i)) == true) && (solve(a.substr(i,n-i), b.substr(i,n-i)) == true)    
        ){
            flag == true; // Means it is a scrambled string
            break;
        }
    }

    return flag;
}