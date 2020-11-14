// Codeforces Round #682 (Div. 2) 
// B. Valerii Against Everyone
// https://codeforces.com/contest/1438/problem/B

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
        cin>>n;
        // vector<ll> b(n);
        // vector<ll> a(n);
        // for(int i=0;i<n;i++){
        //     cin>>b[i];
        //     a[i] = pow(2,b[i]);
        // }

        // for(auto ele:a){
        //     cout<<ele<<" ";
        // }

        set<int> B; 
        for (int i = 0; i < n; i++) { 
            int b; 
            cin >> b; 
            B.insert(b); 
        }
		cout << (int(B.size()) < n ? "YES" : "NO") << '\n';


    }
    return 0;
}
