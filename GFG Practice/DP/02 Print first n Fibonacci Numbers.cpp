// GFG Practice
// 02 DP
// Print first n Fibonacci Numbers
// https://practice.geeksforgeeks.org/problems/print-first-n-fibonacci-numbers/0

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int testCases;
	cin>>testCases;
	for(int t=0;t<testCases;t++){
	    int n;
	    cin>>n;
	    if(n==1){cout<<"1"<<endl; continue;}
	    if(n==2){cout<<"1 1"<<endl; continue;}
	    vector<long long> fibo(n);
	    for(int i=0;i<n;i++){
	        if(i==0 || i==1){
	            fibo[i] = 1;
	            continue;
	        }
	        fibo[i] = fibo[i-1]+fibo[i-2];
	    }
	    
	    for(int i=0;i<n;i++){
	        cout<<fibo[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}