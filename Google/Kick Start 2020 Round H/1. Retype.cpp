// Kick Start 2020 Round H
// 1. Retype
// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff49/000000000043adc7

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
        ll n,k,s;
        cin>>n>>k>>s;
        ll minTime = (k-1)+1+n;
        ll minTime2 = (k-1)+(k-s)+(n-s+1);
        ll ans;
        if(minTime < minTime2){
            ans = minTime;
        }  else {
            ans = minTime2;
        }
        cout<<"Case #"<<t+1<<": "<<ans<<endl;

    }
    return 0;
}
