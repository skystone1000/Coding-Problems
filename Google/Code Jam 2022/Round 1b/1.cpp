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
        int n;
        cin>>n;
        vector<int> deli(n);
        for(int i=0;i<n;i++){
            cin>>deli[i];
        }

        deque<int> dqu(deli.begin(), deli.end());

        int paid = 0;
        int currDel = 0;
        while(!dqu.empty()){
            if(dqu.front() < dqu.back()){
                if(dqu.front() >= currDel){
                    paid++;
                    currDel = dqu.front();
                }
                dqu.pop_front();
            }else{
                if(dqu.back() >= currDel){
                    paid++;
                    currDel = dqu.back();
                }
                dqu.pop_back();
            }
        }
        cout<<"Case #"<<t+1<<": "<<paid<<endl;
    }
    return 0;
}
