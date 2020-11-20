// NASDAQ Internship Hiring
// 1. Arrays and Pizzas
// Wrong Answer (Partially correct)

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<iterator> 
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<stack>

#define ll long long
#define pb push_back
#define deb(x) cout<<#x<<" = "<<x<<endl
#define deb2(x,y) cout<<#x<<" = "<<x <<", "<<#y<<" = "<<y<<endl
#define all(x) x.begin(), x.end()
#define modulo 1000000007

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end(),greater<int>());
    for(int ele:arr){
        cout<<ele<<" ";
    }
    int sets = n / 4;
    int ans = 0;
    for(int i=2;i<n;i=i+4){
        ans+=arr[i];
    }
    cout<<ans;


    return 0;
}

/*
Example
8
1 3 4 1 5 1 5 3

Output
5
*/