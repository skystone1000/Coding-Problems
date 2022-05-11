// Aditya Verma - DP Playlist - 40 Evaluate Expression to True Memoized

/*
Ques - 40 Evaluate Expression to True Memoized | Boolean Parenthesization
You are given a string consisting of T,F along with operators like and,or,xor. 
Return number of ways in which we can apply brackets to the string such that the 
resulting equation will evaluate to TRUE.

Example 1:
IP=> S: "T^F&T"
OP=> 2

Explanation
Return number of ways in which we can apply brackets to the string such that the 
resulting equation will evaluate to TRUE. Possible ways are
1) ((T^F)&T)
2) T^(F&T)
Therefore 2 ways so output 

Example 2:
IP=> S: "T|F&T^F"
OP=> 3

Explanation
1) T|(F&T^F)
2) (T|F)&(T^F)
3) (T|F&T)^F

Also we need to put brackets on(beside) operator

Flow 
    a) Problem statement
    b) Why memoization is needed
    c) Table dimension
    d) Code variations

Steps
    1) Add a DP table
        i=0, j=S.size()-1
    2) Dimensions of table
        Dimnesions define -> Number of variables that change in recursive call
        => i, j, isTrue

    3) 
        
*/

#include<bits/stdc++.h>
using namespace std;

// int t[i+1][j+1][isTrue];
// int static t[10001][10001][2]; // Check for constraints

// Here we are using map for better visualization
unordered_map<string, int> mp;


int main(){
    string S = "T|F&T^F";
    mp.clear();
    int ans = solve(S, 0, S.size()-1, true);
}

int solve(string S, int i, int j, bool isTrue){
    // Base condition
    if(i>j) 
        return 0;

    if(i==j){
        if(isTrue == true)
            return S[i] == 'T';
        else
            return S[i] == 'F';
    }

    // Lookup from map
    string temp = to_string(i);
    temp += " ";
    temp.append(to_string(j));
    temp += " ";
    temp.append(to_string(isTrue)); // "i j isTrue"

    if(mp.find(temp) != mp.end())
        return mp[temp];

    int ans = 0; 
    for(int k=i+1; k<=j-1; k=k+1){
        int lT = solve(S,i,k-1,true);   // leftTrue
        int lF = solve(S,i,k-1,false);  // leftFalse
        int rT = solve(S,k+1,j,true);   // rightTrue
        int rF = solve(S,k+1,j,false);  // rightFalse

        if(S[k] == '&'){
            if(isTrue == true)
                ans = ans + lT*rT;
            else
                ans = ans + lF*rT + lF*rF + lF*rF;
        } 
        else if( S[k] == '|'){ 
            if(isTrue == true)
                ans = ans + lT*rT + lT*rF + lF*rT;
            else
                ans = ans + lF*rF;
        }
        else if( S[k] == '^'){
            if(isTrue == true)
                ans = ans + lF*rT + lT*rF;
            else
                ans = ans + lT*rT  + lF*rF;
        }
    }

    // Saving ans again in map
    return mp[temp] = ans;

}
