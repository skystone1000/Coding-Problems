// 06 Cost of Ballons
#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        int gc,rc;
        int green=0, red=0;
        cin>>gc>>rc;
        int n;
        cin>>n;
        int par[n][2];
        for(int i=0;i<n;i++){
            cin>>par[i][0]>>par[i][1];
            if(par[i][0] == 1){
                green++;
            }
            if(par[i][1] == 1){
                red++;
            }
        }
        int cost1 = rc*green+gc*red;
        int cost2 = gc*green+rc*red;
        if(cost1>cost2){
            cout<<cost2<<endl;
        }else
            cout<<cost1<<endl;

    }
    return 0;
}