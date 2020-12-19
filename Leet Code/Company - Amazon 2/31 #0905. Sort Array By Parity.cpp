// Company Amazon
// 31 #0905. Sort Array By Parity
// https://leetcode.com/problems/sort-array-by-parity/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int index = 0;
        for (int i=0;i<A.size();i++){
            if(A[i] % 2 == 0){
                int temp = A[i];
                A[i] = A[index];
                A[index] = temp;
                
                index++;
            }
        }
        return A;
    }
};

/*
// LeetCode arrays 12
// #905 Sort Array By Parity 

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        vector<int> ans;
        ans.reserve(n);
        
        for(int i=0;i<n;i++){
            if(A[i] % 2 == 0){
                ans.push_back(A[i]);
            }
        }
        
        for(int i=0;i<n;i++){
            if(A[i] % 2 == 1){
                ans.push_back(A[i]);
            }
        }
        return ans;
    }
};
*/