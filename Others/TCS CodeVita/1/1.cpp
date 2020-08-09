// 
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

    

    int n;
    cin>>n;

    vector<vector<char>> cons;
    for(int i=0;i<3;i++){
        vector<char> inpVec(n);
        for(int j=0;j<n;j++){
            // char inpChar;
            // cin>>inpChar
            cin>>inpVec[j];
        }
        cons.pb(inpVec);
    }

    // cout<<"----------------"<<endl;

    /*
    for(auto &r:cons){
        for(auto &c:r){
            cout<<c<<" ";
        }
        cout<<endl;
    }*/

    // cout<<"----------------"<<endl;

    for(int i=0;i<n-2;i++){
        // cout<<i;
        if (cons[0][i]=='#'){
            cout<<"#";
            continue;
        }

        
        if (cons[0][i]=='.' ){
            if (cons[1][i]=='.' ){
                if (cons[2][i]=='.' ){
                    continue;
                }
            }
        }

        if (cons[0][i]=='.' && cons[0][i+1]=='*' && cons[0][i+2]=='.'){
            if (cons[1][i]=='*' && cons[1][i+1]=='*' && cons[1][i+2]=='*'){
                if (cons[2][i]=='*' && cons[2][i+1]=='.' && cons[2][i+2]=='*'){
                    cout<<'A';
                    i=i+2;
                    continue;
                }
            }
        }

        if (cons[0][i]=='*' && cons[0][i+1]=='*' && cons[0][i+2]=='*'){
            if (cons[1][i]=='*' && cons[1][i+1]=='*' && cons[1][i+2]=='*'){
                if (cons[2][i]=='*' && cons[2][i+1]=='*' && cons[2][i+2]=='*'){
                    cout<<'E';
                    i=i+2;
                    continue;
                }
            }
        }

        if (cons[0][i]=='*' && cons[0][i+1]=='*' && cons[0][i+2]=='*'){
            if (cons[1][i]=='.' && cons[1][i+1]=='*' && cons[1][i+2]=='.'){
                if (cons[2][i]=='*' && cons[2][i+1]=='*' && cons[2][i+2]=='*'){
                    cout<<'I';
                    i=i+2;
                    continue;
                }
            }
        }

        if (cons[0][i]=='*' && cons[0][i+1]=='*' && cons[0][i+2]=='*'){
            if (cons[1][i]=='*' && cons[1][i+1]=='.' && cons[1][i+2]=='*'){
                if (cons[2][i]=='*' && cons[2][i+1]=='*' && cons[2][i+2]=='*'){
                    cout<<'O';
                    i=i+2;
                    continue;
                }
            }
        }
                    
        if (cons[0][i]=='*' && cons[0][i+1]=='.' && cons[0][i+2]=='*'){
            if (cons[1][i]=='*' && cons[1][i+1]=='.' && cons[1][i+2]=='*'){
                if (cons[2][i]=='*' && cons[2][i+1]=='*' && cons[2][i+2]=='*'){
                    cout<<'U';
                    i=i+2;
                    continue;
                }
            }
        }


    }

    
    return 0;
}
