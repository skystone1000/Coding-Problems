// Kick Start 2020 Round H
// 2. Boring Numbers
// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff49/000000000043b0c6

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

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        ll l,r;
        cin>>l>>r;
        ll count = 0;
        for(ll i=l;i<=r;i++){
            ll curr = i;
            int loopCount = 0;
            while(curr>0){
                curr = curr / 10;
                loopCount++;
            }

            curr = i;
            int flag = 1;
            while(curr>0){
                int dig = curr % 10;
                if(loopCount % 2 == 1){
                    if(dig % 2 == 0){
                        flag = 0;
                        break;
                    }
                }else{
                    if(dig % 2 == 1){
                        flag = 0;
                        break;
                    }
                }
                loopCount++;
                curr = curr / 10;
            }
            if(flag == 1){
                // cout<<i<<" ";
                count++;
            }
        }
        cout<<"Case #"<<t+1<<": "<<count<<endl;

    }
    return 0;
}
