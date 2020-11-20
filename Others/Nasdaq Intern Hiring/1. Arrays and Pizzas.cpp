// NASDAQ Internship Hiring
// 1. Arrays and Pizzas

#include <iostream>
#include<vector>
#include<algorithm>
#define deb2(x,y) cout<<#x<<" = "<<x <<", "<<#y<<" = "<<y<<endl
#define modulo 1000000007
#define ll long long

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin>>n;
	vector<ll> arr(n);
	for(ll i=0;i<n;i++)
		cin>>arr[i];
	
	sort(arr.begin(), arr.end(), greater<ll>());
	ll ans = 0;
	int i=2;
	for(int j=0;j<n/4;j++){
        ans+=arr[i];
        // deb2(i,arr[i]);
		i=i+3;
    }
	ans = ans % modulo;
	cout<<ans;
}
