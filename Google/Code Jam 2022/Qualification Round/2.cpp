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
        int c1,m1,y1,k1;
        int c2,m2,y2,k2;
        int c3,m3,y3,k3;
        int cm,mm,ym,km;
        cin>>c1>>m1>>y1>>k1;
        cin>>c2>>m2>>y2>>k2;
        cin>>c3>>m3>>y3>>k3;

        int LOGO = 1000000;
        int sum = 0;
        cout<<"Case #"<<t+1<<": ";
        cm = min(min(c1,c2),c3);
        mm = min(min(m1,m2),m3);
        ym = min(min(y1,y2),y3);
        km = min(min(k1,k2),k3);
        if(cm+mm+ym+km < LOGO){
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }else{
            int rem = LOGO;
            if(cm > rem){
                cout<<rem<<" ";
                rem = 0;
            }else{
                cout<<cm<<" ";
                rem = rem - cm;
            }

            if(mm > rem){
                cout<<rem<<" ";
                rem = 0;
            }else{
                cout<<mm<<" ";
                rem = rem - mm;
            }

            if(ym > rem){
                cout<<rem<<" ";
                rem = 0;
            }else{
                cout<<ym<<" ";
                rem = rem - ym;
            }

            if(km > rem){
                cout<<rem<<endl;
                rem = 0;
            }else{
                cout<<km<<endl;
                rem = rem - km;
            }
        }

    }
    return 0;
}
