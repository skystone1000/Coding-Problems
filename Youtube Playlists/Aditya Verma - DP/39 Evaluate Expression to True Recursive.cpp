// Aditya Verma - DP Playlist - 39 Evaluate Expression to True Recursive

/*
Ques - 39 Evaluate Expression to True Recursive | Boolean Parenthesization
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
    b) Identify MCM
    c) Format rule
    d) Further optimization

Here when we add brackets beside operator and we need to evaluate complete
expression to true, then are the current variable that we pass in solve() 
are they sufficient ?
No bcz we need left and rigth values to be sometimes true sometimes false in case of XOR
as T^F=T and F^T=T 
so Left could be T/F and same goes with right. Therefore we need one more boolean(isTrue) in solve

Steps
    1) Find i and j value
        i=0, j=S.size()-1
    2) Find right Base condition
        if(i>j) 
            return false;

        if(i==j){
            if(isTrue == True)
                return s[i] == 'True';
            else
                return s[i] == 'False';
        }

    3) Move k from i to j (Loop for k)
        Possible options 
        k=i+1, k=j-1, k=k+1   ==>     i to k-1, k+1 to j

        for(int k=i+1; k<=j-1; k=k+1){
            // We pass boolean to solve whichever we require
            int leftTrue = solve(s,i,k-1,T);
            int leftFalse = solve(s,i,k-1,F);
            int rightTrue = solve(s,k+1,j,T);
            int rightFalse = solve(s,k+1,j,F);
        }
    4) Calculate finalAns from tempAns  
        int ans = 0;
        
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    string S = "T|F&T^F";
    int ans = solve(S, 0, S.size()-1, true);
}

int solve(string S, int i, int j, bool isTrue){
    // Base condition
    if(i>j) 
        return 0; // return false;

    if(i==j){
        if(isTrue == true)
            return S[i] == 'T';
        else
            return S[i] == 'F';
    }

    int ans = 0; 
    for(int k=i+1; k<=j-1; k=k+1){
        // We pass boolean to solve whichever we require
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

    return ans;

}
