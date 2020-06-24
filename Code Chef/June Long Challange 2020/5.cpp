// Codechef June Long Challange 2020
// Contest Code:JUNE20B - Problem Code:EVENM
// 5 - Even Matrix

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<iterator> 
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        int n;
        cin>>n;
        int k = 1;
        for(int i=0;i<n;i++){
            if( i % 2 == 0 ){
                for(int j=0;j<n;j++){
                    cout<<k<<" ";
                    k++;
                }
            } else {
                k = k+n-1;
                for(int j=0;j<n;j++){
                    cout<<k<<" ";
                    k--;
                }
                k = k + n + 1;
            }
            cout<<endl;
        }


    }
    return 0;
}
