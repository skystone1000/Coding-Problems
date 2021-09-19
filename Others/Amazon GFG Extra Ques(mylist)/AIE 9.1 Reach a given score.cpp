// Company Amazon
// AIE 9.1 Reach a given score 
// https://practice.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1

// Soln - https://www.geeksforgeeks.org/count-number-ways-reach-given-score-game/


#include<bits/stdc++.h>
#define ll long long int
using namespace std;


long long int count(long long int n)
{
	long long int table[n+1],i;
  
    // Initialize all table 
    // values as 0 
    for(int j = 0; j < n + 1; j++) 
        table[j] = 0; 
  
    // Base case (If given value is 0) 
    table[0] = 1; 
  
    // One by one consider given 3 moves  
    // and update the table[] values after 
    // the index greater than or equal to  
    // the value of the picked move 
    for (i = 3; i <= n; i++) 
        table[i] += table[i - 3]; 
      
    for (i = 5; i <= n; i++) 
        table[i] += table[i - 5]; 
      
    for (i = 10; i <= n; i++) 
        table[i] += table[i - 10]; 
  
    return table[n]; 
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}