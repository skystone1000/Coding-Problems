// 05  Find Product  
#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin>>n;
	int arr[n];
    unsigned long long int prod=1;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		prod= (prod*arr[i])%(1000000007);
	} 
	int ans = prod ;
	cout<<ans<<endl;
    return 0;
}