// Educational Codeforces Round 98 (Rated for Div. 2) 
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
        int x,y;
        cin>>x>>y;
        int ans=0;
        if(x==y){
            ans = x+y;
        }else if(x<y){
            ans = ( 2 * x ) + ( y - x ) * 2 - 1; 
        }else{
            int temp = x;
            x = y;
            y = temp;
            ans = ( 2 * x ) + ( y - x ) * 2 - 1;
        }
        cout<<ans<<endl;

    }
    return 0;
}
