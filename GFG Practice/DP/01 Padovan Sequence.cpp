// GFG Practice
// 01 DP
// Padovan Sequence
// https://practice.geeksforgeeks.org/problems/padovan-sequence/0

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int testCases;
	cin>>testCases;
	for(int t=0;t<testCases;t++){
	    int n;
	    cin>>n;
	    if(n == 0 || n==1 || n==2) { 
	        cout<<1<<endl; 
	        continue;
	    }
	    vector<int> arr(n+1);
	    for(int i=0;i<n+1;i++){
	        if(i==0||i==1||i==2){ 
	            arr[i] = 1; 
	            continue;
	        }
	        arr[i] = (arr[i-2] + arr[i-3]) % 1000000007;
	       // cout<<arr[i]<<endl;
	       // arr.push_back(arr[i]);
	    }
	    cout<<arr[n]<<endl;
	}
	
	return 0;
}