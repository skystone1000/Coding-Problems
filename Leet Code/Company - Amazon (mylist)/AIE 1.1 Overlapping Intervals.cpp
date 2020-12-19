// Company Amazon
// AIE 1.1 Overlapping Intervals
// https://practice.geeksforgeeks.org/problems/overlapping-intervals4919/1

// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> overlappedInterval(vector<pair<int,int>> , int );

// User code will be pasted here

int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        vector<pair<int,int> > arr,res;
        int n,x,y;
        cin>>n;

        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            arr.push_back(make_pair(x,y));
        }
        
        res = overlappedInterval(arr,n);
        
        
        for(int i=0;i<res.size();i++)
            cout << res[i].first << " " << res[i].second << " " ;
            
        cout<<endl;
    }
}
// } Driver Code Ends


//User function template for C++

vector<pair<int,int>> overlappedInterval(vector<pair<int,int>> vec, int n) {
    vector<pair<int,int>> ans;
    if(n<=0)
        return ans;
    
    sort(vec.begin(),vec.end());
    stack<pair<int,int>> s;
    s.push(vec[0]);
    for(auto ele:vec){
        pair<int,int> top = s.top();
        if(top.second < ele.first){
            s.push(ele);
        } else if(top.second < ele.second){
            top.second = ele.second;
            s.pop();
            s.push(top);
        }
    }
    
    
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}