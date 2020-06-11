// Educational Codeforces Round 89 (Rated for Div. 2)
// A - Shovels and Swords 

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<iterator> 
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        long long a,b;
        cin>>a>>b;
        long long emb=0;

        // Method 1 (TLE)
        while (a>0 && b>0){
            if(a==1 && b==1){
                break;
            }
            if(a>2*b){
                emb = b;
                break;
            }
            if(b>2*a){
                emb = a;
                break;
            }

            if(a/10 > 100 && b/10 > 100){
                if(a>b){
                    int k = a/4;
                    b = b-k*1;
                    a = a-k*2;
                    emb = emb + k*1; 
                }else{
                    int k = b/4;
                    a = a-k*1;
                    b = b-k*2;
                    emb = emb + k*1; 
                }
            }    
            else{
                if(a>b){
                    b = b-1;
                    a = a-2;
                    emb++; 
                }else{
                    a = a-1;
                    b = b-2;
                    emb++; 
                }

            }
        }

        cout<<emb<<endl;

    }
    return 0;
}