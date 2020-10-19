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
        ll n;
        cin>>n;
        vector<vector<ll>> nums;
        for(ll i=0;i<n;i++){
            vector<ll> temp(n);
            for(int j=0;j<n;j++){
                cin>>temp[n-1-j]; 
            }
            nums.push_back(temp);
        }

        vector<vector<ll>> ans;
        for (ll r = 0; r < nums.size(); ++r) {
            for (ll c = 0; c < nums[r].size(); ++c) {
                if (ans.size() <= r + c) {
                    ans.emplace_back();
                }
                ans[r + c].emplace_back(nums[c][r]);
            }
        }

        /*
        for (auto rp:ans) {
            for (auto cp:rp) {
                cout<<cp<<"  ";
            }cout<<endl;
        }*/

        ll maxSum = 0;
        for(auto row:ans){
            ll tempSum = 0;
            for(auto ele:row){
                tempSum += ele;
            }
            if(tempSum > maxSum)
                maxSum = tempSum;
        }
        
        cout<<"Case #"<<t+1<<": "<<maxSum<<endl;


    }
    return 0;
}
