int Solution::solve(vector<int> &A) {
    map<int,int, greater<int>> freq;
    
    int maxCount = 0;
    int ans = 0;
    for(int i=0;i<A.size();i++){
        freq[A[i]]++;
        ans += A[i];
    }
    
    for(auto ele:freq){
        int curr = ele.first * ele.second;
        if(maxCount < curr){
            maxCount = curr;
        }
    }
    ans = ans - maxCount;
    return ans;
}
