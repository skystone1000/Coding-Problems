// Company Amazon
// AIE 10.10 K largest elements
// https://practice.geeksforgeeks.org/problems/k-largest-elements3736/1

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


vector<int> kLargest(int arr[], int n, int k){
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i=0;i<n;i++){
        minHeap.push(arr[i]);
        if(minHeap.size() > k)
            minHeap.pop();
    }
    
    vector<int> largest(k);
    for(int i=k-1;i>=0;i--){
        largest[i] = minHeap.top();
        minHeap.pop();
    }
    return largest;
}

// { Driver Code Starts.
vector<int> kLargest(int arr[], int n, int k);

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        for(int i = 0; i < n;i++)
            cin>>arr[i];
        
        vector<int> result = kLargest(arr, n, k);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout << endl;
        
    }
    return 0;
}
  // } Driver Code Ends