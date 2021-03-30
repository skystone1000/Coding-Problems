//
// 

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<iterator> 
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<stack>
#include <bits/stdc++.h>

#define modulo 1000000007

#define ll long long
#define pb push_back
#define deb(x) cout<<#x<<" = "<<x<<endl
#define deb2(x,y) cout<<#x<<" = "<<x <<", "<<#y<<" = "<<y<<endl
#define all(x) x.begin(), x.end()

using namespace std;

void dfs(int &minVal, int currVal, int index, string s, int x, int y);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        int x;cin>>x;
        int y;cin>>y;

        string s;
        cin>>s;
        
        int minVal = INT_MAX;

        dfs(minVal, 0, 0, s, x, y);
        
        cout<<"Case #"<<t+1<<": "<<minVal<<endl;
    }
    return 0;
}

void dfs(int &minVal, int currVal, int index, string s, int x, int y){
    if(index == s.size()-1){
        if(currVal < minVal){
            minVal = currVal;
            return;
        }
    }

    currVal = 0;
    for(int i=0;i<s.size()-1;i++){
        if(s[i] != '?'){
            if(s[i+1] != '?'){
                if(s[i] == 'J' &&s[i+1] == 'C'){
                    currVal = currVal +  x;     
                } else if(s[i] == 'C' &&s[i+1] == 'J') {
                    currVal = currVal + y;
                }
            }else {
                continue;
            }
        } else {
            s[i] = 'J';
            dfs(minVal,currVal,i+1,s,x,y);
            s[i] = 'C';
            dfs(minVal,currVal,i+1,s,x,y);
            break;
        }
    }
}
