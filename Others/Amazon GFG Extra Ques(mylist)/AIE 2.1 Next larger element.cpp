// Company Amazon
// AIE 2.1 Next larger element
// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to store Next larger elements


vector <long long> nextLargerElement(long long arr[], int n){
    stack < long long > s; 
    
    /* push the first element to stack */
    s.push(0); 
    
    vector<long long> result(n);
    
    // iterate for rest of the elements 
    for (int i = 1; i < n; i++) { 
    
        if (s.empty()) { 
            s.push(i); 
            continue; 
        } 
        
        /* if stack is not empty, then 
        pop an element from stack. 
        If the popped element is smaller 
        than next, then 
        a) print the pair 
        b) keep popping while elements are 
        smaller and stack is not empty */
        while (s.empty() == false && arr[s.top()] < arr[i]) {          
            result[s.top()] = arr[i] ; 
            s.pop(); 
        } 
        
        /* push next to stack so that we can find 
        next greater for it */
        s.push(i); 
    } 
    
    /* After iterating over the loop, the remaining 
    elements in stack do not have the next greater 
    element, so print -1 for them */
    while (s.empty() == false) { 
        result[s.top()] = -1; 
        s.pop(); 
    }     
    
    return result;

}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        
        vector <long long> res = nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
  // } Driver Code Ends