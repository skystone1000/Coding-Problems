// Codeforces Round #688 (Div. 2) 
// A. Cancel the Trains
// https://codeforces.com/contest/1453/problem/A

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<iterator> 
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<stack>
#define modulo 1000000007

#define ll long long
#define pb push_back
#define deb(x) cout<<#x<<" = "<<x<<endl
#define deb2(x,y) cout<<#x<<" = "<<x <<", "<<#y<<" = "<<y<<endl
#define all(x) x.begin(), x.end()

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        int n,m;
        cin>>n>>m;
        set<int> bottom;
        vector<int>left(m);
        for(int i=0;i<n;i++){
            int inp;
            cin>>inp;
            bottom.insert(inp);
        }
        for(int i=0;i<m;i++){
            cin>>left[i];
        }

        int count = 0;
        for(int ele:left){
            if(bottom.count(ele) > 0){
                count++;
            }
        }

        cout<<count<<endl;


    }
    return 0;
}