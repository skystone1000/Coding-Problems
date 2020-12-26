// Company Amazon
// AIE 2.4 Minimum Cost of ropes 
// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Position this line where user code will be pasted.
long long minCost(long long arr[], long long n);
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << minCost(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


long long minCost(long long arr[], long long n) {
    long long cost = 0;
    priority_queue<long long, std::vector<long long> ,std::greater<long long>> minHeap;
    
    for(int i=0;i<n;i++){
        minHeap.push(arr[i]);
    }
    
    while(minHeap.size() > 1){
        long long sum = 0;
        sum += minHeap.top();
        minHeap.pop();
        sum += minHeap.top();
        minHeap.pop();
        
        minHeap.push(sum);
        cost += sum;
        // cout<<"Sum = "<<sum<<" Cost = "<<cost<<endl;
    }
    
    return cost;
}
