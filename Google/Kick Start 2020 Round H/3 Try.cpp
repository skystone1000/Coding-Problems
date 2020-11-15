// Kick Start 2020 Round H
// 3. Rugby
// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff49/000000000043b027

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
        ll n;
        cin>>n;
        vector<ll> x(n);
        vector<ll> y(n);
        ll xSum=0,ySum=0;
        for(int i=0;i<n;i++){
            cin>>x[i]>>y[i];
            xSum += x[i];
            ySum += y[i];
        }
        pair<float,float> mean = {xSum/n,ySum/n};
        ll xRound = llround(mean.first);
        ll yRound = llround(mean.second);


        ll ySteps = 0;
        ll xSteps = 0;
        ll rc = 1;
        ll lc = 1;
        for(int i=0;i<n;i++){
            if(x[i] > xRound){
                xSteps += x[i] - xRound - rc; 
                rc++;
            }else{
                xSteps += xRound - x[i] - lc;
                lc++;
            }
            ySteps += llabs(yRound - y[i]); 
        }
        cout<<"Case #"<<t+1<<": "<<xSteps+ySteps<<endl;

    }
    return 0;
}
