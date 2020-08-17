// Codeforces Round #662 (Div. 2)
// B. Applejack and Storages
// https://codeforces.com/contest/1393/problem/B

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

    ll n;
    cin>>n;
    vector<int> planks(n);
    map<int,int> freq;

    int sq=0,rc=0;
    for(int i=0;i<n;i++){
        cin>>planks[i];
        freq[planks[i]]++;
    }

    ll q;
    cin>>q;
    for(int e=0;e<q;e++){
        char op;
        ll length;
        cin>>op>>length;
        freq[length]++;

        for(auto &x:freq){
            cout<<x.first<<"  "<<x.second<<endl;
        }
        cout<<"============="<<endl;

    }

    return 0;
}
