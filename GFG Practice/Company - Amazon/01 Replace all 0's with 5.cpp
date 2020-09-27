// Amazon Interview Questions
// 01 Replace all 0's with 5  
// https://practice.geeksforgeeks.org/problems/replace-all-0-with-5-in-an-input-integer/1/?company[]=Amazon&difficulty[]=-2&page=1&query=company[]Amazondifficulty[]-2page1

#include<bits/stdc++.h>
using namespace std;

int convertFive(int n);
 
// Driver program to test above function
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n;
    	cin>>n;
    	cout<<convertFive(n)<<endl;
    }
}


/*you are required to complete this method*/
int convertFive(int n){
    int ans = 0;
    
    while(n>0){
        int dig = n % 10;
        if(dig == 0){
            ans = ans * 10 + 5;
        }else{
            ans = ans * 10 + dig;
        }
        n = n / 10;
    }
    
    int rans = 0;
    while(ans > 0){
        int dig = ans % 10;
        rans = rans * 10 + dig;
        ans = ans / 10;
    }
    
    return rans;
}