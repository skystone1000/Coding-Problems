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
