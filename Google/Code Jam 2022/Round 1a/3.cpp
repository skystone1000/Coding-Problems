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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        int e, w;
        cin>>e>>w;
        vector<vector<int>> exe;
        for(int i=0;i<e;i++){
            vector<int> temp;
            for(int j=0;j<w;j++){
                int toin;
                cin>>toin;
                temp.pb(toin);
            }
            exe.pb(temp);
        }

        


    }
    return 0;
}
