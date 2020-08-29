// Educational Codeforces Round 94 (Rated for Div. 2)
// A. String Similarity
// https://codeforces.com/contest/1400/problem/A

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<iterator> 
#include<algorithm>
#include<cmath>
#include<unordered_map>

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
        int n;
        string s;
        cin>>n;
        cin>>s;
        string ans = "";
        for(int i=0;i<n;i++){
            ans+=s[n-1];
        }
        cout<<ans<<endl;
    }
    return 0;
}
