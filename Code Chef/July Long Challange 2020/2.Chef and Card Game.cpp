// July Long Challange 2020
// 2.Chef and Card Game - Problem Code: CRDGAME

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
        ll n;
        cin>>n;
        ll aTot = 0,bTot = 0;
        for(ll i=0;i<n;i++){
            ll a,b,ap,bp;
            cin>>a>>b;

            ll tempSum = 0;
            while(a>0){
                int temDi = a%10;
                tempSum = tempSum + temDi;
                a = a / 10;
            }
            ap = tempSum;
            tempSum = 0;

            while(b>0){
                int temDi = b%10;
                tempSum = tempSum + temDi;
                b = b / 10;
            }
            bp = tempSum;

            if(ap>bp)
                aTot++;
            else if(bp>ap)
                bTot++;
            else{
                aTot++;bTot++;
            }
        }
        if(aTot > bTot)
            cout<<"0 "<<aTot<<endl;
        else if(bTot > aTot)
            cout<<"1 "<<bTot<<endl;
        else 
            cout<<"2 "<<aTot<<endl;
    }
    return 0;
}
