// Codeforces Round #658 (Div. 2)
// A. Common Subsequence

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<iterator> 
#include<algorithm>
#include<cmath>

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
        int n,m;
        cin>>n>>m;
        vector<int> arrN(n);
        vector<int> arrM(m);

        for(int i=0;i<n;i++)
            cin>>arrN[i];

        for(int i=0;i<m;i++)
            cin>>arrM[i];
        
        int flag = 0;
        int ans;
        for(int i=0;i<n;i++){
            std::vector<int>::iterator it; 
            it = std::find (arrM.begin(), arrM.end(), arrN[i]); 
            if (it != arrM.end()) {
                flag = 1;
                ans = arrN[i];
                break;
            }
        }

        if(flag == 1){
            cout<<"YES"<<endl;
            cout<<"1 "<<ans<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        

    }
    return 0;
}
