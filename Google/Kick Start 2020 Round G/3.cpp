// Kick Start 2020 Round G
// 

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
        ll w,n;
        cin>>w>>n;
        vector<ll> values(w);
        for(ll i=0;i<w;i++){
            cin>>values[i];
        }

        ll minMoves = std::numeric_limits<long long int>::max();
        // vector<int> ans;
        for(ll i=1;i<=n;i++){
            ll curMoves = 0;
            for(int j=1;j<=w;j++){
                ll reqMove = min( llabs(values[j-1] - i) , n - llabs(values[j-1] - i) );
                curMoves += reqMove; 
            }
            // ans.push_back(curMoves);
            if(curMoves<minMoves){
                minMoves = curMoves;
            }
        }

        /*
        cout<<endl;
        for(auto ele:ans){
            cout<<ele<<" ";
        }*/
        
        cout<<"Case #"<<t+1<<": "<<minMoves<<endl;

    }
    return 0;
}
