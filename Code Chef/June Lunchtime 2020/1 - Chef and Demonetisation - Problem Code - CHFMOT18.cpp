// June Lunchtime 2020
// 1 - Chef and Demonetisation - Problem Code: CHFMOT18

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
    //cout.tie(NULL);
    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        ll s,n;
        cin>>s>>n;
        int coins=0;
        int done = 0;

        if( s== 1){
            cout<<"1"<<endl;
            continue;
        }

        while(s>0){
            if(s < n){
                // if(){
                //     coins += 1;
                //     done = 1;
                //     cout<<coins<<endl;
                //     break;
                // }else 
                if(s==1 || s%2 == 0){
                    coins += 1;
                    cout<<coins<<endl;
                    done = 1;
                    break;
                }else{
                    coins += 2;
                    done = 1;
                    cout<<coins<<endl;
                    break;
                }
            }
            if(s/n >= 1){
                coins += s/n;
                ll temp = s % n; 
                s = temp;
            }
        }

        if (done == 0){
            cout<<coins<<endl;
        } 

    }
    return 0;
}
