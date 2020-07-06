// Codeforces Round #654 (Div. 2)
// A. Magical Sticks
// https://codeforces.com/contest/1371/problem/A

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<iterator> 
#include<algorithm>
#include<cmath>

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

        // if(n==1){
        //     cout<<1<<endl;
        //     continue;
        // }else if(n==2){
        //     cout<<
        // }

        if(n%2 == 0){
            cout<<n/2<<endl;
            continue;
        }else{
            cout<<(n/2)+1<<endl;
            continue;
        }

    }
    return 0;
}
