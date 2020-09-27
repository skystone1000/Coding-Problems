// Amazon Interview Questions
// 02 Reverse a String   
// https://practice.geeksforgeeks.org/problems/reverse-the-string/0/?company[]=Amazon&difficulty[]=-2&page=1&query=company[]Amazondifficulty[]-2page1

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin>>T;
	for(int t = 0 ; t<T;t++){
	    string s;
	    cin>>s;
	    
	    // Method 1
	    // reverse(s.begin(),s.end());

        // Method 2
        int start = 0, end = s.size() - 1;
        while(start < end){
            char temp = s[end];
            s[end] = s[start];
            s[start] = temp;
            
            start++;end--;
        }
        
	    cout<<s<<endl;
	}
	return 0;
}