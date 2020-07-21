// July Long Challange 2020
// 1.Chef and Strings - Problem Code: CHEFSTR1

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
        vector<ll> arr;
        for(int i=0;i<n;i++){
            ll temp;
            cin>>temp;
            arr.pb(temp);
        }
        ll prev = arr[0];
        ll skips = 0;
        for(int i=1;i<n;i++){
            //deb(llabs(prev - arr[i]));
            skips = skips + llabs(prev - arr[i]) - 1;
            prev = arr[i];
        }
        cout<<skips<<endl;
    }
    return 0;
}
