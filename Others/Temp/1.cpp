#include<iostream>
#include <climits>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    int ans[m];

    for(int i=0;i<m;i++){
        ans[i] = INT_MAX;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(ans[j] > arr[i][j]){
                ans[j] = arr[i][j];
            }
        }
    }

    for(int i=0;i<m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}