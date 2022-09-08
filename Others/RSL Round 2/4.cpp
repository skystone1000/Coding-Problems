/*
A-4: ​Write a function that takes an array of integers as input and prints the second-maximum difference between any two elements from an array.
Example:int arr[]={14, 12, 70, 15, 95, 65, 22, 30};
First max-difference = 95-12=83 
Second max-difference = 95 -14 = 81 
So output should be 81
========================================
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int diff(vector<int> &arr) {
    vector<int> diffs;
    int n = arr.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int currDiff = arr[i] - arr[j];
            diffs.push_back(currDiff);
        }
    }
    std::sort(diffs.begin(),diffs.end(), greater<int>());
    return diffs[1];
}

int main(){
    vector<int> arr = {14, 12, 70, 15, 95, 65, 22, 30};    
    int ans = diff(arr);
    cout<<ans<<endl;
    return 0;
}
