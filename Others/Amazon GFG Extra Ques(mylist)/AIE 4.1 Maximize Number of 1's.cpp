// Company Amazon
// AIE 4.1 Maximize Number of 1's
// https://practice.geeksforgeeks.org/problems/maximize-number-of-1s0905/1

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends

class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int A[], int n, int K) {
        int i,j=0;
        for(i = 0; i < n; i++){
            if(A[i] == 0)
                K--;
            if(K<0){
                if(A[j] == 0)
                    K++;
                j++;
            }
        }
        
        return i-j;
    }  
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends