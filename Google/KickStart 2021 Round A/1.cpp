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
        ll N,K;
        string S;
        cin>>N>>K;
        cin>>S;
        
        int score=0;
        for(int i=0;i<N/2;i++){
            if(S[i] != S[N-i-1]){
                score++;
            }
        }
        
        if(N==1 || K-score < 0){
            cout<<"Case #"<<t+1<<": "<<0<<endl;
        } else{
            cout<<"Case #"<<t+1<<": ";
            cout<<K-score<<endl;            
        }

    }
    return 0;
}
