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
        int r,c;
        cin>>r>>c;
        cout<<"Case #"<<t+1<<":"<<endl;
        for(int i=0;i<2*r+1;i++){
            for(int j=0;j<2*c+1;j++){
                if((i==0 && j==0) || (i==1 && j==0) || (i==0 && j==1)){
                    cout<<".";
                    continue;
                }
                
                if(i % 2 == 0){
                    if(j % 2 == 0){
                        cout<<"+";
                    }else{
                        cout<<"-";
                    }
                }else{
                    if(j % 2 == 0){
                        cout<<"|";
                    }else{
                        cout<<".";
                    }
                }
            }
            cout<<endl;
        }

    }
    return 0;
}
