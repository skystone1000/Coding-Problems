//  Hamiltonian and Lagrangian 
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int count = 0;
	// Checking if all elements on the right of a particular element are greater
	for(int i=0; i<n-1;i++){
		count=n-1-i;
		for(int j=i+1; j<n; j++){
			if(arr[i]>=arr[j])
				count-=1;
			else 
                break;
		}
		if(count==0){
			cout<<arr[i]<<" ";
		}
	}
	cout<<arr[n-1];
	return 0;
}