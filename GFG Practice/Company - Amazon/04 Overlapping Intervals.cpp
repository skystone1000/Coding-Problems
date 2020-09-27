// Amazon Interview Questions
// 04 Overlapping Intervals
// Medium Accuracy: 42.98% Submissions: 21198 Points: 4 
// https://practice.geeksforgeeks.org/problems/overlapping-intervals/0

// Not passing Some corner cases check which are they

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int testcases;
	cin>>testcases;
	for(int t = 0;t<testcases;t++){
	    int N;
	    cin>>N;
	    vector<pair<int,int>> arr;
	
	    for(int i=0;i<N;i++){
	        int x,y;
	        cin>>x>>y;
	        arr.push_back({x,y});
	    }
	    
	    sort(arr.begin(),arr.end());
	    
	    vector<pair<int,int>> ans;
	    ans.push_back(arr[0]);
	    
	    int k = 0;
	    for(int i=0;i<arr.size();i++){
	        if(ans[k].second < arr[i].first){
	            ans.push_back(arr[i]);
	            k++;
	        }else if(ans[k].second < arr[i].second){
	            ans[k].second = arr[i].second;
	            k++;
	        }
	        
	    }
	    for(auto ele:ans){
	        cout<<ele.first<<" "<<ele.second<<" ";
	    }
	    cout<<endl;
	    
	}
	
	return 0;
}