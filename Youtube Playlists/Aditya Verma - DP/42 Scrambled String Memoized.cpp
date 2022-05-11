// Aditya Verma - DP Playlist - 42 Scrambled String Memoized

/*
Flow
    A) Problem statement
    B) Why Memoization needed
    C) Table/Map
    D) Code variation

A) Ques - 42 Scrambled String Memoized
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
        
*/

#include<bits/stdc++.h>
using namespace std;

unordered_map<string,bool> mp;

int main(){
    string a,b;
    cin>>a>>b;
    if(a.size() != b.size())
        cout<<false;
    mp.clear();
    solve(a,b);
}

bool solve(string a, string b){
    // Base condition
    if(a.compare(b) == 0)  // if(a == b) 
        return true;

    if(a.size() <= 1)
        return false;

    // Memoization code
    string key = a;
    key += " ";
    key.append(b);
    if(mp.find(key) != mp.end())
        return mp[key];

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

    return mp[key] = flag;
}