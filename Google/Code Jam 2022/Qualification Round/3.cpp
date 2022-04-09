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
#define modulo 1000000007

#define ll long long
#define pb push_back
#define deb(x) cout<<#x<<" = "<<x<<endl
#define deb2(x,y) cout<<#x<<" = "<<x <<", "<<#y<<" = "<<y<<endl
#define all(x) x.begin(), x.end()

using namespace std;

int fun(int maxlen, int currlen, int ptr, int n, vector<int> &sides){
    if(ptr > n-1)
        return maxlen;

    if(sides[ptr] > currlen){
        currlen++;
        ptr++;
        if(maxlen < currlen)
            maxlen = currlen;
        maxlen = max(maxlen, fun(maxlen, currlen, ptr, n, sides));
    }else{
    // cout<< "befor next "<<endl;
    // deb(maxlen);
    
    maxlen = max(maxlen, fun(maxlen, currlen, ptr+1, n, sides));
    // deb(maxlen);
    }
    return maxlen;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        int n; cin>>n;
        vector<int> sides;
        for(int i=0;i<n;i++){
            int temp; cin>>temp;
            sides.pb(temp);
        }
        sort(sides.begin(), sides.end());
        int maxLen = fun(0, 0, 0, n, sides);
        cout<<"Case #"<<t+1<<": ";
        cout<<maxLen<<endl;
    }
    return 0;
}
