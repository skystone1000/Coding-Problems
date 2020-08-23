// Kick Start 2020 Round E
// 1.Longest Arithmetic

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<iterator> 
#include<algorithm>
#include<cmath>
#include<unordered_map>

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

    // Save output to a file
    // freopen ("myfile.txt","w",stdout);

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        int n;
        cin>>n;
        vector<ll> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        int maxSize = 0;
        // vector<vector<ll>> possible;
        for(int i=0;i<n;i++){
            vector<ll> temp;
            ll d = arr[i] - arr[i+1];
            // temp.pb(arr[i]);
            for(int j=i;j<n-1;j++){
                if(arr[j] - arr[j+1] == d){
                    temp.pb(arr[j]);
                    if(j == n-2){
                        temp.pb(arr[j+1]);
                        i = n;
                    }
                }else{
                    temp.pb(arr[j]);
                    i = j-1;
                    break;
                }
            }
            if(temp.size() > maxSize){
                maxSize = temp.size();
            }
            // possible.pb(temp);
        }

        /*
        for(auto &y:possible){
            for(auto &x:y){
                cout<<x<<" ";
            }
            cout<<endl;
        }*/
        
        // sort(possible.begin(), possible.end(), [](const vector<ll> & a, const vector<ll> & b){ return a.size() > b.size(); });
        /*
        cout<<":========================"<<endl;
        for(auto &y:possible){
            for(auto &x:y){
                cout<<x<<" ";
            }
            cout<<endl;
        }*/

        // cout<<"Case #"<<t+1<<": "<<possible[0].size()<<endl;
        cout<<"Case #"<<t+1<<": "<<maxSize<<endl;

    }

    // Save Output to file
    // fclose (stdout);
    return 0;
}
