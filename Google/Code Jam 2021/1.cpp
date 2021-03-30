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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        int N;cin>>N;
        vector<int> arr(N);
        for(int i=0;i<N;i++){
            cin>>arr[i];
        }
        
        int cost = 0;
        
        for(int i=0;i<N-1;i++){
            int smallest = arr[i],index = i;
            for(int j=i;j<N;j++){
                if(arr[j] < smallest){
                    smallest = arr[j];
                    index = j;
                }
            }
            // deb2(i,cost);
            // deb2(index,index-i+1);
            cost = cost + index - i + 1;
            reverse(arr.begin()+i,arr.begin()+index+1);
        }
        
        cout<<"Case #"<<t+1<<": "<<cost<<endl;
    }
    return 0;
}
