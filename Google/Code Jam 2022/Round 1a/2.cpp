//
// 

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<iterator> 
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<stack>
#define modulo 1000000007

#define ll long long
#define pb push_back
#define deb(x) cout<<#x<<" = "<<x<<endl
#define deb2(x,y) cout<<#x<<" = "<<x <<", "<<#y<<" = "<<y<<endl
#define all(x) x.begin(), x.end()

using namespace std;

void findAns(int curr, int sum, int currSum, vector<int> &arr, vector<int> &ans){
    if(curr >= arr.size()){
        return;
    }

    if(currSum = sum){
        return;
    }

    findAns(curr+1, sum, currSum, arr, ans);

    currSum += arr[curr];
    ans.push_back(arr[curr]);
    findAns(curr+1, sum, currSum, arr, ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        int n;
        cin>>n;
        vector<int> arr;
        int sum = 0;
        for(int i=1;i<=n;i++){
            cout<<i<<" ";
            arr.pb(i);
            sum += i;
        }
        for(int i=1;i<=n;i++){
            int temp;
            cin>>temp;
            arr.pb(temp);
            sum += temp;
        }

        int subsetSum = sum/2;

        vector<int> ans;
        findAns(0, subsetSum, 0, arr, ans);

        for(int i=0;i<ans.size();i++){
            cout<<ans[i] <<" ";
        }
        cout<<endl;
    }
    return 0;
}
