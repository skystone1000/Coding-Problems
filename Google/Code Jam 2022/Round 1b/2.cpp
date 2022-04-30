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
        int n,p;cin>>n>>p;
        vector<vector<int>> pressure;
        vector<int> avgPressure;
        for(int i=0;i<n;i++){
            vector<int> temp(p);
            int sum = 0;
            for(int j=0;j<p;j++){
                cin>>temp[j];
                sum += temp[j];
            }
            sort(temp.begin(),temp.end());
            pressure.pb(temp);
            avgPressure.pb(sum/p);
        }

        int buttonPress = 0;
        int prevEnd = 0;
        for(int i=0;i<n;i++){
            if(prevEnd < avgPressure[i]){
                buttonPress += llabs(prevEnd - pressure[i][0]);
                buttonPress += pressure[i][p-1] - pressure[i][0];
                prevEnd = pressure[i][p];
            }else{
                buttonPress += llabs(prevEnd - pressure[i][p-1]);
                buttonPress += pressure[i][p-1] - pressure[i][0];
                prevEnd = pressure[i][0];
            }
        }
        cout<<"Case #"<<t+1<<": "<<buttonPress<<endl;
    }
    return 0;
}
