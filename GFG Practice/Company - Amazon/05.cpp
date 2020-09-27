// Amazon Interview Questions
// 05 Josephus problem
// Easy Accuracy: 52.47% Submissions: 29151 Points: 2  
// https://practice.geeksforgeeks.org/problems/josephus-problem/1

#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k);

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		cout<<josephus(n,k)<<endl;
	}
	return 0;
}

/*You are required to complete this method */
int josephus(int n, int k)
{
    if (n == 1) 
        return 1; 
    else
        /* The position returned by josephus(n - 1, k) 
        is adjusted because the recursive call  
        josephus(n - 1, k) considers the  
        original position k % n + 1 as position 1 */
        return (josephus(n - 1, k) + k-1) % n + 1; 
}

/* -- NOT WORKING --
int josephus(int n, int k)
{
        vector<int> arr;
        for(int i=0;i<n;i++){
          arr.push_back(i);
        }
        
        int i = 0;
        while(arr.size() > 1){
          i = (i + k-1) % n-1;
          arr.erase(arr.begin() + i);
        }
        // cout<<arr[0];
        return arr[0] + 1;
}
*/